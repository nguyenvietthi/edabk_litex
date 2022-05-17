#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2020 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

from math import ceil

from migen import *
from migen.genlib.misc import WaitTimer

from litex.gen import *

from litex.soc.interconnect import stream

# Layouts ------------------------------------------------------------------------------------------

def phy_description(dw):
    layout = [("data", dw)]
    return stream.EndpointDescription(layout)


def user_description(dw):
    layout = [("data", 32), ("length", 32)]
    return stream.EndpointDescription(layout)

# Header -------------------------------------------------------------------------------------------

class HeaderField:
    def __init__(self, byte, offset, width):
        self.byte = byte
        self.offset = offset
        self.width = width


class Header:
    def __init__(self, fields, length, swap_field_bytes=True):
        self.fields = fields
        self.length = length
        self.swap_field_bytes = swap_field_bytes

    def get_layout(self):
        layout = []
        for k, v in sorted(self.fields.items()):
            layout.append((k, v.width))
        return layout

    def get_field(self, obj, name, width):
        if "_lsb" in name:
            field = getattr(obj, name.replace("_lsb", ""))[:width]
        elif "_msb" in name:
            field = getattr(obj, name.replace("_msb", ""))[width:2*width]
        else:
            field = getattr(obj, name)
        if len(field) != width:
            raise ValueError("Width mismatch on " + name + " field")
        return field

    def encode(self, obj, signal):
        r = []
        for k, v in sorted(self.fields.items()):
            start = v.byte*8 + v.offset
            end = start + v.width
            field = self.get_field(obj, k, v.width)
            if self.swap_field_bytes:
                field = reverse_bytes(field)
            r.append(signal[start:end].eq(field))
        return r

    def decode(self, signal, obj):
        r = []
        for k, v in sorted(self.fields.items()):
            start = v.byte*8 + v.offset
            end = start + v.width
            field = self.get_field(obj, k, v.width)
            if self.swap_field_bytes:
                r.append(field.eq(reverse_bytes(signal[start:end])))
            else:
                r.append(field.eq(signal[start:end]))
        return r

# Packetizer ---------------------------------------------------------------------------------------

class Packetizer(Module):
    def __init__(self):
        self.sink   = sink   = stream.Endpoint(user_description(32))
        self.source = source = stream.Endpoint(phy_description(32))

        # # #

        # Packet description
        #   - Preamble : 4 bytes
        #   - Length   : 4 bytes
        #   - Payload

        self.submodules.fsm = fsm = FSM(reset_state="PREAMBLE")
        fsm.act("PREAMBLE",
            If(sink.valid,
                source.valid.eq(1),
                source.data.eq(0x5aa55aa5),
                If(source.ready,
                    NextState("LENGTH")
                )
            )
        )
        fsm.act("LENGTH",
            source.valid.eq(1),
            source.data.eq(sink.length),
            If(source.ready,
                NextState("DATA")
            )
        )
        fsm.act("DATA",
            source.valid.eq(sink.valid),
            source.data.eq(sink.data),
            sink.ready.eq(source.ready),
            If(source.ready & sink.last,
                NextState("PREAMBLE")
            )
        )

# Depacketizer -------------------------------------------------------------------------------------

class Depacketizer(Module):
    def __init__(self, clk_freq, timeout=10):
        self.sink   = sink   = stream.Endpoint(phy_description(32))
        self.source = source = stream.Endpoint(user_description(32))

        # # #

        count  = Signal(len(source.length))
        length = Signal(len(source.length))

        # Packet description
        #   - Preamble : 4 bytes
        #   - Length   : 4 bytes
        #   - Payload

        self.submodules.timer = timer = WaitTimer(clk_freq*timeout)

        self.submodules.fsm = fsm = FSM(reset_state="PREAMBLE")
        fsm.act("PREAMBLE",
            sink.ready.eq(1),
            If(sink.valid &
              (sink.data == 0x5aa55aa5),
                NextState("LENGTH")
            )
        )
        fsm.act("LENGTH",
            sink.ready.eq(1),
            If(sink.valid,
                NextValue(count, 0),
                NextValue(length, sink.data),
                NextState("DATA")
            ),
            timer.wait.eq(1)
        )
        fsm.act("DATA",
            source.valid.eq(sink.valid),
            source.last.eq(count == (length[2:] - 1)),
            source.length.eq(length),
            source.data.eq(sink.data),
            sink.ready.eq(source.ready),
            If(timer.done,
                NextState("PREAMBLE")
            ).Elif(source.valid & source.ready,
                NextValue(count, count + 1),
                If(source.last,
                    NextState("PREAMBLE")
                )
            ),
            timer.wait.eq(1)
        )
