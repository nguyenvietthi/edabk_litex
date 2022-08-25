module snn_1x1_wrapper (
    input                    clk                   ,
    input                    reset_n               ,
    input                    tick                  ,
    input                    input_buffer_empty    ,
    input  [29:0]            packet_in             ,
    input                    param_wen             ,
    input  [$clog2(256)-1:0] param_address         ,
    input  [367:0]           param_data_in         ,
    input                    neuron_inst_wen       ,
    input  [$clog2(256)-1:0] neuron_inst_address   ,
    input  [1:0]             neuron_inst_data_in   ,
    output [7:0]             packet_out            ,
    output                   packet_out_valid      ,
    output                   ren_to_input_buffer   ,
    output                   token_controller_error,
    output                   scheduler_error       
	
);

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

endmodule