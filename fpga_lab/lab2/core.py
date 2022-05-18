from migen import *

# Goals:
# - understand how to create simple logical core
# - understand how to create a FSM

# Indications:
# You can choose to code the clock core with only
# - If/Elif/Else in Migen:
# https://m-labs.hk/migen/manual/fhdl.html#statements
#
# or with
#
# - a FSM in Migen:
# https://github.com/m-labs/migen/blob/master/examples/basic/fsm.py
#
# or try both...

# Core ---------------------------------------------------------------------------------------------

class Core(Module):
    def __init__(self):
        # Module's interface
        self.tick = Signal()     # input
        self.seconds = Signal(6) # output
        self.minutes = Signal(6) # output
        self.hours = Signal(5)   # output

        # Set interface
        self.inc_minutes = Signal() # input
        self.inc_hours = Signal()   # output

        # # #

        # Synchronous assigment
        self.sync += [
            # Increment minutes
            If(self.inc_minutes,
                self.minutes.eq(self.minutes + 1)
            # Increment hours
            ).Elif(self.inc_hours,
                self.hours.eq(self.hours + 1)
            # At each tick
            ).Elif(self.tick,
                self.seconds.eq(self.seconds + 1),
                # Reach end of seconds
                If(self.seconds == (60-1),
                    self.seconds.eq(0),
                    self.minutes.eq(self.minutes + 1),
                    # Reach end of minutes
                    If(self.minutes == (60-1),
                        self.minutes.eq(0),
                        self.hours.eq(self.hours + 1),
                        # Reach end of hours
                        If(self.hours == (24-1),
                            self.hours.eq(0)
                            # Nothing else since we are not counting days...
                        )
                    )
                )
            )
        ]

# CoreFSM ------------------------------------------------------------------------------------------

class CoreFSM(Module):
    def __init__(self):
        # Module's interface
        self.tick    = Signal()  # input
        self.seconds = Signal(6) # output
        self.minutes = Signal(6) # output
        self.hours   = Signal(5) # output

        # Set interface
        self.inc_minutes = Signal() # input
        self.inc_hours   = Signal() # output

        # # #

        self.submodules.fsm = fsm = FSM(reset_state="IDLE")

        # -- TO BE COMPLETED --
        fsm.act("IDLE",
            If(self.tick,
                NextState("INC_SECONDS")
            ),

        )

        fsm.act("INC_SECONDS",
		    NextValue(self.seconds, self.seconds + 1),
			NextState("IDLE")
        )

        fsm.act("INC_MINUTES",
			NextState("IDLE")
        )

        fsm.act("INC_HOURS",
           NextState("IDLE")
        )
		# -- TO BE COMPLETED --

# Main ---------------------------------------------------------------------------------------------

if __name__ == '__main__':
    # Seven segment simulation
    print("Core simulation")
    # Uncomment the one you want to simulate
    dut = Core()
    #dut = CoreFSM()

    def show_time(cycle, hours, minutes, seconds):
        print("cycle %d: hh:%02d, mm:%02d, ss:%02d" %(cycle, hours, minutes, seconds))

    def dut_tb(dut):
        yield dut.tick.eq(1) # Tick active on each cycle
        for i in range(3600*48):
            yield
            show_time(i,
                (yield dut.hours),
                (yield dut.minutes),
                (yield dut.seconds))

    run_simulation(dut, dut_tb(dut), vcd_name="core.vcd")
