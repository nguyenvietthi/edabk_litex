from migen import *

from tick import Tick

# Goals:
# - understand own to use external modules
# - understand seven segment display and create simple digit controller
# - understand how to multiplex displays
# - use python capabilities to create visual simulations

# SevenSegment -------------------------------------------------------------------------------------

class SevenSegment(Module):
    def __init__(self):
        # Module's interface
        self.value   = value = Signal(4)         # input
        self.abcdefg = abcdefg = Signal(7)     # output

        # # #

        # Value to abcd segments dictionary.
        # Here we create a table to translate each of the 16 possible input
        # values to abdcefg segments control.
        cases = {
          0x0: abcdefg.eq(0b0111111),
          0x1: abcdefg.eq(0b0000110),
          0x2: abcdefg.eq(0b1011011),
          0x3: abcdefg.eq(0b1001111),
          0x4: abcdefg.eq(0b1100110),
          0x5: abcdefg.eq(0b1101101),
          0x6: abcdefg.eq(0b1111101),
          0x7: abcdefg.eq(0b0000111),
          0x8: abcdefg.eq(0b1111111),
          0x9: abcdefg.eq(0b1101111),
          0xa: abcdefg.eq(0b1110111),
          0xb: abcdefg.eq(0b1111100),
          0xc: abcdefg.eq(0b0111001),
          0xd: abcdefg.eq(0b1011110),
          0xe: abcdefg.eq(0b1111001),
          0xf: abcdefg.eq(0b1110001),
        }

        # Combinatorial assignement
        self.comb += Case(value, cases)

#SevenSegmentDisplay_noScanLed
class SevenSegmentDisplay_noScanLed(Module):
    def __init__(self):
        self.values = Array(Signal(4) for i in range(6))
        self.abcdefg = Array(Signal(7) for i in range(6))

        seven_segment = list(SevenSegment() for i in range(6))
        for i in range(6):
            self.submodules += seven_segment[i]

        for i in range(6):
            self.comb += seven_segment[i].value.eq(self.values[i])

        for i in range(6):
            self.comb += self.abcdefg[i].eq(seven_segment[i].abcdefg)

# SevenSegmentDisplay ------------------------------------------------------------------------------
class SevenSegmentDisplay(Module):
    def __init__(self, sys_clk_freq, cs_period=0.001):
        # Module's interface
        self.values = Array(Signal(5) for i in range(6))  # input

        self.cs = Signal(6)      # output
        self.abcdefg = Signal(7) # output

        # # #

        # Create our seven segment controller
        seven_segment = SevenSegment()
        self.submodules += seven_segment
        self.comb += self.abcdefg.eq(seven_segment.abcdefg)

        # Create a tick every cs_period
        self.submodules.tick = Tick(sys_clk_freq, cs_period)

        # Rotate cs 6 bits signals to alternate seven segments
		# cycle 0 : 0b000001
	    # cycle 1 : 0b000010
	    # cycle 2 : 0b000100
	    # cycle 3 : 0b001000
	    # cycle 4 : 0b010000
	    # cycle 5 : 0b010000
	    # cycle 6 : 0b100000
		# cycle 7 : 0b000001
        cs = Signal(6, reset=0b000001)
        # Synchronous assigment
        self.sync += [
            If(self.tick.ce,     # At the next tick:
                cs[1].eq(cs[0]), # bit1 takes bit0 value
                cs[2].eq(cs[1]), # bit2 takes bit1 value
                cs[3].eq(cs[2]), # bit3 takes bit2 value
                cs[4].eq(cs[3]), # bit4 takes bit3 value
                cs[5].eq(cs[4]), # bit5 takes bit4 value
                cs[0].eq(cs[5])  # bit0 takes bit5 value
            )
        ]
        # Combinatorial assigment
        self.comb += self.cs.eq(cs)

        # cs to value selection.
        # Here we create a table to translate each of the 8 cs possible values
        # to input value selection.
        cases = {
            0b000001 : seven_segment.value.eq(self.values[0]),
            0b000010 : seven_segment.value.eq(self.values[1]),
            0b000100 : seven_segment.value.eq(self.values[2]),
            0b001000 : seven_segment.value.eq(self.values[3]),
            0b010000 : seven_segment.value.eq(self.values[4]),
            0b100000 : seven_segment.value.eq(self.values[5])
        }
        # Combinatorial assigment
        self.comb += Case(self.cs, cases)

# Main ---------------------------------------------------------------------------------------------

if __name__ == '__main__':
    # SevenSegment simulation
    print("SevenSegment simulation")
    dut = SevenSegment()

    def show_seven_segment(abcdefg):
        line0 = ["   ", " _ "]
        line1 = ["   ", "  |", " _ ", " _|", "|  ", "| |" , "|_ ", "|_|"]
        a = abcdefg & 0b1;
        fgb = ((abcdefg >> 1) & 0b001) | ((abcdefg >> 5) & 0b010) | ((abcdefg >> 3) & 0b100)
        edc = ((abcdefg >> 2) & 0b001) | ((abcdefg >> 2) & 0b010) | ((abcdefg >> 2) & 0b100)
        print(line0[a])
        print(line1[fgb])
        print(line1[edc])

    def dut_tb(dut):
        for i in range(16):
            yield dut.value.eq(i)
            yield
            show_seven_segment((yield dut.abcdefg))

    run_simulation(dut, dut_tb(dut), vcd_name="seven_segment.vcd")

    # SevenSegmentDisplay simulation
    print("SevenSegmentDisplay simulation")
    dut = SevenSegmentDisplay(100e6, 0.000001)
    def dut_tb(dut):
        for i in range(4096):
            for j in range(6):
                yield dut.values[j].eq(i + j)
            yield

    run_simulation(dut, dut_tb(dut), vcd_name="display.vcd")
