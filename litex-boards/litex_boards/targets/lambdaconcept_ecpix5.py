#!/usr/bin/env python3

#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2020-2022 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex_boards.platforms import lambdaconcept_ecpix5

from litex.build.lattice.trellis import trellis_args, trellis_argdict

from litex.soc.cores.clock import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.led import LedChaser
from litex.soc.cores.video import VideoDVIPHY
from litex.soc.cores.bitbang import I2CMaster

from litedram.modules import MT41K256M16
from litedram.phy import ECP5DDRPHY

from liteeth.phy.ecp5rgmii import LiteEthPHYRGMII

# CRG ----------------------------------------------------------------------------------------------

class _CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.rst = Signal()
        self.clock_domains.cd_init    = ClockDomain()
        self.clock_domains.cd_por     = ClockDomain()
        self.clock_domains.cd_sys     = ClockDomain()
        self.clock_domains.cd_sys2x   = ClockDomain()
        self.clock_domains.cd_sys2x_i = ClockDomain()

        # # #

        self.stop  = Signal()
        self.reset = Signal()

        # Clk / Rst
        clk100 = platform.request("clk100")
        rst_n  = platform.request("rst_n")

        # Power on reset
        por_count = Signal(16, reset=2**16-1)
        por_done  = Signal()
        self.comb += self.cd_por.clk.eq(clk100)
        self.comb += por_done.eq(por_count == 0)
        self.sync.por += If(~por_done, por_count.eq(por_count - 1))

        # PLL
        self.submodules.pll = pll = ECP5PLL()
        self.comb += pll.reset.eq(~por_done | ~rst_n | self.rst)
        pll.register_clkin(clk100, 100e6)
        pll.create_clkout(self.cd_sys2x_i, 2*sys_clk_freq)
        pll.create_clkout(self.cd_init, 25e6)
        self.specials += [
            Instance("ECLKSYNCB",
                i_ECLKI = self.cd_sys2x_i.clk,
                i_STOP  = self.stop,
                o_ECLKO = self.cd_sys2x.clk),
            Instance("CLKDIVF",
                p_DIV     = "2.0",
                i_ALIGNWD = 0,
                i_CLKI    = self.cd_sys2x.clk,
                i_RST     = self.reset,
                o_CDIVX   = self.cd_sys.clk),
            AsyncResetSynchronizer(self.cd_sys, ~pll.locked | self.reset),
        ]

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCCore):
    def __init__(self, device="85F", sys_clk_freq=int(75e6),
        with_ethernet          = False,
        with_etherbone         = False,
        with_video_terminal    = False,
        with_video_framebuffer = False,
        with_led_chaser        = True,
        **kwargs):
        platform = lambdaconcept_ecpix5.Platform(device=device, toolchain="trellis")

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = _CRG(platform, sys_clk_freq)

        # SoCCore ----------------------------------------------------------------------------------
        SoCCore.__init__(self, platform, sys_clk_freq, ident="LiteX SoC on ECPIX-5", **kwargs)

        # DDR3 SDRAM -------------------------------------------------------------------------------
        if not self.integrated_main_ram_size:
            self.submodules.ddrphy = ECP5DDRPHY(
                platform.request("ddram"),
                sys_clk_freq=sys_clk_freq)
            self.comb += self.crg.stop.eq(self.ddrphy.init.stop)
            self.comb += self.crg.reset.eq(self.ddrphy.init.reset)
            self.add_sdram("sdram",
                phy           = self.ddrphy,
                module        = MT41K256M16(sys_clk_freq, "1:2"),
                l2_cache_size = kwargs.get("l2_size", 8192)
            )

        # Ethernet / Etherbone ---------------------------------------------------------------------
        if with_ethernet or with_etherbone:
            self.submodules.ethphy = LiteEthPHYRGMII(
                clock_pads = self.platform.request("eth_clocks"),
                pads       = self.platform.request("eth"),
                rx_delay   = 0e-9)
            if with_ethernet:
                self.add_ethernet(phy=self.ethphy)
            if with_etherbone:
                self.add_etherbone(phy=self.ethphy)

        # HDMI -------------------------------------------------------------------------------------
        if with_video_terminal or with_video_framebuffer:
            # PHY + IT6613 I2C initialization.
            hdmi_pads = platform.request("hdmi")
            self.submodules.videophy = VideoDVIPHY(hdmi_pads, clock_domain="init")
            self.submodules.videoi2c = I2CMaster(hdmi_pads)

            # I2C initialization adapted from https://github.com/ultraembedded/ecpix-5
            # Copyright (c) 2020 https://github.com/ultraembedded
            # Adapted from C to Python.
            REG_TX_SW_RST = 0x04
            B_ENTEST   = (1<<7)
            B_REF_RST  = (1<<5)
            B_AREF_RST = (1<<4)
            B_VID_RST  = (1<<3)
            B_AUD_RST  = (1<<2)
            B_HDMI_RST = (1<<1)
            B_HDCP_RST = (1<<0)

            REG_TX_AFE_DRV_CTRL = 0x61
            B_AFE_DRV_PWD     = (1<<5)
            B_AFE_DRV_RST     = (1<<4)
            B_AFE_DRV_PDRXDET = (1<<2)
            B_AFE_DRV_TERMON  = (1<<1)
            B_AFE_DRV_ENCAL   = (1<<0)

            REG_TX_AFE_XP_CTRL = 0x62
            B_AFE_XP_GAINBIT   = (1<<7)
            B_AFE_XP_PWDPLL    = (1<<6)
            B_AFE_XP_ENI       = (1<<5)
            B_AFE_XP_ER0       = (1<<4)
            B_AFE_XP_RESETB    = (1<<3)
            B_AFE_XP_PWDI      = (1<<2)
            B_AFE_XP_DEI       = (1<<1)
            B_AFE_XP_DER       = (1<<0)

            REG_TX_AFE_ISW_CTRL = 0x63
            B_AFE_RTERM_SEL = (1<<7)
            B_AFE_IP_BYPASS = (1<<6)
            M_AFE_DRV_ISW   = (7<<3)
            O_AFE_DRV_ISW   = 3
            B_AFE_DRV_ISWK  = 7

            REG_TX_AFE_IP_CTRL = 0x64
            B_AFE_IP_GAINBIT = (1<<7)
            B_AFE_IP_PWDPLL  = (1<<6)
            M_AFE_IP_CKSEL   = (3<<4)
            O_AFE_IP_CKSEL   = 4
            B_AFE_IP_ER0     = (1<<3)
            B_AFE_IP_RESETB  = (1<<2)
            B_AFE_IP_ENC     = (1<<1)
            B_AFE_IP_EC1     = (1<<0)

            REG_TX_HDMI_MODE = 0xC0
            B_TX_HDMI_MODE = 1
            B_TX_DVI_MODE  = 0

            REG_TX_GCP = 0xC1
            B_CLR_AVMUTE    = 0
            B_SET_AVMUTE    = 1
            B_TX_SETAVMUTE  = (1<<0)
            B_BLUE_SCR_MUTE = (1<<1)
            B_NODEF_PHASE   = (1<<2)
            B_PHASE_RESYNC  = (1<<3)

            self.videoi2c.add_init(addr=0x4c, init=[
                # Reset.
                (REG_TX_SW_RST, B_REF_RST | B_VID_RST | B_AUD_RST | B_AREF_RST | B_HDCP_RST),
                (REG_TX_SW_RST, 0),

                # Select DVI Mode.
                (REG_TX_HDMI_MODE, B_TX_DVI_MODE),

                # Configure Clks.
                (REG_TX_SW_RST,       B_AUD_RST | B_AREF_RST | B_HDCP_RST),
                (REG_TX_AFE_DRV_CTRL, B_AFE_DRV_RST),
                (REG_TX_AFE_XP_CTRL,  0x18),
                (REG_TX_AFE_ISW_CTRL, 0x10),
                (REG_TX_AFE_IP_CTRL,  0x0C),

                # Enable Clks.
                (REG_TX_AFE_DRV_CTRL, 0),

                # Enable Video.
                (REG_TX_GCP, 0),
            ])
            # Video Terminal/Framebuffer.
            if with_video_terminal:
                self.add_video_terminal(phy=self.videophy, timings="640x480@75Hz", clock_domain="init")
            if with_video_framebuffer:
                self.add_video_framebuffer(phy=self.videophy, timings="640x480@75Hz", clock_domain="init")

        # Leds -------------------------------------------------------------------------------------
        if with_led_chaser:
            leds_pads = []
            for i in range(4):
                rgb_led_pads = platform.request("rgb_led", i)
                self.comb += [getattr(rgb_led_pads, n).eq(1) for n in "gb"] # Disable Green/Blue Leds.
                leds_pads += [getattr(rgb_led_pads, n) for n in "r"]
            self.submodules.leds = LedChaser(
                pads         = Cat(leds_pads),
                sys_clk_freq = sys_clk_freq)

