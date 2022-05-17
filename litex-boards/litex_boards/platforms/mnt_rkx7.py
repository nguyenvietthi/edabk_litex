#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2021 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from litex.build.generic_platform import *
from litex.build.xilinx import XilinxPlatform
from litex.build.openocd import OpenOCD

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Clk / Rst.
    ("clk100", 0, Pins("AA10"), IOStandard("LVCMOS15")),

    # Serial.
    ("serial", 0,
        Subsignal("tx", Pins("D15")),
        Subsignal("rx", Pins("C18")),
        IOStandard("LVCMOS33")
    ),

    # SPIFlash
    ("spiflash4x", 0,  # clock needs to be accessed through STARTUPE2
        Subsignal("cs_n", Pins("C23")),
        Subsignal("dq",   Pins("B24 A25 B22 A22")),
        IOStandard("LVCMOS33")
    ),

    # SDCard.
    ("spisdcard", 0,
        Subsignal("clk",  Pins("C11")),
        Subsignal("mosi", Pins("A15"), Misc("PULLUP True")),
        Subsignal("cs_n", Pins("B15"), Misc("PULLUP True")),
        Subsignal("miso", Pins("A14"), Misc("PULLUP True")),
        Misc("SLEW=FAST"),
        IOStandard("LVCMOS18"),
    ),
    ("sdcard", 0,
        Subsignal("data", Pins("A14 B10 A12 B15"), Misc("PULLUP True")),
        Subsignal("cmd",  Pins("A15"), Misc("PULLUP True")),
        Subsignal("clk",  Pins("C11")),
        Subsignal("cd",   Pins("A10")),
        Misc("SLEW=FAST"),
        IOStandard("LVCMOS18"),
    ),

    # RGMII Ethernet
    ("eth_refclk", 0, Pins("F17"), IOStandard("LVCMOS33")), # CHECKME: Drive it?
    ("eth_clocks", 0,
        Subsignal("tx", Pins("E18")),
        Subsignal("rx", Pins("D18")),
        IOStandard("LVCMOS33")
    ),
    ("eth", 0,
        Subsignal("rst_n",   Pins("G17"), IOStandard("LVCMOS33")),
        Subsignal("int_n",   Pins("E16"), IOStandard("LVCMOS33")),
        Subsignal("mdio",    Pins("E15"), IOStandard("LVCMOS33")),
        Subsignal("mdc",     Pins("E17"), IOStandard("LVCMOS33")),
        Subsignal("rx_ctl",  Pins("F15"), IOStandard("LVCMOS33")),
        Subsignal("rx_data", Pins("J15 J16 F20 D20"), IOStandard("LVCMOS33")),
        Subsignal("tx_ctl",  Pins("D19"), IOStandard("LVCMOS33")),
        Subsignal("tx_data", Pins("H18 H17 G19 F18"), IOStandard("LVCMOS33")),
    ),

    # I2C
    ("i2c", 0,
        Subsignal("scl", Pins("G12")),
        Subsignal("sda", Pins("A13")),
        IOStandard("LVCMOS18"),
    ),

    # DDR3 SDRAM.
    ("ddram", 0,
        Subsignal("a",       Pins(
            "AC8 AA7 AA8 AF7 AE7 AC11 V9 Y10",
            "AB11 Y7  Y8 V11  V8  W11 Y11 V7 "),
            IOStandard("SSTL15")),
        Subsignal("ba",      Pins("AC7 AB7 AB9"), IOStandard("SSTL15")),
        Subsignal("ras_n",   Pins("AA9"), IOStandard("SSTL15")),
        Subsignal("cas_n",   Pins("AD8"), IOStandard("SSTL15")),
        Subsignal("we_n",    Pins("AC9"), IOStandard("SSTL15")),
        Subsignal("cs_n",    Pins("AD9"), IOStandard("SSTL15")),
        Subsignal("dm",      Pins(
            "U6 Y3 AB6 AD4"),
            IOStandard("SSTL15")),
        Subsignal("dq",      Pins(
            " V4  W3  U5  U1  U7  U2  V6  V3",
            " Y2  Y1 AA3  V2 AC2  W1 AB2  V1",
            "AA4 AB4 AC4 AC3 AC6  Y6  Y5 AD6",
            "AD1 AE1 AE3 AE2 AE6 AE5 AF3 AF2"),
            IOStandard("SSTL15_T_DCI")),
        Subsignal("dqs_p",   Pins("W6 AB1 AA5 AF5"),
            IOStandard("DIFF_SSTL15")),
        Subsignal("dqs_n",   Pins("W5 AC1 AB5 AF4"),
            IOStandard("DIFF_SSTL15")),
        Subsignal("clk_p",   Pins("W10"),  IOStandard("DIFF_SSTL15")),
        Subsignal("clk_n",   Pins("W9"),   IOStandard("DIFF_SSTL15")),
        Subsignal("cke",     Pins("AB12"), IOStandard("SSTL15")),
        Subsignal("odt",     Pins("AC12"), IOStandard("SSTL15")),
        Subsignal("reset_n", Pins("AA2"),  IOStandard("LVCMOS15")),
        Misc("SLEW=FAST"),
        Misc("VCCAUX_IO=HIGH")
    ),
]

# Connectors ---------------------------------------------------------------------------------------

_connectors = []

# Platform -----------------------------------------------------------------------------------------

class Platform(XilinxPlatform):
    default_clk_name   = "clk100"
    default_clk_period = 1e9/100e6

    def __init__(self, toolchain="vivado"):
        XilinxPlatform.__init__(self, "xc7k325t-ffg676-2", _io, _connectors, toolchain=toolchain)

    def create_programmer(self):
        return OpenOCD("openocd_xc7_ft2232.cfg", "bscan_spi_xc7a325t.bit")

    def do_finalize(self, fragment):
        XilinxPlatform.do_finalize(self, fragment)
        self.add_period_constraint(self.lookup_request("clk100", loose=True), 1e9/100e6)
        self.add_platform_command("set_property INTERNAL_VREF 0.750 [get_iobanks 33]")
        self.add_platform_command("set_property INTERNAL_VREF 0.750 [get_iobanks 34]")
