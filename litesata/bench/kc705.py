#!/usr/bin/env python3

#
# This file is part of LiteSATA.
#
# Copyright (c) 2015-2020 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import sys
import argparse

from migen import *

from litex_boards.platforms import xilinx_kc705

from litex.build.generic_platform import *

from litex.soc.cores.clock import S7MMCM
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.interconnect import wishbone

from litesata.common import *
from litesata.phy import LiteSATAPHY
from litesata.core import LiteSATACore
from litesata.frontend.arbitration import LiteSATACrossbar
from litesata.frontend.bist import LiteSATABIST
from litesata.frontend.dma import LiteSATASector2MemDMA, LiteSATAMem2SectorDMA

from litescope import LiteScopeAnalyzer

# IOs ----------------------------------------------------------------------------------------------

_sata_io = [
    # AB09-FMCRAID / https://www.dgway.com/AB09-FMCRAID_E.html
    ("fmc2sata", 0,
        Subsignal("clk_p", Pins("HPC:GBTCLK0_M2C_P")),
        Subsignal("clk_n", Pins("HPC:GBTCLK0_M2C_N")),
        Subsignal("tx_p",  Pins("HPC:DP0_C2M_P")),
        Subsignal("tx_n",  Pins("HPC:DP0_C2M_N")),
        Subsignal("rx_p",  Pins("HPC:DP0_M2C_P")),
        Subsignal("rx_n",  Pins("HPC:DP0_M2C_N"))
    ),
    # SFP 2 SATA Adapter / https://shop.trenz-electronic.de/en/TE0424-01-SFP-2-SATA-Adapter
    ("sfp2sata", 0,
        Subsignal("tx_p", Pins("H2")),
        Subsignal("tx_n", Pins("H1")),
        Subsignal("rx_p", Pins("G4")),
        Subsignal("rx_n", Pins("G3")),
    ),
    # PCIe 2 SATA Custom Adapter (With PCIe Riser / SATA cable mod).
    ("pcie2sata", 0,
        Subsignal("tx_p", Pins("L4")),
        Subsignal("tx_n", Pins("L3")),
        Subsignal("rx_p", Pins("M6")),
        Subsignal("rx_n", Pins("M5")),
    ),
]

# CRG ----------------------------------------------------------------------------------------------

class _CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys    = ClockDomain()
        self.clock_domains.cd_sys4x  = ClockDomain(reset_less=True)
        self.clock_domains.cd_idelay = ClockDomain()

        # # #

        self.submodules.pll = pll = S7MMCM(speedgrade=-2)
        self.comb += pll.reset.eq(platform.request("cpu_reset"))
        pll.register_clkin(platform.request("clk200"), 200e6)
        pll.create_clkout(self.cd_sys,    sys_clk_freq)

# SATATestSoC --------------------------------------------------------------------------------------

