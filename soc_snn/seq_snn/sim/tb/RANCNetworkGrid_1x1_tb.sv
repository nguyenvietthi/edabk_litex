`timescale 1ns/1ps
module RANCNetworkGrid_1x1_tb ();
	parameter NUM_OUTPUT = 250; // Số spike bắn ra
	parameter NUM_PICTURE = 100; // Số ảnh test
	parameter NUM_PACKET = 3058; // số lượng input packet trong file
	
	
	reg clk, reset_n, tick, input_buffer_empty;
	reg [29:0] packet_in;
	wire [7:0] packet_out;
	wire packet_out_valid, ren_to_input_buffer, token_controller_error, scheduler_error;
	
	reg                   param_wen           ;
	reg [$clog2(256)-1:0] param_address       ;
	reg [367:0]           param_data_in       ;
	reg                   neuron_inst_wen     ;
	reg [$clog2(256)-1:0] neuron_inst_address ;
	reg [1:0]             neuron_inst_data_in ;
	
	RANCNetworkGrid_1x1 uut(
	    .clk                    (clk                   ),
	    .reset_n                (reset_n               ),
	    .tick                   (tick                  ),
	    .input_buffer_empty     (input_buffer_empty    ),
	    .packet_in              (packet_in             ),
	    .param_wen              (param_wen             ),
	    .param_address          (param_address         ),
	    .param_data_in          (param_data_in         ),
	    .neuron_inst_wen        (neuron_inst_wen       ),
	    .neuron_inst_address    (neuron_inst_address   ),
	    .neuron_inst_data_in    (neuron_inst_data_in   ),
	    .packet_out             (packet_out            ),
	    .packet_out_valid       (packet_out_valid      ),
	    .ren_to_input_buffer    (ren_to_input_buffer   ),
	    .token_controller_error (token_controller_error),
	    .scheduler_error        (scheduler_error       )
	);
	// đọc số lượng packet trong mỗi tick
	reg [6:0] num_pic [0:NUM_PICTURE - 1];
	initial $readmemh("./../../data/tb_num_inputs.txt", num_pic);
	
	// đọc tất cả các packet
	reg [29:0] packet [0:NUM_PACKET - 1];
	initial $readmemb("./../../data/tb_input.txt", packet);
	
	reg [367:0] neuron_parameter    [0:255];
	reg [1:0]   neuron_instructions [0:255];
	
	initial $readmemb("./../../data/csram.mem", neuron_parameter);
	initial $readmemb("./../../data/neuron_inst.mem", neuron_instructions);
	reg [NUM_OUTPUT - 1:0] output_soft [0:NUM_PICTURE - 1];
	initial $readmemb("./../../data/simulator_output.txt", output_soft);

	initial begin
	    clk = 0;
	    forever #5 clk = ~clk;
	end

	reg [7:0] count_valid;
	int begin_packet_addr;
	reg [NUM_OUTPUT - 1:0] spike_out;
	int pic_index;
	always @(negedge packet_out_valid or posedge tick) begin
		if(tick) begin
			spike_out = 0;
		end else begin
			spike_out[249 - packet_out] = 1'b1;			
		end
	end

	always @(uut.Core0.neuron_grid.controller.current_state ) begin 
		if(uut.Core0.neuron_grid.controller.current_state == 0) begin 
			if(spike_out == output_soft[pic_index]) begin 
				$display("OK %d", pic_index);
			end else begin 
				$display("ERROR %d", pic_index);
			end
			pic_index++;
		end
	end

	initial begin 
		reset_n = 0;
		tick = 0;
		input_buffer_empty = 1;
		param_wen       = 0;
    	neuron_inst_wen = 0;
    	begin_packet_addr = 0;
    	pic_index = -1;
		@(negedge clk); 
		reset_n = 1;
		repeat(10) @(negedge clk);
    	param_wen = 1;

	    for (int i = 0; i < 256; i++) begin
	        @(negedge clk);
	        param_address = i;
	        param_data_in = neuron_parameter[i];
	    end
	
	    @(negedge clk);
	    param_wen       = 0;
	    neuron_inst_wen = 1;
	    for (int i = 0; i < 256; i++) begin
	        @(negedge clk);
	        neuron_inst_address = i;
	        neuron_inst_data_in = neuron_instructions[i];
	    end
	    @(negedge clk);
	    param_wen       = 0;
	    neuron_inst_wen = 0;

	    for (int i = 0; i < NUM_PICTURE; i++) begin
	    	@(posedge clk);
	    	input_buffer_empty = 0;
	    	for (int j = 0; j < num_pic[i]; j++) begin
	    		@(posedge clk);
	    		packet_in = packet[begin_packet_addr + j];
	    		@(posedge clk);
	    	end
	    	input_buffer_empty = 1;
	    	begin_packet_addr = begin_packet_addr + num_pic[i];
			repeat(30) @(posedge clk);
			tick = 1;
			@(posedge clk);
			tick = 0;
	    	repeat(70000) @(posedge clk);
	    end
	    $stop;
	end

endmodule