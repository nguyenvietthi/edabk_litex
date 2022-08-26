`timescale 1ns/1ps
module RANCNetworkGrid_1x1_tb ();
	parameter NUM_OUTPUT = 250; // Số spike bắn ra
	parameter NUM_PICTURE = 100; // Số ảnh test
	parameter NUM_PACKET = 3058; // số lượng input packet trong file
	
	
	reg clk, sys_clk, reset_n, tick, input_buffer_empty;
	reg [29:0] packet_in;
	wire [7:0] packet_out;
	wire packet_out_valid, ren_to_input_buffer, token_controller_error, scheduler_error;
	
	reg                   param_winc        ;
	reg [367:0]           param_wdata       ;
	wire                  param_wfull       ;

	reg                   neuron_inst_winc ;
	reg [1:0]             neuron_inst_wdata;
	wire                  neuron_inst_wfull;

	reg                   packet_winc           ;
    reg [29:0]            packet_wdata          ;
    wire                  packet_wfull          ;   
	
	snn_1x1_wrapper uut(
		.clk                   (clk                   ),
		.reset_n               (reset_n               ),
		.sys_clk               (sys_clk               ),
		.sys_reset_n           (reset_n               ),
		.tick                  (tick                  ),
		.packet_winc           (packet_winc           ),
		.packet_wdata          (packet_wdata          ),
		.packet_wfull          (packet_wfull          ),
		.param_winc            (param_winc            ),
		.param_wdata           (param_wdata           ),
		.param_wfull           (param_wfull           ),
		.neuron_inst_winc      (neuron_inst_winc      ),
		.neuron_inst_wdata     (neuron_inst_wdata     ),
		.neuron_inst_wfull     (neuron_inst_wfull     ),
		.packet_out            (packet_out            ),
		.packet_out_valid      (packet_out_valid      ),
		.token_controller_error(token_controller_error),
		.scheduler_error       (scheduler_error       )
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

	initial begin
	    sys_clk = 0;
	    forever #1 sys_clk = ~sys_clk;
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

	always @(uut.RANCNetworkGrid_1x1_ins.Core0.neuron_grid.controller.current_state ) begin 
		if(uut.RANCNetworkGrid_1x1_ins.Core0.neuron_grid.controller.current_state == 0) begin 
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
    	begin_packet_addr = 0;
    	pic_index = -1;
    	param_winc = 0;
    	neuron_inst_winc = 0;
    	packet_winc = 0;
		@(negedge clk); 
		reset_n = 1;
		repeat(10) @(negedge clk);

	    for (int i = 0; i < 256; i++) begin
	        @(negedge sys_clk);
	        // param_address = i;
	        param_wdata = neuron_parameter[i];
	        param_winc = 1;
	        @(negedge sys_clk);
	        param_winc = 0;
	    end

	    repeat(250) @(negedge clk);
		for (int i = 0; i < 256; i++) begin
	        $display("param %d: %d", i, uut.RANCNetworkGrid_1x1_ins.Core0.neuron_grid.datapath.neuron_parameter[i]);
	    end

	    for (int i = 0; i < 256; i++) begin
	        @(negedge sys_clk);
	        neuron_inst_wdata = neuron_instructions[i];
	        neuron_inst_winc = 1;
	        @(negedge sys_clk);
	        neuron_inst_winc = 0;
	    end

	    repeat(250) @(negedge clk);
		for (int i = 0; i < 256; i++) begin
	        $display("inst %d: %d", i, uut.RANCNetworkGrid_1x1_ins.Core0.neuron_grid.datapath.neuron_instructions[i]);
	    end
	
	    repeat(20) @(negedge clk);

	    for (int i = 0; i < NUM_PICTURE; i++) begin
	    	@(posedge clk);
	    	// input_buffer_empty = 0;
	    	for (int j = 0; j < num_pic[i]; j++) begin
	    		@(negedge sys_clk);
	        	packet_wdata = packet[begin_packet_addr + j];
	        	packet_winc = 1;
	        	@(negedge sys_clk);
	        	packet_winc = 0;
	    	end
	    	// input_buffer_empty = 1;
	    	begin_packet_addr = begin_packet_addr + num_pic[i];
			repeat(1000) @(posedge sys_clk);
			tick = 1;
			@(posedge sys_clk);
			tick = 0;
	    	repeat(70000) @(posedge clk);
	    end
	    $stop;
	end

endmodule