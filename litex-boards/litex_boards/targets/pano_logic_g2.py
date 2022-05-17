#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import os

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex_boards.platforms import pano_logic_g2

from litex.soc.cores.clock import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser

from liteeth.phy import LiteEthPHY

# CRG ----------------------------------------------------------------------------------------------

class _CRG(Module):
    def __init__(self, platform, clk_freq, with_ethernet=False):
        self.rst = Signal()
        self.clock_domains.cd_sys    = ClockDomain()

        # # #

        if not with_ethernet:
            # Take Ethernet PHY out of reset to enable 125MHz on clk125 (25MHz otherwise).
            # See https://github.com/tomverbeure/panologic-g2#fpga-external-clocking-architecture
            self.comb += platform.request("eth_rst_n").eq(1)

        self.submodules.pll = pll = S6PLL(speedgrade=-2)
        self.comb += pll.reset.eq(~platform.request("user_btn_n") | self.rst)
        pll.register_clkin(platform.request("clk125"), 125e6)
        pll.create_clkout(self.cd_sys, clk_freq)
        platform.add_false_path_constraints(self.cd_sys.clk, pll.clkin) # Ignore sys_clk to pll.clkin path created by SoC's rst.

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, revision, sys_clk_freq=int(50e6), with_ethernet=False, with_etherbone=False,
                 eth_ip="192.168.1.50", with_led_chaser=True, **kwargs):
        platform = pano_logic_g2.Platform(revision=revision)
        if with_etherbone:
            sys_clk_freq = int(125e6)

        # CRG --------------------------------------------------------------------------------------
        with_ethernet = (with_ethernet or with_etherbone)
        self.submodules.crg = _CRG(platform, sys_clk_freq, with_ethernet=with_ethernet)

        # SoCCore ----------------------------------------------------------------------------------
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on Pano Logic G2", **kwargs)

        # Ethernet / Etherbone ---------------------------------------------------------------------
        if with_ethernet or with_etherbone:
            self.submodules.ethphy = LiteEthPHY(
                clock_pads         = self.platform.request("eth_clocks"),
                pads               = self.platform.request("eth"),
                clk_freq           = sys_clk_freq,
                with_hw_init_reset = False)
            if with_ethernet:
                self.add_ethernet(phy=self.ethphy)
            if with_etherbone:
                self.add_etherbone(phy=self.ethphy, ip_address=eth_ip)

        # Leds -------------------------------------------------------------------------------------
        if with_led_chaser:
            self.submodules.leds = LedChaser(
                pads         = platform.request_all("user_led"),
                sys_clk_freq = sys_clk_freq)

# Build --------------------------------------------------------------------------------------------

def main():
    from litex.soc.integration.soc import LiteXSoCArgumentParser
    parser = LiteXSoCArgumentParser(description="LiteX SoC on Pano Logic G2")
    target_group = parser.add_argument_group(title="Target options")
    target_group.add_argument("--build",           action="store_true",              help="Build design.")
    target_group.add_argument("--load",            action="store_true",              help="Load bitstream.")
    target_group.add_argument("--revision",        default="c",                      help="Board revision (b or c).")
    target_group.add_argument("--sys-clk-freq",    default=50e6,                     help="System clock frequency.")
    ethopts = target_group.add_mutually_exclusive_group()
    ethopts.add_argument("--with-ethernet",  action="store_true",              help="Enable Ethernet support.")
    ethopts.add_argument("--with-etherbone", action="store_true",              help="Enable Etherbone support.")
    target_group.add_argument("--eth-ip",          default="192.168.1.50", type=str, help="Ethernet/Etherbone IP address.")
    builder_args(parser)
    soc_core_args(parser)
    args = parser.parse_args()

    soc = BaseSoC(
        revision       = args.revision,
        sys_clk_freq   = int(float(args.sys_clk_freq)),
        with_ethernet  = args.with_ethernet,
        with_etherbone = args.with_etherbone,
        eth_ip         = args.eth_ip,
        **soc_core_argdict(args)
    )
    builder = Builder(soc, **builder_argdict(args))
    if args.build:
        builder.build()

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"))

if __name__ == "__main__":
    main()