# Build --------------------------------------------------------------------------------------------

def main():
    from litex.soc.integration.soc import LiteXSoCArgumentParser
    parser = LiteXSoCArgumentParser(description="LiteX SoC on ECPIX-5")
    target_group = parser.add_argument_group(title="Target options")
    target_group.add_argument("--build",           action="store_true", help="Build design.")
    target_group.add_argument("--load",            action="store_true", help="Load bitstream.")
    target_group.add_argument("--flash",           action="store_true", help="Flash bitstream to SPI Flash.")
    target_group.add_argument("--device",          default="85F",       help="ECP5 device (45F or 85F).")
    target_group.add_argument("--sys-clk-freq",    default=75e6,        help="System clock frequency.")
    target_group.add_argument("--with-sdcard",     action="store_true", help="Enable SDCard support.")
    ethopts = target_group.add_mutually_exclusive_group()
    ethopts.add_argument("--with-ethernet",  action="store_true", help="Enable Ethernet support.")
    ethopts.add_argument("--with-etherbone", action="store_true", help="Enable Etherbone support.")
    viopts = target_group.add_mutually_exclusive_group()
    viopts.add_argument("--with-video-terminal",    action="store_true", help="Enable Video Terminal (HDMI).")
    viopts.add_argument("--with-video-framebuffer", action="store_true", help="Enable Video Framebuffer (HDMI).")

    builder_args(parser)
    soc_core_args(parser)
    trellis_args(parser)
    args = parser.parse_args()

    soc = BaseSoC(
        device                 = args.device,
        sys_clk_freq           = int(float(args.sys_clk_freq)),
        with_ethernet          = args.with_ethernet,
        with_etherbone         = args.with_etherbone,
        with_video_terminal    = args.with_video_terminal,
        with_video_framebuffer = args.with_video_framebuffer,
        **soc_core_argdict(args)
    )
    if args.with_sdcard:
        soc.add_sdcard()
    builder = Builder(soc, **builder_argdict(args))
    if args.build:
        builder.build(**trellis_argdict(args))

    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(builder.get_bitstream_filename(mode="sram"))

    if args.flash:
        prog = soc.platform.create_programmer()
        prog.flash(None, builder.get_bitstream_filename(mode="flash"))

if __name__ == "__main__":
    main()
