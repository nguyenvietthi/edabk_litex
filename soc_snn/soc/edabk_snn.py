from migen import *

from litex.soc.interconnect.csr import *

from litex.soc.interconnect.csr_eventmanager import *

from litex.soc.integration.doc import AutoDoc, ModuleDoc

class edabk_snn(Module, AutoCSR, AutoDoc):
    def __init__(self, platform):
        self.intro = ModuleDoc(""" EDABK SNN""")

        self.clk          = Signal()
        self.sys_clk      = Signal()
        self.tick         = CSRStorage(name="tick",description='Send tick to SNN', reset=0x0, size=1)
        
        self.packet       = CSRStorage(name="packet_wdata",description='Packet data send SNN', reset=0x0, size=30)
        self.packet_wfull = CSRStatus(name="packet_wfull", description="flag full", size=1, reset=0x0)

        self.param       = CSRStorage(name="param_wdata",description='param data send SNN', reset=0x0, size=368)
        self.param_wfull = CSRStatus(name="param_wfull", description="flag full", size=1, reset=0x0)

        self.neuron_inst       = CSRStorage(name="neuron_inst_wdata",description='neuron_inst data send SNN', reset=0x0, size=2)
        self.neuron_inst_wfull = CSRStatus(name="neuron_inst_wfull", description="flag full", size=1, reset=0x0)

        self.packet_out_rinc   = CSRStorage(name="packet_out_rinc",description='Enable signal read packet out data', reset=0x0, size=1)
        self.packet_out        = CSRStorage(name="packet_out",description='Packet out data', reset=0x0, size=8, write_from_dev=True)
        self.packet_out_rempty = CSRStatus(name="packet_out_rempty", description="Packet out data is empty", size=1, reset=0x0)

        self.token_controller_error = CSRStatus(name="token_controller_error", description="Token controller error", size=1, reset=0x0)
        self.scheduler_error        = CSRStatus(name="scheduler_error", description="Scheduler error", size=1, reset=0x0)
        self.wait_packets           = CSRStatus(name="wait_packets", description="wait for packet to put on snn /Time to read packetout", size=1, reset=0x0)
        self.tick_ready             = CSRStatus(name="tick_ready", description="Tick ready", size=1, reset=0x0)

        self.specials += Instance(
            "edabk_snn_ins"                                              ,
            i_clk                    = self.clk                          ,
            i_reset_n                = ResetSignal()                     ,
            i_sys_clk                = self.sys_clk                      ,
            i_sys_reset_n            = ResetSignal()                     ,
            i_tick                   = self.tick.re                      ,
            i_packet_winc            = self.packet.re                    ,
            i_packet_wdata           = self.packet.storage               ,
            o_packet_wfull           = self.packet_wfull.status          ,
            i_param_winc             = self.param.re                     ,
            i_param_wdata            = self.param.storage                ,
            o_param_wfull            = self.param_wfull.status           ,
            i_neuron_inst_winc       = self.neuron_inst.re               ,
            i_neuron_inst_wdata      = self.neuron_inst.storage          ,
            o_neuron_inst_wfull      = self.neuron_inst_wfull.status     ,
            o_packet_out             = self.packet_out.dat_w             ,
            i_packet_out_rinc        = self.packet_out_rinc.re           ,
            o_packet_out_rempty      = self.packet_out_rempty.status     ,
            o_token_controller_error = self.token_controller_error.status,
            o_scheduler_error        = self.scheduler_error.status       ,
            o_wait_packets           = self.wait_packets.status          ,
            o_tick_ready             = self.tick_ready.status             
        )

        platform.add_source_dir("../seq_snn/hdl")
        platform.add_source_dir("../seq_snn/libs/async_fifo/hdl")
        platform.add_source_dir("../seq_snn/libs/snn_1x1/hdl")
        platform.add_source_dir("../seq_snn/libs/sync_signal/hdl")


            


