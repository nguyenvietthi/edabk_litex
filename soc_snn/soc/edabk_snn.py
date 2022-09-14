from migen import *

from litex.soc.interconnect.csr import *

from litex.soc.interconnect.csr_eventmanager import *

from litex.soc.integration.doc import AutoDoc, ModuleDoc

class edabk_snn(Module, AutoCSR, AutoDoc):
    def __init__(self, platform):
        self.intro = ModuleDoc(""" EDABK SNN""")

        self.clk          = Signal()
        self.sys_clk      = Signal()
        self.param_wdata  = Signal(384)

        self.tick         = CSRStorage(name="tick",description='Send tick to SNN', reset=0x0, size=1)
        
        self.packet       = CSRStorage(name="packet_wdata",description='Packet data send SNN', reset=0x0, size=30)

        self.param0       = CSRStorage(name="param_wdata0",description='Param data0 send SNN', reset=0x0, size=32)
        self.param1       = CSRStorage(name="param_wdata1",description='Param data1 send SNN', reset=0x0, size=32)
        self.param2       = CSRStorage(name="param_wdata2",description='Param data2 send SNN', reset=0x0, size=32)
        self.param3       = CSRStorage(name="param_wdata3",description='Param data3 send SNN', reset=0x0, size=32)
        self.param4       = CSRStorage(name="param_wdata4",description='Param data4 send SNN', reset=0x0, size=32)
        self.param5       = CSRStorage(name="param_wdata5",description='Param data5 send SNN', reset=0x0, size=32)
        self.param6       = CSRStorage(name="param_wdata6",description='Param data6 send SNN', reset=0x0, size=32)
        self.param7       = CSRStorage(name="param_wdata7",description='Param data7 send SNN', reset=0x0, size=32)
        self.param8       = CSRStorage(name="param_wdata8",description='Param data8 send SNN', reset=0x0, size=32)
        self.param9       = CSRStorage(name="param_wdata9",description='Param data9 send SNN', reset=0x0, size=32)
        self.param10      = CSRStorage(name="param_wdata10",description='Param data10 send SNN', reset=0x0, size=32)
        self.param11      = CSRStorage(name="param_wdata11",description='Param data11 send SNN', reset=0x0, size=16)

        self.neuron_inst     = CSRStorage(name="neuron_inst_wdata",description='neuron_inst data send SNN', reset=0x0, size=2)

        self.packet_out_rinc = CSRStorage(name="packet_out_rinc",description='Enable signal read packet out data', reset=0x0, size=1)
        self.packet_out      = CSRStorage(name="packet_out",description='Packet out data', reset=0x0, size=8, write_from_dev=True)
        self.tick_ready      = CSRStorage(name="tick_ready", description="Tick ready", size=1, reset=0x0, write_from_dev=True)
        
        self.snn_status = CSRStatus(size=32, fields=[
            CSRField(name="packet_wfull", description="flag full", size=1, reset=0x0),
            CSRField(name="param_wfull", description="flag full", size=1, reset=0x0),
            CSRField(name="neuron_inst_wfull", description="flag full", size=1, reset=0x0),
            CSRField(name="packet_out_rempty", description="Packet out data is empty", size=1, reset=0x0),
            CSRField(name="token_controller_error", description="Token controller error", size=1, reset=0x0),
            CSRField(name="scheduler_error", description="Scheduler error", size=1, reset=0x0),
            CSRField(name="wait_packets", description="wait for packet to put on snn /Time to read packetout", size=1, reset=0x0)
        ], description="SNN status")

        self.comb += self.param_wdata.eq(Cat(self.param0.storage, 
            self.param1.storage , 
            self.param2.storage , 
            self.param3.storage , 
            self.param4.storage , 
            self.param5.storage , 
            self.param6.storage , 
            self.param7.storage , 
            self.param8.storage , 
            self.param9.storage , 
            self.param10.storage,
            self.param11.storage 
        ))

        self.comb += self.packet_out.we.eq(1)
        self.comb += self.tick_ready.dat_w.eq(1)

        self.specials += Instance(
            "snn_1x1_wrapper"                                                       ,
            i_clk                    = self.clk                                     ,
            i_reset_n                = ~ResetSignal()                               ,
            i_sys_clk                = self.sys_clk                                 ,
            i_sys_reset_n            = ~ResetSignal()                               ,
            i_tick                   = self.tick.re                                 ,
            i_packet_winc            = self.packet.re                               ,
            i_packet_wdata           = self.packet.storage                          ,
            o_packet_wfull           = self.snn_status.fields.packet_wfull          ,
            i_param_winc             = self.param11.re                              ,
            i_param_wdata            = self.param_wdata                             ,
            o_param_wfull            = self.snn_status.fields.param_wfull           ,
            i_neuron_inst_winc       = self.neuron_inst.re                          ,
            i_neuron_inst_wdata      = self.neuron_inst.storage                     ,
            o_neuron_inst_wfull      = self.snn_status.fields.neuron_inst_wfull     ,
            o_packet_out             = self.packet_out.dat_w                        ,
            i_packet_out_rinc        = self.packet_out_rinc.re                      ,
            o_packet_out_rempty      = self.snn_status.fields.packet_out_rempty     ,
            o_token_controller_error = self.snn_status.fields.token_controller_error,
            o_scheduler_error        = self.snn_status.fields.scheduler_error       ,
            o_wait_packets           = self.snn_status.fields.wait_packets          ,
            o_tick_ready             = self.tick_ready.we  
        )

        platform.add_source_dir("../seq_snn/hdl")
        platform.add_source_dir("../seq_snn/libs/async_fifo/hdl")
        platform.add_source_dir("../seq_snn/libs/snn_1x1/hdl")
        platform.add_source_dir("../seq_snn/libs/sync_signal/hdl")


            


