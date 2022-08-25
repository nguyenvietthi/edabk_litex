`timescale 1ns/1ps
//Feed packet đầu mỗi tick
module tb_RANCNetworkGrid_1x1;

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

initial begin
    clk = 0;
    forever #5 clk = ~clk;
end
initial begin
    reset_n = 0; @(negedge clk); reset_n = 1;
end


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


integer i = 0;
integer numline = 0; integer index_end = 0;

/////////////////////////
always@(posedge clk) begin
    if(ren_to_input_buffer) begin
        packet_in <= packet[i + index_end];
        i <= i + 1;
    end
end

always @(negedge clk) begin
    if(numline == NUM_PICTURE) input_buffer_empty <= 1;
    else if(i == num_pic[numline]) begin
        input_buffer_empty <= 1;
    end
    
end

// log spike ra
reg [NUM_OUTPUT - 1:0] spike_out;
always @(packet_out_valid, tick) begin
    if(tick) spike_out = {NUM_OUTPUT{1'b0}};
    if(packet_out_valid) begin
        spike_out[249 - packet_out] = 1'b1;
    end
end


reg [NUM_OUTPUT - 1:0] output_file [0:NUM_PICTURE - 1];
// định nghĩa hoạt động 1 vài tín hiệu và log lại output
initial begin
    input_buffer_empty = 0;
    param_wen       = 0;
    neuron_inst_wen = 0;
    repeat(20) @(negedge clk);
    tick = 0; repeat(51) @(negedge clk);
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

    // for (int i = 0; i < 256; i++) begin
    //     $display("%d: \n",uut.Core0.neuron_grid.datapath.neuron_parameter[i]);
    // end

    tick = 0; repeat(51) @(negedge clk);
    forever begin
        // tick = 1;
        index_end = index_end + i;
        i = 0;
        if(numline >= 1) output_file[numline - 1] = spike_out;
        numline = numline + 1;
        input_buffer_empty = 0;
        repeat(500) @(negedge clk);
        tick = 1;
        @(negedge clk);
        tick = 0;
        repeat(66050) @(negedge clk); //Tần số tick
    end
end

reg finish;
initial finish = 0;
always @(numline) begin
    if(numline == NUM_PICTURE + 1) begin
        repeat(50) @(negedge clk);
        $writememb("./../../data/output.txt", output_file);
        finish = 1;
        #(20);
        $stop;
    end
end

///////compare with output from software////////////////////////////
reg [NUM_OUTPUT - 1:0] output_soft [0:NUM_PICTURE - 1];
reg wrong;
initial wrong = 0;
initial $readmemb("./../../data/simulator_output.txt", output_soft);
integer in, j;
always @(finish) begin
    if(finish) begin
        for(in = 0; in < NUM_PICTURE; in = in + 1) begin
            for(j = 0; j < NUM_OUTPUT; j = j + 1) begin
                if(output_file[in][j] != output_soft[in][j]) begin
                    $display("Error at neuron %d, picture %d", j, in);
                    wrong = 1;
                end
            end
        end
    end
end
always @(finish) begin
    if(finish) begin
        #1; if(~wrong) $display("Test pass without error");
    end
    
end

endmodule

