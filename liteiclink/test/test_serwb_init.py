#!/usr/bin/env python3

#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2019 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import unittest

from migen import *

from litex.gen.sim import *

from liteiclink.serwb import scrambler
from liteiclink.serwb.phy import _SerdesMasterInit, _SerdesSlaveInit

# Serdes Model -------------------------------------------------------------------------------------

class SerdesModel(Module):
    def __init__(self, taps, mode="slave"):
        self.tx           = Module()
        self.rx           = Module()

        self.tx.idle      = Signal()
        self.tx.comma     = Signal()
        self.rx.idle      = Signal()
        self.rx.comma     = Signal()

        self.rx.shift     = Signal(6)
        self.rx.delay_rst = Signal()
        self.rx.delay_inc = Signal()

        self.valid_shift  = Signal(6)
        self.valid_delays = Signal(taps)

        # # #

        delay   = Signal(max=taps)
        shift = Signal(6)

        valid_delays = Array(Signal() for i in range(taps))
        for i in range(taps):
            self.comb += valid_delays[taps-1-i].eq(self.valid_delays[i])

        self.sync += [
            shift.eq(self.rx.shift),
            If(self.rx.delay_rst,
                delay.eq(0)
            ).Elif(self.rx.delay_inc,
                delay.eq(delay + 1)
            )
        ]

        if mode == "master":
            self.submodules.fsm = fsm = ResetInserter()(FSM(reset_state="IDLE"))
            self.comb += self.fsm.reset.eq(self.tx.idle)
            fsm.act("IDLE",
                If(self.tx.comma,
                    NextState("SEND_COMMA")
                ),
                self.rx.idle.eq(1)
            )
            fsm.act("SEND_COMMA",
                If(valid_delays[delay] &
                   (shift == self.valid_shift),
                        self.rx.comma.eq(1)
                ),
                If(~self.tx.comma,
                    NextState("READY")
                )
            )
            fsm.act("READY")
        elif mode == "slave":
            self.submodules.fsm = fsm = FSM(reset_state="IDLE")
            fsm.act("IDLE",
                self.rx.idle.eq(1),
                NextState("SEND_COMMA")
            )
            fsm.act("SEND_COMMA",
                If(valid_delays[delay] &
                   (shift == self.valid_shift),
                        self.rx.comma.eq(1)
                ),
                If(~self.tx.idle,
                    NextState("READY")
                )
            )
            fsm.act("READY")

# DUT Master ---------------------------------------------------------------------------------------

class DUTMaster(Module):
    def __init__(self, taps=32):
        self.submodules.serdes = SerdesModel(taps, mode="master")
        self.submodules.init   = _SerdesMasterInit(self.serdes, taps, timeout=1)

# DUT Slave ----------------------------------------------------------------------------------------

class DUTSlave(Module):
    def __init__(self, taps=32):
        self.submodules.serdes = SerdesModel(taps, mode="slave")
        self.submodules.init   = _SerdesSlaveInit(self.serdes, taps, timeout=1)

# TestSERWBInit ------------------------------------------------------------------------------------

def generator(test, dut, valid_shift, valid_delays, check_success):
    yield dut.serdes.valid_shift.eq(valid_shift)
    yield dut.serdes.valid_delays.eq(valid_delays)
    while not ((yield dut.init.ready) or
               (yield dut.init.error)):
        yield
    if check_success:
        ready     = (yield dut.init.ready)
        error     = (yield dut.init.error)
        delay_min = (yield dut.init.delay_min)
        delay_max = (yield dut.init.delay_max)
        delay     = (yield dut.init.delay)
        shift     = (yield dut.init.shift)
        test.assertEqual(ready, 1)
        test.assertEqual(error, 0)
        test.assertEqual(delay_min, 4)
        test.assertEqual(delay_max, 9)
        test.assertEqual(delay, 6)
        test.assertEqual(shift, valid_shift)
    else:
        ready = (yield dut.init.ready)
        error = (yield dut.init.error)
        test.assertEqual(ready, 0)
        test.assertEqual(error, 1)

class TestSERWBInit(unittest.TestCase):
    def test_master_init_success(self):
        dut = DUTMaster()
        valid_shift  = 2
        valid_delays = 0b10001111100000111110000011111000
        run_simulation(dut, generator(self, dut, valid_shift, valid_delays, True))

    def test_master_init_failure(self):
        # too small window
        dut = DUTMaster()
        valid_shift  = 2
        valid_delays = 0b00000000000000010000000000000000
        run_simulation(dut, generator(self, dut, valid_shift, valid_delays, False))

    def test_slave_init_success(self):
        dut = DUTSlave()
        valid_shift  = 2
        valid_delays = 0b10001111100000111110000011111000
        run_simulation(dut, generator(self, dut, valid_shift, valid_delays, True))

    def test_slave_init_failure(self):
        # too small window
        dut = DUTSlave()
        valid_shift  = 2
        valid_delays = 0b00000000000000010000000000000000
        run_simulation(dut, generator(self, dut, valid_shift, valid_delays, False))
