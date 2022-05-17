#!/usr/bin/env python3

from migen import *

from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform

# IOs ----------------------------------------------------------------------------------------------

_io = [
    # Clk
    ("clk50", 0, Pins("Y2"), IOStandard("3.3-V LVTTL")),
    
    # Leds
    ("user_led", 0, Pins("G19"), IOStandard("3.3-V LVTTL")),
    ("user_led", 1, Pins("F19"), IOStandard("3.3-V LVTTL")),
    ("user_led", 2, Pins("E19"), IOStandard("3.3-V LVTTL")),
    ("user_led", 3, Pins("F21"), IOStandard("3.3-V LVTTL")),
    ("user_led", 4, Pins("F18"), IOStandard("3.3-V LVTTL")),
    ("user_led", 5, Pins("E18"), IOStandard("3.3-V LVTTL")),
    ("user_led", 6, Pins("J19"), IOStandard("3.3-V LVTTL")),
    ("user_led", 7, Pins("H19"), IOStandard("3.3-V LVTTL")),
    ("user_led", 8, Pins("J17"), IOStandard("3.3-V LVTTL")),
    ("user_led", 9, Pins("G17"), IOStandard("3.3-V LVTTL")),
    ("user_led", 10, Pins("J15"), IOStandard("3.3-V LVTTL")),
    ("user_led", 11, Pins("H16"), IOStandard("3.3-V LVTTL")),
    ("user_led", 12, Pins("J16"), IOStandard("3.3-V LVTTL")),
    ("user_led", 13, Pins("H17"), IOStandard("3.3-V LVTTL")),
    ("user_led", 14, Pins("F15"), IOStandard("3.3-V LVTTL")),
    ("user_led", 15, Pins("G15"), IOStandard("3.3-V LVTTL")),

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

    # ("cpu_reset", 16, Pins("Y24"), IOStandard("3.3-V LVTTL"))
]

# Platform -----------------------------------------------------------------------------------------

class Platform(AlteraPlatform):
    default_clk_name = "clk50"
    default_clk_period = 10.0

    def __init__(self):
        AlteraPlatform.__init__(self, "EP4CE115F29I7", _io, toolchain="quartus")

    def do_finalize(self, fragment):
        AlteraPlatform.do_finalize(self, fragment)

# Design -------------------------------------------------------------------------------------------

# Create our platform (fpga interface)
platform = Platform()

# Create our module (fpga description)
class Switches(Module):
    def __init__(self, platform):     
        # synchronous assignments
        self.sync += []
        # combinatorial assignements
        for i in range(0, 8):
            led = platform.request("user_led", i)
            sw = platform.request("user_sw", i)
            self.comb += led.eq(~sw)
        for i in range(8, 16):
            led = platform.request("user_led", i)
            sw = platform.request("user_sw", i)
            self.comb += led.eq(sw)

module = Switches(platform)

# Build --------------------------------------------------------------------------------------------

platform.build(module)

