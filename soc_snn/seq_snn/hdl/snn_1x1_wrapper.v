module snn_1x1_wrapper(
    input                    clk                   ,
    input                    reset_n               ,
    input                    sys_clk               ,
    input                    sys_reset_n           ,
    input                    tick                  ,
    input                    input_buffer_empty    ,
    input  [29:0]            packet_in             ,
    input                    param_winc            ,
    input  [367:0]           param_wdata           ,
    output                   param_wfull           ,
    input                    neuron_inst_winc      ,
    input  [1:0]             neuron_inst_wdata     ,
    output                   neuron_inst_wfull     ,
    output [7:0]             packet_out            ,
    output                   packet_out_valid      ,
    output                   ren_to_input_buffer   ,
    output                   token_controller_error,
    output                   scheduler_error       
	
);
    wire                     param_wen             ;
    wire  [$clog2(256)-1:0]  param_address         ;
    wire  [367:0]            param_data_in         ;

    wire                     neuron_inst_wen       ;
    wire   [$clog2(256)-1:0] neuron_inst_address   ;
    wire   [1:0]             neuron_inst_data_in   ;

	RANCNetworkGrid_1x1 RANCNetworkGrid_1x1_ins(
		.clk                   (clk                   ),
		.reset_n               (reset_n               ),
		.tick                  (tick                  ),
		.input_buffer_empty    (input_buffer_empty    ),
		.packet_in             (packet_in             ),
		.param_wen             (param_wen             ),
		.param_address         (param_address         ),
		.param_data_in         (param_data_in         ),
		.neuron_inst_wen       (neuron_inst_wen       ),
		.neuron_inst_address   (neuron_inst_address   ),
		.neuron_inst_data_in   (neuron_inst_data_in   ),
		.packet_out            (packet_out            ),
		.packet_out_valid      (packet_out_valid      ),
		.ren_to_input_buffer   (ren_to_input_buffer   ),
		.token_controller_error(token_controller_error),
		.scheduler_error       (scheduler_error       )
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


endmodule