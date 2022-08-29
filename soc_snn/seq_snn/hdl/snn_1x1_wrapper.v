module snn_1x1_wrapper(
    input                    clk                   ,
    input                    reset_n               ,
    input                    sys_clk               ,
    input                    sys_reset_n           ,
    input                    tick                  ,
    input                    packet_winc           ,
    input  [29:0]            packet_wdata          ,
    output                   packet_wfull          ,   
    input                    param_winc            ,
    input  [367:0]           param_wdata           ,
    output                   param_wfull           ,
    input                    neuron_inst_winc      ,
    input  [1:0]             neuron_inst_wdata     ,
    output                   neuron_inst_wfull     ,
    output [7:0]             packet_out            ,
    input                    packet_out_rinc       ,
    output                   packet_out_rempty     ,
    output                   token_controller_error,
    output                   scheduler_error       ,
    output                   wait_packets          ,
    output                   tick_ready                 
	
);
    wire                     param_wen             ;
    wire  [$clog2(256)-1:0]  param_address         ;
    wire  [367:0]            param_data_in         ;

    wire                     neuron_inst_wen       ;
    wire   [$clog2(256)-1:0] neuron_inst_address   ;
    wire   [1:0]             neuron_inst_data_in   ;

    wire                     input_buffer_empty    ;
    wire   [29:0]            packet_in             ;
    wire                     ren_to_input_buffer   ;

    wire                     tick_snn              ;

    wire [7:0]               packet_out_tmp        ;
    wire                     packet_out_valid      ;
    wire                     packet_out_wfull      ;

	RANCNetworkGrid_1x1 RANCNetworkGrid_1x1_ins(
		.clk                   (clk                   ),
		.reset_n               (reset_n               ),
		.tick                  (tick_snn              ),
		.input_buffer_empty    (input_buffer_empty    ),
		.packet_in             (packet_in             ),
		.param_wen             (param_wen             ),
		.param_address         (param_address         ),
		.param_data_in         (param_data_in         ),
		.neuron_inst_wen       (neuron_inst_wen       ),
		.neuron_inst_address   (neuron_inst_address   ),
		.neuron_inst_data_in   (neuron_inst_data_in   ),
		.packet_out            (packet_out_tmp        ),
		.packet_out_valid      (packet_out_valid      ),
		.ren_to_input_buffer   (ren_to_input_buffer   ),
		.token_controller_error(token_controller_error),
		.scheduler_error       (scheduler_error       ),
		.wait_packets          (wait_packets          ),
		.tick_ready            (tick_ready            )
	);

	load_param_fifo #(
		.DSIZE (368)
	) load_param_fifo(
		.wclk     (sys_clk      ),
		.wrst_n   (sys_reset_n  ),
		.winc     (param_winc   ),
		.wdata    (param_wdata  ),
		.wfull    (param_wfull  ),
		.rclk     (clk          ),
		.rrst_n   (reset_n      ),
		.write_en (param_wen    ),
		.address  (param_address),
		.data_in  (param_data_in)
	);

	load_param_fifo #(
		.DSIZE (2)
	) load_neuron_inst_fifo(
		.wclk     (sys_clk            ),
		.wrst_n   (sys_reset_n        ),
		.winc     (neuron_inst_winc   ),
		.wdata    (neuron_inst_wdata  ),
		.wfull    (neuron_inst_wfull  ),
		.rclk     (clk                ),
		.rrst_n   (reset_n            ),
		.write_en (neuron_inst_wen    ),
		.address  (neuron_inst_address),
		.data_in  (neuron_inst_data_in)
	);

	async_fifo #(
		.DSIZE      (30     ), 
		.ASIZE      (8      ),
		.FALLTHROUGH("FALSE")
	) load_packet_fifo(
		.wclk    (sys_clk            ),
		.wrst_n  (sys_reset_n        ),
		.winc    (packet_winc        ),
		.wdata   (packet_wdata       ),
		.wfull   (packet_wfull       ),
		.awfull  (                   ),
		.rclk    (clk                ),
		.rrst_n  (reset_n            ),
		.rinc    (ren_to_input_buffer),
		.rdata   (packet_in          ),
		.rempty  (input_buffer_empty ),
		.arempty ()
	);

	sync_signal sync_tick_signal(
		.clk1      (sys_clk    ),
		.rst_n1    (sys_reset_n),
		.clk2      (clk        ),
		.rst_n2    (reset_n    ),
		.signal_in (tick       ),
		.signal_out(tick_snn   )
	);

	async_fifo #(
		.DSIZE      (8      ), 
		.ASIZE      (8      ),
		.FALLTHROUGH("TRUE")
	) packet_out_fifo(
		.wclk   (clk                                 ),
		.wrst_n (reset_n                             ),
		.winc   (packet_out_valid & ~packet_out_wfull),
		.wdata  (packet_out_tmp                      ),
		.wfull  (packet_out_wfull                    ),
		.awfull (                                    ),
		.rclk   (sys_clk                             ),
		.rrst_n (sys_reset_n                         ),
		.rinc   (packet_out_rinc                     ),
		.rdata  (packet_out                          ),
		.rempty (packet_out_rempty                   ),
		.arempty(                                    )
	);

endmodule