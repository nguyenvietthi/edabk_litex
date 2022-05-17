import os
import sys
try:
    import colorama
    colorama.init()  # install escape sequence translation on Windows
    _have_colorama = True
except ImportError:
    _have_colorama = False

from migen.fhdl.structure import *
from migen.fhdl.specials import Instance
from migen.fhdl.module import Module
from migen.genlib.cdc import *
from migen.genlib.resetsync import AsyncResetSynchronizer
from migen.genlib.io import *

from migen.build import tools


colors = []
if _have_colorama:
    colors += [
        ("^ERROR:.*$", colorama.Fore.RED + colorama.Style.BRIGHT +
         r"\g<0>" + colorama.Style.RESET_ALL),
        ("^CRITICAL WARNING:.*$", colorama.Fore.RED +
         r"\g<0>" + colorama.Style.RESET_ALL),
        ("^WARNING:.*$", colorama.Fore.YELLOW +
         r"\g<0>" + colorama.Style.RESET_ALL),
        ("^INFO:.*$", colorama.Fore.GREEN +
         r"\g<0>" + colorama.Style.RESET_ALL),
    ]


class XilinxMultiRegImpl(MultiRegImpl):
    def __init__(self, *args, **kwargs):
        MultiRegImpl.__init__(self, *args, **kwargs)
        i = self.i
        if not hasattr(i, "attr"):
            i0, i = i, Signal()
            self.comb += i.eq(i0)
        self.regs[0].attr.add("mr_ff")
        for r in self.regs:
            r.attr.add("async_reg")
            r.attr.add("no_shreg_extract")


class XilinxMultiReg:
    @staticmethod
    def lower(dr):
        return XilinxMultiRegImpl(dr.i, dr.o, dr.odomain, dr.n)


class XilinxAsyncResetSynchronizerImpl(Module):
    def __init__(self, cd, async_reset):
        if not hasattr(async_reset, "attr"):
            i, async_reset = async_reset, Signal()
            self.comb += async_reset.eq(i)
        rst_meta = Signal()
        self.specials += [
            Instance("FDPE", p_INIT=1, i_D=0, i_PRE=async_reset,
                i_CE=1, i_C=cd.clk, o_Q=rst_meta,
                attr={"async_reg", "ars_ff1"}),
            Instance("FDPE", p_INIT=1, i_D=rst_meta, i_PRE=async_reset,
                i_CE=1, i_C=cd.clk, o_Q=cd.rst,
                attr={"async_reg", "ars_ff2"})
        ]


class XilinxAsyncResetSynchronizer:
    @staticmethod
    def lower(dr):
        return XilinxAsyncResetSynchronizerImpl(dr.cd, dr.async_reset)


class XilinxDifferentialInputImpl(Module):
    def __init__(self, i_p, i_n, o):
        self.specials += Instance("IBUFDS", i_I=i_p, i_IB=i_n, o_O=o)


class XilinxDifferentialInput:
    @staticmethod
    def lower(dr):
        return XilinxDifferentialInputImpl(dr.i_p, dr.i_n, dr.o)


class XilinxDifferentialOutputImpl(Module):
    def __init__(self, i, o_p, o_n):
        self.specials += Instance("OBUFDS", i_I=i, o_O=o_p, o_OB=o_n)


class XilinxDifferentialOutput:
    @staticmethod
    def lower(dr):
        return XilinxDifferentialOutputImpl(dr.i, dr.o_p, dr.o_n)


xilinx_special_overrides = {
    MultiReg:               XilinxMultiReg,
    AsyncResetSynchronizer: XilinxAsyncResetSynchronizer,
    DifferentialInput:      XilinxDifferentialInput,
    DifferentialOutput:     XilinxDifferentialOutput
}


class XilinxDDROutputImplS6(Module):
    def __init__(self, i1, i2, o, clk):
        self.specials += Instance("ODDR2",
                p_DDR_ALIGNMENT="C0", p_INIT=0, p_SRTYPE="ASYNC",
                i_C0=clk, i_C1=~clk, i_CE=1, i_S=0, i_R=0,
                i_D0=i1, i_D1=i2, o_Q=o,
        )


class XilinxDDROutputS6:
    @staticmethod
    def lower(dr):
        return XilinxDDROutputImplS6(dr.i1, dr.i2, dr.o, dr.clk)

class XilinxDDRInputImplS6(Module):
    def __init__(self, i, o1, o2, clk):
        self.specials += Instance("IDDR2",
            p_DDR_ALIGNMENT = "C0",
            p_INIT_Q0       = 0,
            p_INIT_Q1       = 0,
            p_SRTYPE        = "ASYNC",
            i_C0 = clk,
            i_C1 = ~clk,
            i_CE = 1,
            i_S  = 0,
            i_R  = 0,
            i_D  = i,
            o_Q0 = o1,
            o_Q1 = o2
        )


class XilinxDDRInputS6:
    @staticmethod
    def lower(dr):
        return XilinxDDRInputImplS6(dr.i, dr.o1, dr.o2, dr.clk)


xilinx_s6_special_overrides = {
    DDROutput: XilinxDDROutputS6,
    DDRInput:  XilinxDDRInputS6,
}


class XilinxDDROutputImplS7(Module):
    def __init__(self, i1, i2, o, clk):
        self.specials += Instance("ODDR",
                p_DDR_CLK_EDGE="SAME_EDGE",
                i_C=clk, i_CE=1, i_S=0, i_R=0,
                i_D1=i1, i_D2=i2, o_Q=o,
        )


class XilinxDDROutputS7:
    @staticmethod
    def lower(dr):
        return XilinxDDROutputImplS7(dr.i1, dr.i2, dr.o, dr.clk)


class XilinxDDRInputImplS7(Module):
    def __init__(self, i, o1, o2, clk):
        self.specials += Instance("IDDR",
                p_DDR_CLK_EDGE="SAME_EDGE",
                i_C=clk, i_CE=1, i_S=0, i_R=0,
                i_D=i, o_Q1=o1, o_Q2=o2,
        )


class XilinxDDRInputS7:
    @staticmethod
    def lower(dr):
        return XilinxDDRInputImplS7(dr.i, dr.o1, dr.o2, dr.clk)


xilinx_s7_special_overrides = {
    DDROutput:              XilinxDDROutputS7,
    DDRInput:               XilinxDDRInputS7
}


class XilinxDDROutputImplKU(Module):
    def __init__(self, i1, i2, o, clk):
        self.specials += Instance("ODDRE1",
                i_C=clk, i_SR=0,
                i_D1=i1, i_D2=i2, o_Q=o,
        )


class XilinxDDROutputKU:
    @staticmethod
    def lower(dr):
        return XilinxDDROutputImplKU(dr.i1, dr.i2, dr.o, dr.clk)


class XilinxDDRInputImplKU(Module):
    def __init__(self, i, o1, o2, clk):
        self.specials += Instance("IDDRE1",
            p_DDR_CLK_EDGE="SAME_EDGE_PIPELINED",
            p_IS_C_INVERTED=0,
            p_IS_CB_INVERTED=1,
            i_D=i,
            o_Q1=o1, o_Q2=o2,
            i_C=clk, i_CB=clk,
            i_R=0
        )


class XilinxDDRInputKU:
    @staticmethod
    def lower(dr):
        return XilinxDDRInputImplKU(dr.i, dr.o1, dr.o2, dr.clk)


xilinx_ku_special_overrides = {
    DDROutput:              XilinxDDROutputKU,
    DDRInput:               XilinxDDRInputKU
}
