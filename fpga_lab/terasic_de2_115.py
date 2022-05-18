#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2019 Antony Pavlov <antonynpavlov@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform
from litex.build.altera.programmer import USBBlaster

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Clk
    ("clk50", 0, Pins("Y2"), IOStandard("3.3-V LVTTL")),
    
    # Leds
    ("user_led_r", 0, Pins("G19"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 1, Pins("F19"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 2, Pins("E19"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 3, Pins("F21"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 4, Pins("F18"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 5, Pins("E18"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 6, Pins("J19"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 7, Pins("H19"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 8, Pins("J17"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 9, Pins("G17"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 10, Pins("J15"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 11, Pins("H16"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 12, Pins("J16"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 13, Pins("H17"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 14, Pins("F15"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 15, Pins("G15"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 16, Pins("G16"), IOStandard("3.3-V LVTTL")),
    ("user_led_r", 17, Pins("H15"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 0, Pins("E21"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 1, Pins("E22"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 2, Pins("E25"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 3, Pins("E24"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 4, Pins("H21"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 5, Pins("G20"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 6, Pins("G22"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 7, Pins("G21"), IOStandard("3.3-V LVTTL")),
    ("user_led_g", 8, Pins("F17"), IOStandard("3.3-V LVTTL")),
    
    # Seven Segment
    ("seven_seg", 0, Pins("G18 F22 E17 L26 L25 J22 H22"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 1, Pins("M24 Y22 W21 W22 W25 U23 U24"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 2, Pins("AA25 AA26 Y25 W26 Y26 W27 W28"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 3, Pins("V21 U21 AB20 AA21 AD24 AF23 Y19"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 4, Pins("AB19 AA19 AG21 AH21 AE19 AF19 AE18"),  IOStandard("3.3-V LVTTL")),
    ("seven_seg", 5, Pins("AD18 AC18 AB18 AH19 AG19 AF18 AH18"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 6, Pins("AA17 AB16 AA16 AB17 AB15 AA15 AC17"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 7, Pins("AD17 AE17 AG17 AH17 AF17 AG18 AA14"), IOStandard("3.3-V LVTTL")),
    
    # Button
    ("key", 0, Pins("M23"), IOStandard("3.3-V LVTTL")),
    ("key", 1, Pins("M21"), IOStandard("3.3-V LVTTL")),
    ("key", 2, Pins("N21"), IOStandard("3.3-V LVTTL")),
    ("key", 3, Pins("R24"), IOStandard("3.3-V LVTTL")),

    # Switches
    ("user_sw", 0, Pins("AB28"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 1, Pins("AC28"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 2, Pins("AC27"),  IOStandard("3.3-V LVTTL")),
    ("user_sw", 3, Pins("AD27"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 4, Pins("AB27"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 5, Pins("AC26"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 6, Pins("AD26"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 7, Pins("AB26"),  IOStandard("3.3-V LVTTL")),
    ("user_sw", 8, Pins("AC25"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 9, Pins("AB25"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 10, Pins("AC24"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 11, Pins("AB24"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 12, Pins("AB23"),  IOStandard("3.3-V LVTTL")),
    ("user_sw", 13, Pins("AA24"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 14, Pins("AA23"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 15, Pins("AA22"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 16, Pins("Y24"), IOStandard("3.3-V LVTTL")),
    ("user_sw", 17, Pins("Y23"),  IOStandard("3.3-V LVTTL")),

    # Serial
    ("serial", 0,
        Subsignal("tx", Pins("G9"), IOStandard("3.3-V LVTTL")), # Use built-in Tx RS32 port
        Subsignal("rx", Pins("G12"), IOStandard("3.3-V LVTTL"))  #  Use built-in Rx RS32 port
    ),
    
    # I2C
    ("i2c", 0,
        Subsignal("scl", Pins("B7")),
        Subsignal("sda", Pins("A8")),
        IOStandard("3.3-V LVTTL")
    ),
    
    # VGA
    ("vga", 0,
        Subsignal("hsync_n", Pins("G13")),
        Subsignal("vsync_n", Pins("C13")),
        Subsignal("r", Pins("E12 E11 D10 F12 G10 J12 H8 H10")),
        Subsignal("g", Pins("G8 G11 F8 H12 C8 B8 F10 C9")),
        Subsignal("b", Pins("B10 A10 C11 B11 A11 C12 D11 D12 F11")),
        IOStandard("3.3-V LVTTL")
    ),

    # SDR SDRAM
    ("sdram_clock", 0, Pins("AE5"), IOStandard("3.3-V LVTTL")),
    ("sdram", 0,
        Subsignal("a",     Pins(
            "R6 V8 U8 P1 V5 W8 W7 AA7",
            "Y5 Y6 R5 AA5 Y7")),
        Subsignal("ba",    Pins("U7 R4")),
        Subsignal("cs_n",  Pins("T4")),
        Subsignal("cke",   Pins("AA6")),
        Subsignal("ras_n", Pins("U6")),
        Subsignal("cas_n", Pins("V7")),
        Subsignal("we_n",  Pins("V6")),
        Subsignal("dq", Pins(
            "W3 W2  V4  W1  V3  V2  V1  U3",
            "Y3 Y4 AB1 AA3 AB2 AC1 AB3 AC2")),
        Subsignal("dm", Pins("U2 W4")),
        IOStandard("3.3-V LVTTL")
    ),

    # Ethernet 0
    ("eth0_clocks", 0,
        Subsignal("tx",  Pins("B17")),
        Subsignal("gtx", Pins("A17")),
        Subsignal("rx",  Pins("U27")),
        IOStandard("3.3-V LVTTL")
    ),
    ("eth0", 0,
        Subsignal("rst_n",   Pins("C19")),
        Subsignal("int_n",   Pins("A21")),
        Subsignal("mdio",    Pins("B21")),
        Subsignal("mdc",     Pins("C20")),
        Subsignal("rx_dv",   Pins("C17")),
        Subsignal("rx_er",   Pins("D18")),
        Subsignal("rx_data", Pins("C16 D16 D17 C15")),
        Subsignal("tx_en",   Pins("A18")),
        Subsignal("tx_er",   Pins("B18")),
        Subsignal("tx_data", Pins("C18 D19 A19 B19")),
        Subsignal("col",     Pins("E15")),
        Subsignal("crs",     Pins("D15")),
        IOStandard("3.3-V LVTTL")
    ),

    # Ethernet 1
    ("eth1_clocks", 0,
        Subsignal("tx",  Pins("C22")),
        Subsignal("gtx", Pins("C23")),
        Subsignal("rx",  Pins("B15")),
        IOStandard("3.3-V LVTTL")
    ),
    ("eth1", 0,
        Subsignal("rst_n",   Pins("D22")),
        Subsignal("int_n",   Pins("D24")),
        Subsignal("mdio",    Pins("D25")),
        Subsignal("mdc",     Pins("D23")),
        Subsignal("rx_dv",   Pins("A22")),
        Subsignal("rx_er",   Pins("C24")),
        Subsignal("rx_data", Pins("B23 C21 A23 D21")),
        Subsignal("tx_en",   Pins("B25")),
        Subsignal("tx_er",   Pins("A25")),
        Subsignal("tx_data", Pins("C25 A26 B26 C26")),
        Subsignal("col",     Pins("B22")),
        Subsignal("crs",     Pins("D20")),
        IOStandard("3.3-V LVTTL")
    ),

    # LCD
    ("lcd", 0,
        Subsignal("data", Pins("M5 M3 K2 K1 K7 L2 L1 L3")),
        Subsignal("e",  Pins("L4")),
        Subsignal("rs", Pins("M2")),
        Subsignal("rw", Pins("M1")),
        Subsignal("on", Pins("L5")),
        Subsignal("blon", Pins("L6")),
        IOStandard("1.5-V")
    ),

    # GPIOs
    ("gpio", 0, Pins(
        "AB22 AC15  AB21  Y17  AC21  Y16  AD21  AE16",
        "AD15 AE15  AC19  AF16 AD19  AF15 AF24  AE21",
        "AF25 AC22  AE22  AF21 AF22  AD22 AG25  AD25",
        "AH25 AE25  AG22  AE24 AH22  AF26 AE20  AG23",
        "AF20 AH26  AH23  AG26"),
        IOStandard("3.3-V LVTTL")
    ),
]

# Platform -----------------------------------------------------------------------------------------

class Platform(AlteraPlatform):
    default_clk_name   = "clk50"
    default_clk_period = 1e9/50e6

    def __init__(self, toolchain="quartus"):
        AlteraPlatform.__init__(self, "EP4CE115F29C7", _io, toolchain=toolchain)

    def create_programmer(self):
        return USBBlaster()

    def do_finalize(self, fragment):
        AlteraPlatform.do_finalize(self, fragment)
        self.add_period_constraint(self.lookup_request("clk50", loose=True), 1e9/50e6)
