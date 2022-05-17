#!/usr/bin/env python3

#
# This file is part of LiteSDCard.
#
# Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import os
import argparse

from migen import *

from litex.build.generic_platform import *

from litex_boards.platforms import digilent_arty
from litex_boards.targets.digilent_arty import BaseSoC

from litex.soc.interconnect import stream
from litex.soc.integration.builder import *

from sampler import Sampler

# BenchSoC -----------------------------------------------------------------------------------------

class BenchSoC(BaseSoC):
    def __init__(self, variant="minimal", with_sampler=False, with_analyzer=False, host_ip="192.168.1.100", host_udp_port=2000):
        platform = digilent_arty.Platform()

        # BenchSoC ---------------------------------------------------------------------------------
        bench_kwargs = {
            "minimal":  dict(cpu_variant="minimal", integrated_main_ram_size=0x1000),
            "standard": dict(),
        }[variant]
        BaseSoC.__init__(self, sys_clk_freq=int(100e6),
            integrated_rom_size=0x10000,
            integrated_rom_mode = "rw",
            **bench_kwargs)

        # SDCard on PMODD with Digilent's Pmod MicroSD ---------------------------------------------
        self.platform.add_extension(digilent_arty._sdcard_pmod_io)
        self.add_sdcard("sdcard")

        if with_sampler or with_analyzer:
            # Etherbone ----------------------------------------------------------------------------
            from liteeth.phy.mii import LiteEthPHYMII
            self.submodules.ethphy = LiteEthPHYMII(
                clock_pads         = self.platform.request("eth_clocks"),
                pads               = self.platform.request("eth"))
            self.add_csr("ethphy")
            self.add_etherbone(phy=self.ethphy)

        if with_sampler:
            # PMODB Sampler (connected to PmodTPH2 with Pmode Cable Kit) ---------------------------
            _la_pmod_ios = [
                ("la_pmod", 0, Pins(
                    "pmoda:0 pmoda:1 pmoda:2 pmoda:3",
                    "pmoda:4 pmoda:5 pmoda:6 pmoda:7"),
                     IOStandard("LVCMOS33")
                )
            ]
            self.platform.add_extension(_la_pmod_ios)
            self.submodules.sampler = Sampler(self.platform.request("la_pmod"))
            self.add_csr("sampler")

            # DRAMFIFO -----------------------------------------------------------------------------
            from litedram.frontend.fifo import LiteDRAMFIFO
            self.submodules.fifo = LiteDRAMFIFO(
                data_width = 8,
                base       = 0x00000000,
                depth      = 0x01000000, # 16MB
                write_port = self.sdram.crossbar.get_port(mode="write", data_width=8),
                read_port  = self.sdram.crossbar.get_port(mode="read",  data_width=8),
            )

            # UDPStreamer --------------------------------------------------------------------------
            from liteeth.common import convert_ip
            from liteeth.frontend.stream import LiteEthStream2UDPTX
            udp_port       = self.ethcore.udp.crossbar.get_port(host_udp_port, dw=8)
            udp_streamer   = LiteEthStream2UDPTX(
                ip_address = convert_ip(host_ip),
                udp_port   = host_udp_port,
                fifo_depth = 1024
            )
            udp_streamer   = ClockDomainsRenamer("eth_tx")(udp_streamer)
            self.submodules += udp_streamer
            udp_cdc = stream.ClockDomainCrossing([("data", 8)], "sys", "eth_tx")
            self.submodules += udp_cdc

            # Sampler/FIFO/UDPStreamer flow -------------------------------------------------------------
            self.comb += self.sampler.source.connect(self.fifo.sink)
            self.comb += self.fifo.source.connect(udp_cdc.sink)
            self.comb += udp_cdc.source.connect(udp_streamer.sink)
            self.comb += udp_streamer.source.connect(udp_port.sink)

        if with_analyzer:
            from litescope import LiteScopeAnalyzer
            analyzer_signals = [
                self.sdphy.sdpads,
                self.sdphy.cmdw.sink,
                self.sdphy.cmdr.sink,
                self.sdphy.cmdr.source,
                self.sdphy.dataw.sink,
                self.sdphy.dataw.stop,
                self.sdphy.dataw.crc.source,
                self.sdphy.dataw.status.status,
                self.sdphy.datar.sink,
                self.sdphy.datar.source,
                self.sdphy.clocker.ce,
                self.sdphy.clocker.stop,
            ]
            self.submodules.analyzer = LiteScopeAnalyzer(analyzer_signals,
                depth        = 2048,
                clock_domain = "sys",
                csr_csv      = "analyzer.csv")
            self.add_csr("analyzer")

# BenchPHY -----------------------------------------------------------------------------------------

class BenchPHY(BaseSoC):
    def __init__(self, **kwargs):
        platform = digilent_arty.Platform()

        # BenchPHY ---------------------------------------------------------------------------------
        BaseSoC.__init__(self, sys_clk_freq=int(100e6), cpu_type=None, integrated_main_ram_size=0x100)

        # SDCard on PMODD with Digilent's Pmod MicroSD ---------------------------------------------
        self.platform.add_extension(digilent_arty._sdcard_pmod_io)
        from litesdcard.phy import SDPHY
        self.submodules.sd_phy = SDPHY(self.platform.request("sdcard"), platform.device, self.clk_freq)
        self.add_csr("sd_phy")

        # Send a command with button to verify timings ---------------------------------------------
        self.comb += [
            If(self.platform.request("user_btn", 0),
                self.sd_phy.cmdw.sink.valid.eq(1),
                self.sd_phy.cmdw.sink.data.eq(0x5a),
            )
        ]

# SoC Ctrl -----------------------------------------------------------------------------------------

class SoCCtrl:
    @staticmethod
    def reboot(wb):
        wb.regs.ctrl_reset.write(1)

    @staticmethod
    def load_rom(wb, filename):
        from litex.soc.integration.common import get_mem_data
        rom_data = get_mem_data(filename, "little")
        for i, data in enumerate(rom_data):
            wb.write(wb.mems.rom.base + 4*i, data)

# Build --------------------------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description="LiteSDCard Bench on Arty")
    parser.add_argument("--bench",         default="soc",       help="Bench: soc (default) or phy.")
    parser.add_argument("--variant",       default="standard",  help="Bench variant standard (default) or minimal.")
    parser.add_argument("--with-sampler",  action="store_true", help="Add Sampler to Bench.")
    parser.add_argument("--with-analyzer", action="store_true", help="Add Analyzer to Bench.")
    parser.add_argument("--build",         action="store_true", help="Build bitstream.")
    parser.add_argument("--load",          action="store_true", help="Load bitstream.")
    parser.add_argument("--load-bios",     action="store_true", help="Load BIOS over Etherbone and reboot SoC.")
    args = parser.parse_args()

    bench     = {"soc": BenchSoC, "phy": BenchPHY}[args.bench](
        variant       = args.variant,
        with_sampler  = args.with_sampler,
        with_analyzer = args.with_analyzer,
    )
    builder   = Builder(bench, csr_csv="csr.csv")
    builder.build(run=args.build)

    if args.load:
        prog = bench.platform.create_programmer()
        prog.load_bitstream(os.path.join(builder.gateware_dir, bench.build_name + ".bit"))

    if args.load_bios:
        from litex import RemoteClient
        wb = RemoteClient()
        wb.open()
        ctrl = SoCCtrl()
        ctrl.load_rom(wb, os.path.join(builder.software_dir, "bios", "bios.bin"))
        ctrl.reboot(wb)
        wb.close()

if __name__ == "__main__":
    main()
