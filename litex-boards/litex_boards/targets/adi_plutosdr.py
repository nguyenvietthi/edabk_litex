#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2022 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

# Build/Use:
# ./adi_plutosdr.py --build --load
# litex_server --jtag --jtag-config=openocd_xc7_ft232.cfg
# litex_term crossover

from migen import *

from litex_boards.platforms import adi_plutosdr
from litex.build.xilinx.vivado import vivado_build_args, vivado_build_argdict

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *

from litex.soc.cores.clock import *

# CRG ----------------------------------------------------------------------------------------------

class _CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.rst = Signal()
        self.clock_domains.cd_sys = ClockDomain()

        # # #

        # CFGM Clk ~65MHz.
        cfgm_clk      = Signal()
        cfgm_clk_freq = int(65e6)
        self.specials += Instance("STARTUPE2",
            i_CLK       = 0,
            i_GSR       = 0,
            i_GTS       = 0,
            i_KEYCLEARB = 1,
            i_PACK      = 0,
            i_USRCCLKO  = cfgm_clk,
            i_USRCCLKTS = 0,
            i_USRDONEO  = 1,
            i_USRDONETS = 1,
            o_CFGMCLK   = cfgm_clk
        )

        # PLL
        self.submodules.pll = pll = S7PLL(speedgrade=-1)
        self.comb += pll.reset.eq(self.rst)
        pll.register_clkin(cfgm_clk, cfgm_clk_freq)
        pll.create_clkout(self.cd_sys, sys_clk_freq)
        platform.add_false_path_constraints(self.cd_sys.clk, pll.clkin) # Ignore sys_clk to pll.clkin path created by SoC's rst.

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, sys_clk_freq=int(100e6), **kwargs):
        platform = adi_plutosdr.Platform()

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = _CRG(platform, sys_clk_freq)

        # SoCCore ----------------------------------------------------------------------------------
        kwargs["uart_name"] = "crossover"
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on Pluto SDR", **kwargs)

        # JTAGBone ---------------------------------------------------------------------------------
        self.add_jtagbone()

        # GPIOS ------------------------------------------------------------------------------------
        self.comb += platform.request("gpio", 0).eq(ClockSignal("sys"))

# Build --------------------------------------------------------------------------------------------

def main():
    from litex.soc.integration.soc import LiteXSoCArgumentParser
    parser = LiteXSoCArgumentParser(description="LiteX SoC on Pluto SDR")
    target_group = parser.add_argument_group(title="Target options")
    target_group.add_argument("--build",        action="store_true", help="Build design.")
    target_group.add_argument("--load",         action="store_true", help="Load bitstream.")
    target_group.add_argument("--sys-clk-freq", default=100e6,       help="System clock frequency.")

    builder_args(parser)
    soc_core_args(parser)
    vivado_build_args(parser)
    args = parser.parse_args()

    soc = BaseSoC(
        sys_clk_freq        = int(float(args.sys_clk_freq)),
        **soc_core_argdict(args)
    )
    builder = Builder(soc, **builder_argdict(args))
    if args.build:
        builder.build(**vivado_build_argdict(args))

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"), device=1)

if __name__ == "__main__":
    main()