class SATATestSoC(SoCMini):
    def __init__(self, platform, connector="fmc", gen="gen3",
        with_global_analyzer     = False,
        with_sector2mem_analyzer = False,
        with_mem2sector_analyzer = False):
        assert connector in ["fmc", "sfp", "pcie"]
        assert gen in ["gen1", "gen2", "gen3"]
        sys_clk_freq  = int(200e6)
        sata_clk_freq = {"gen1": 75e6, "gen2": 150e6, "gen3": 300e6}[gen]

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = _CRG(platform, sys_clk_freq)

        # SoCMini ----------------------------------------------------------------------------------
        SoCMini.__init__(self, platform, sys_clk_freq, ident="LiteSATA bench on KC705")

        # UARTBone ---------------------------------------------------------------------------------
        self.add_uartbone()

        # SATA -------------------------------------------------------------------------------------
        # RefClk
        sata_refclk = None
        if connector != "fmc":
            # Generate 150MHz from PLL.
            self.clock_domains.cd_sata_refclk = ClockDomain()
            self.crg.pll.create_clkout(self.cd_sata_refclk, 150e6)
            sata_refclk = ClockSignal("sata_refclk")
            platform.add_platform_command("set_property SEVERITY {{Warning}} [get_drc_checks REQP-52]")

        # PHY
        self.submodules.sata_phy = LiteSATAPHY(platform.device,
            refclk     = sata_refclk,
            pads       = platform.request(connector+"2sata"),
            gen        = gen,
            clk_freq   = sys_clk_freq,
            data_width = 16)

        # Core
        self.submodules.sata_core = LiteSATACore(self.sata_phy)

        # Crossbar
        self.submodules.sata_crossbar = LiteSATACrossbar(self.sata_core)

        # BIST
        self.submodules.sata_bist = LiteSATABIST(self.sata_crossbar, with_csr=True)

        # Sector2Mem DMA
        bus =  wishbone.Interface(data_width=32, adr_width=32)
        self.submodules.sata_sector2mem = LiteSATASector2MemDMA(self.sata_crossbar.get_port(), bus)
        self.bus.add_master("sata_sector2mem", master=bus)

        # Mem2Sector DMA
        bus =  wishbone.Interface(data_width=32, adr_width=32)
        self.submodules.sata_mem2sector = LiteSATAMem2SectorDMA(bus, self.sata_crossbar.get_port())
        self.bus.add_master("sata_mem2sector", master=bus)

        # Timing constraints
        platform.add_period_constraint(self.sata_phy.crg.cd_sata_tx.clk, 1e9/sata_clk_freq)
        platform.add_period_constraint(self.sata_phy.crg.cd_sata_rx.clk, 1e9/sata_clk_freq)
        self.platform.add_false_path_constraints(
            self.crg.cd_sys.clk,
            self.sata_phy.crg.cd_sata_tx.clk,
            self.sata_phy.crg.cd_sata_rx.clk)

        # Leds -------------------------------------------------------------------------------------
        # sys_clk
        sys_counter = Signal(32)
        self.sync.sys += sys_counter.eq(sys_counter + 1)
        self.comb += platform.request("user_led", 0).eq(sys_counter[26])
        # tx_clk
        tx_counter = Signal(32)
        self.sync.sata_tx += tx_counter.eq(tx_counter + 1)
        self.comb += platform.request("user_led", 1).eq(tx_counter[26])
        # rx_clk
        rx_counter = Signal(32)
        self.sync.sata_rx += rx_counter.eq(rx_counter + 1)
        self.comb += platform.request("user_led", 2).eq(rx_counter[26])
        # ready
        self.comb += platform.request("user_led", 3).eq(self.sata_phy.ctrl.ready)

        # Analyzers ---------------------------------------------------------------------------------
        if with_global_analyzer:
            analyzer_signals = [
                self.sata_phy.phy.tx_init.fsm,
                self.sata_phy.phy.rx_init.fsm,
                self.sata_phy.ctrl.fsm,

                self.sata_phy.ctrl.ready,
                self.sata_phy.source,
                self.sata_phy.sink,

                self.sata_core.command.sink,
                self.sata_core.command.source,

                self.sata_core.link.rx.fsm,
                self.sata_core.link.tx.fsm,
                self.sata_core.transport.rx.fsm,
                self.sata_core.transport.tx.fsm,
                self.sata_core.command.rx.fsm,
                self.sata_core.command.tx.fsm,
            ]
            self.submodules.global_analyzer = LiteScopeAnalyzer(analyzer_signals, 512, csr_csv="global_analyzer.csv")

        if with_sector2mem_analyzer:
            analyzer_signals = [
                self.sata_sector2mem.start.re,
                self.sata_sector2mem.fsm,
                self.sata_sector2mem.port.sink,
                self.sata_sector2mem.port.source,
                self.sata_sector2mem.bus,
            ]
            self.submodules.sector2mem_analyzer = LiteScopeAnalyzer(analyzer_signals, 2048, csr_csv="sector2mem_analyzer.csv")

        if with_mem2sector_analyzer:
            analyzer_signals = [
                self.sata_mem2sector.start.re,
                self.sata_mem2sector.fsm,
                self.sata_mem2sector.port.sink,
                self.sata_mem2sector.port.source,
                self.sata_mem2sector.bus,
            ]
            self.submodules.mem2sector_analyzer = LiteScopeAnalyzer(analyzer_signals, 2048, csr_csv="mem2sector_analyzer.csv")

# Build --------------------------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description="LiteSATA bench on KC705")
    parser.add_argument("--build",                    action="store_true", help="Build bitstream")
    parser.add_argument("--load",                     action="store_true", help="Load bitstream (to SRAM)")
    parser.add_argument("--gen",                      default="3",         help="SATA Gen: 1, 2 or 3 (default)")
    parser.add_argument("--connector",                default="fmc",       help="SATA Connector: fmc (default) , sfp or pcie")
    parser.add_argument("--with-global-analyzer",     action="store_true", help="Add Global LiteScope Analyzer")
    parser.add_argument("--with-sector2mem-analyzer", action="store_true", help="Add Sector2Mem LiteScope Analyzer")
    parser.add_argument("--with-mem2sector-analyzer", action="store_true", help="Add Mem2Sector LiteScope Analyzer")
    args = parser.parse_args()

    platform = xilinx_kc705.Platform()
    platform.add_extension(_sata_io)
    soc = SATATestSoC(platform, args.connector, "gen" + args.gen,
        with_global_analyzer     = args.with_global_analyzer,
        with_sector2mem_analyzer = args.with_sector2mem_analyzer,
        with_mem2sector_analyzer = args.with_mem2sector_analyzer,
    )
    builder = Builder(soc, csr_csv="csr.csv")
    builder.build(run=args.build)

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(os.path.join(builder.gateware_dir, soc.build_name + ".bit"))

if __name__ == "__main__":
    main()
