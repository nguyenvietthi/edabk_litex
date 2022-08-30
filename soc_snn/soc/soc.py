#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2014-2015 Sebastien Bourdeauducq <sb@m-labs.hk>
# Copyright (c) 2014-2020 Florent Kermarrec <florent@enjoy-digital.fr>
# Copyright (c) 2014-2015 Yann Sionneau <ys@m-labs.hk>
# SPDX-License-Identifier: BSD-2-Clause

import os
from typing import Tuple

from migen import *

from litex_boards.platforms import xilinx_kc705

from litex.soc.cores.clock import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser

from litedram.modules import MT8JTF12864
from litedram.phy import s7ddrphy

from liteeth.phy import LiteEthPHY

from litepcie.phy.s7pciephy import S7PCIEPHY
from litepcie.software import generate_litepcie_software
from litex.soc.interconnect import wishbone

from edabk_snn import edabk_snn
# CRG ----------------------------------------------------------------------------------------------

class _CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.rst = Signal()
        self.clock_domains.cd_sys    = ClockDomain()
        self.clock_domains.cd_sys4x  = ClockDomain()
        self.clock_domains.cd_idelay = ClockDomain()

        # # #

        self.submodules.pll = pll = S7MMCM(speedgrade=-2)
        self.comb += pll.reset.eq(platform.request("cpu_reset") | self.rst)
        pll.register_clkin(platform.request("clk200"), 200e6)
        pll.create_clkout(self.cd_sys,    sys_clk_freq)
        pll.create_clkout(self.cd_sys4x,  4*sys_clk_freq)
        pll.create_clkout(self.cd_idelay, 200e6)
        platform.add_false_path_constraints(self.cd_sys.clk, pll.clkin) # Ignore sys_clk to pll.clkin path created by SoC's rst.

        self.submodules.idelayctrl = S7IDELAYCTRL(self.cd_idelay)

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(125e6), with_ethernet=False, with_led_chaser=True,
                 with_spi_flash=False, with_pcie=False, with_sata=False, with_sdcard =True, **kwargs):
        platform = xilinx_kc705.Platform()

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = _CRG(platform, sys_clk_freq)

        # SoCCore ----------------------------------------------------------------------------------
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on KC705", **kwargs)

        # SDCard -----------------------------------------------------------------------------------
        # Simply integrate SDCard through LiteX's add_sdcard method.
        if with_sdcard:
            # Wishbone Control -------------------------------------------------------------------------
            # Create Wishbone Control Slave interface, expose it and connect it to the SoC.
            wb_ctrl = wishbone.Interface()
            self.add_wb_master(wb_ctrl)
            platform.add_extension(wb_ctrl.get_ios("wb_ctrl"))
            self.comb += wb_ctrl.connect_to_pads(self.platform.request("wb_ctrl"), mode="slave")
            # Wishbone DMA -----------------------------------------------------------------------------
            # Create Wishbone DMA Master interface and expose it.
            wb_dma = wishbone.Interface(data_width=32)
            platform.add_extension(wb_ctrl.get_ios("wb_dma"))
            self.comb += wb_dma.connect_to_pads(self.platform.request("wb_dma"), mode="master")

            # Create DMA Bus Handler (DMAs will be added by add_sdcard to it) and connect it to Wishbone DMA.
            self.submodules.dma_bus = SoCBusHandler(
                name             = "SoCDMABusHandler",
                standard         = "wishbone",
                data_width       = 32,
                address_width    = 32,
            )
            self.dma_bus.add_slave("dma", slave=wb_dma, region=SoCRegion(origin=0x00000000, size=0x100000000))

        # SDCard -----------------------------------------------------------------------------------
        # Simply integrate SDCard through LiteX's add_sdcard method.
        self.add_sdcard(name="sdcard")

        # IRQ
        irq_pad = platform.request("irq")
        self.comb += irq_pad.eq(self.sdirq.irq)

        # EDABK SNN---------------------------------------------------------------------------------
        # SNN clk, Generate 100MHz from PLL.
        self.clock_domains.cd_snn_clk = ClockDomain()
        self.crg.pll.create_clkout(self.cd_snn_clk, 100e6)
        snn_clk = ClockSignal("snn_clk")
        # platform.add_platform_command("set_property SEVERITY {{Warning}} [get_drc_checks REQP-52]")

        self.submodules.edabk_snn_module = edabk_snn(self.platform)
        self.add_csr("edabk_snn")
        self.comb += self.edabk_snn_module.clk.eq(snn_clk)
        self.comb += self.edabk_snn_module.sys_clk.eq(ClockSignal())

        # DDR3 SDRAM -------------------------------------------------------------------------------
        if not self.integrated_main_ram_size:
            self.submodules.ddrphy = s7ddrphy.K7DDRPHY(platform.request("ddram"),
                memtype      = "DDR3",
                nphases      = 4,
                sys_clk_freq = sys_clk_freq)
            self.add_sdram("sdram",
                phy           = self.ddrphy,
                module        = MT8JTF12864(sys_clk_freq, "1:4"),
                l2_cache_size = kwargs.get("l2_size", 8192)
            )

        # Ethernet ---------------------------------------------------------------------------------
        if with_ethernet:
            self.submodules.ethphy = LiteEthPHY(
                clock_pads = self.platform.request("eth_clocks"),
                pads       = self.platform.request("eth"),
                clk_freq   = self.clk_freq)
            self.add_ethernet(phy=self.ethphy)

        # SPI Flash --------------------------------------------------------------------------------
        if with_spi_flash:
            from litespi.modules import N25Q128A13
            from litespi.opcodes import SpiNorFlashOpCodes as Codes
            self.add_spi_flash(mode="4x", module=N25Q128A13(Codes.READ_1_1_4), rate="1:1", with_master=True)

        # PCIe -------------------------------------------------------------------------------------
        if with_pcie:
            self.submodules.pcie_phy = S7PCIEPHY(platform, platform.request("pcie_x4"),
                data_width = 128,
                bar0_size  = 0x20000)
            self.add_pcie(phy=self.pcie_phy, ndmas=1)

        # SATA -------------------------------------------------------------------------------------
        if with_sata:
            from litex.build.generic_platform import Subsignal, Pins
            from litesata.phy import LiteSATAPHY

            # IOs
            _sata_io = [
                # SFP 2 SATA Adapter / https://shop.trenz-electronic.de/en/TE0424-01-SFP-2-SATA-Adapter
                ("sfp2sata", 0,
                    Subsignal("tx_p", Pins("H2")),
                    Subsignal("tx_n", Pins("H1")),
                    Subsignal("rx_p", Pins("G4")),
                    Subsignal("rx_n", Pins("G3")),
                ),
            ]
            platform.add_extension(_sata_io)

            # RefClk, Generate 150MHz from PLL.
            self.clock_domains.cd_sata_refclk = ClockDomain()
            self.crg.pll.create_clkout(self.cd_sata_refclk, 150e6)
            sata_refclk = ClockSignal("sata_refclk")
            platform.add_platform_command("set_property SEVERITY {{Warning}} [get_drc_checks REQP-52]")

            # PHY
            self.submodules.sata_phy = LiteSATAPHY(platform.device,
                refclk     = sata_refclk,
                pads       = platform.request("sfp2sata"),
                gen        = "gen2",
                clk_freq   = sys_clk_freq,
                data_width = 16)

            # Core
            self.add_sata(phy=self.sata_phy, mode="read+write")

        # Leds -------------------------------------------------------------------------------------
        if with_led_chaser:
            self.submodules.leds = LedChaser(
                pads         = platform.request_all("user_led"),
                sys_clk_freq = sys_clk_freq)

        # Documentation generation -----------------------------------------------------------------
        def generate_doc(self, board_name):
            from litex.soc.doc import generate_docs
            doc_dir = os.path.join("build", board_name, "doc")
            generate_docs(self, doc_dir)
            os.system("sphinx-build -M html {}/ {}/_build".format(doc_dir, doc_dir))

