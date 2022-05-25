#!/usr/bin/env python3

from migen import *

from litex.build.generic_platform import *
from litex.build.altera import AlteraPlatform


from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.cores.uart import UARTWishboneBridge
from litex.soc.cores import dna, xadc
from litex.soc.cores.spi import SPIMaster

from ios import Led, RGBLed, Button, Switch
from display import SevenSegmentDisplay

# IOs ----------------------------------------------------------------------------------------------

_io = [
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

    # Button
    ("user_btn", 0, Pins("M23"), IOStandard("3.3-V LVTTL")),
    ("user_btn", 1, Pins("M21"), IOStandard("3.3-V LVTTL")),
    ("user_btn", 2, Pins("N21"), IOStandard("3.3-V LVTTL")),

    # Seven Segment
    ("seven_seg", 0, Pins("G18 F22 E17 L26 L25 J22 H22"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 1, Pins("M24 Y22 W21 W22 W25 U23 U24"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 2, Pins("AA25 AA26 Y25 W26 Y26 W27 W28"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 3, Pins("V21 U21 AB20 AA21 AD24 AF23 Y19"), IOStandard("3.3-V LVTTL")),
    ("seven_seg", 4, Pins("AB19 AA19 AG21 AH21 AE19 AF19 AE18"),  IOStandard("3.3-V LVTTL")),
    ("seven_seg", 5, Pins("AD18 AC18 AB18 AH19 AG19 AF18 AH18"), IOStandard("3.3-V LVTTL")),
    # Clk
    ("clk50", 0, Pins("Y2"), IOStandard("3.3-V LVTTL")),

    # #cpu_reset
    ("cpu_reset", 0, Pins("R24"), IOStandard("3.3-V LVTTL")),

    # Serial
    ("serial", 0,
        Subsignal("tx", Pins("G9"), IOStandard("3.3-V LVTTL")), # Use built-in Tx RS32 port
        Subsignal("rx", Pins("G12"), IOStandard("3.3-V LVTTL"))  #  Use built-in Rx RS32 port
    )
]

# Platform -----------------------------------------------------------------------------------------

class Platform(AlteraPlatform):
    default_clk_name   = "clk50"
    default_clk_period = 1e9/50e6

    def __init__(self):
        AlteraPlatform.__init__(self, "EP4CE115F29C7", _io, toolchain="quartus")

# Design -------------------------------------------------------------------------------------------

# Create our platform (fpga interface)
platform = Platform()

# Create our soc (fpga description)
class BaseSoC(SoCMini):
    def __init__(self, platform, **kwargs):
        sys_clk_freq = int(50e6)

        # SoC with CPU
        SoCCore.__init__(self, platform,
            cpu_type                 = "vexriscv",
            clk_freq                 = 50e6,
            ident                    = "LiteX CPU Test SoC", ident_version=True,
            integrated_rom_size      = 0x8000,
            integrated_main_ram_size = 0x4000)

        # Clock Reset Generation
        self.submodules.crg = CRG(platform.request("clk50"), ~platform.request("cpu_reset"))

        # # No CPU, use Serial to control Wishbone bus
        # self.submodules.serial_bridge = UARTWishboneBridge(platform.request("serial"), sys_clk_freq)
        # self.add_wb_master(self.serial_bridge.wishbone)

        # # FPGA identification
        # self.submodules.dna = dna.DNA()
        # self.add_csr("dna")

        # # FPGA Temperature/Voltage
        # self.submodules.xadc = xadc.XADC()
        # self.add_csr("xadc")

        # Led
        user_leds = Cat(*[platform.request("user_led", i) for i in range(16)])
        self.submodules.leds = Led(user_leds)
        self.add_csr("leds")

        # Switches
        user_switches = Cat(*[platform.request("user_sw", i) for i in range(16)])
        self.submodules.switches = Switch(user_switches)
        self.add_csr("switches")

        # Buttons
        user_buttons = Cat(*[platform.request("user_btn", i) for i in range(3)])
        self.submodules.buttons = Button(user_buttons)
        self.add_csr("buttons")

        # # Accelerometer
        # self.submodules.adxl362 = SPIMaster(platform.request("adxl362_spi"),
        #     data_width   = 32,
        #     sys_clk_freq = sys_clk_freq,
        #     spi_clk_freq = 1e6)
        # self.add_csr("adxl362")

        # SevenSegmentDisplay
        self.submodules.display = SevenSegmentDisplay()
        self.add_csr("display")
        for i in range(6):
            self.comb += platform.request("seven_seg", i).eq(~self.display.abcdefg[i])

soc = BaseSoC(platform)

# Build --------------------------------------------------------------------------------------------

builder = Builder(soc, output_dir="build", csr_csv="test/csr.csv")
builder.build(build_name="top")