# Build --------------------------------------------------------------------------------------------

def main():
    from litex.soc.integration.soc import LiteXSoCArgumentParser
    parser = LiteXSoCArgumentParser(description="LiteX SoC on KC705")
    target_group = parser.add_argument_group(title="Target options")
    target_group.add_argument("--build",          action="store_true", help="Build design.")
    target_group.add_argument("--load",           action="store_true", help="Load bitstream.")
    target_group.add_argument("--sys-clk-freq",   default=125e6,       help="System clock frequency.")
    target_group.add_argument("--with-ethernet",  action="store_true", help="Enable Ethernet support.")
    target_group.add_argument("--with-sdcard",    action="store_true", help="Enable SDcard support.")
    target_group.add_argument("--with-spi-flash", action="store_true", help="Enable SPI Flash (MMAPed).")
    target_group.add_argument("--with-pcie",      action="store_true", help="Enable PCIe support.")
    target_group.add_argument("--driver",         action="store_true", help="Generate PCIe driver.")
    target_group.add_argument("--with-sata",      action="store_true", help="Enable SATA support (over SFP2SATA).")
    builder_args(parser)
    soc_core_args(parser)
    args = parser.parse_args()

    soc = BaseSoC(
        sys_clk_freq   = int(float(args.sys_clk_freq)),
        with_ethernet  = args.with_ethernet,
        with_spi_flash = args.with_spi_flash,
        with_pcie      = args.with_pcie,
        with_sata      = args.with_sata,
        with_sdcard    = args.with_sdcard,
        **soc_core_argdict(args)
    )
    builder = Builder(soc, **builder_argdict(args))
    if args.build:
        builder.build()

    if args.driver:
        generate_litepcie_software(soc, os.path.join(builder.output_dir, "driver"))

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"))

if __name__ == "__main__":
    main()
