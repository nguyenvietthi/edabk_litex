//////////////////////////////////////////////////////////////////////////////////
// Core.v
//
// Created for Dr. Akoglu's Reconfigurable Computing Lab
//  at the University of Arizona
// 
// Contains all the modules for a single RANC core.
//////////////////////////////////////////////////////////////////////////////////

module Core_1x1 #(
    parameter CORE_NUMBER     = 0
)(
    input clk,
    input tick,
    input reset_n,
    input ren_in_west,
    input ren_in_east,
    input ren_in_north,
    input ren_in_south,
    input empty_in_west,
    input empty_in_east,
    input empty_in_north,
    input empty_in_south,
    input [29:0] east_in,
    input [29:0] west_in,
    input [20:0] north_in,
    input [20:0] south_in,
    input                   param_wen          ,
    input [$clog2(256)-1:0] param_address      ,
    input [367:0]           param_data_in      ,
    input                   neuron_inst_wen    ,
    input [$clog2(256)-1:0] neuron_inst_address,
    input [1:0]             neuron_inst_data_in,
    output ren_out_west,
    output ren_out_east,
    output ren_out_north,
    output ren_out_south,
    output empty_out_west,
    output empty_out_east,
    output empty_out_north,
    output empty_out_south,
    output [29:0] east_out,
    output [29:0] west_out,
    output [20:0] north_out,
    output [20:0] south_out,
    output token_controller_error,
    output scheduler_error, 
    output     wait_packets,
    output reg tick_ready                  
);
    
    wire [255:0] axon_spikes;
    wire [29:0]  spike_out_packet;
    wire [11:0]  scheduler_packet;
    wire         scheduler_wen;

    reg [7:0] packet_count;
    reg [7:0] packet_to_router_count;

    always @(negedge clk or negedge reset_n) begin
        if(~reset_n) begin
            packet_count <= 0;
        end else if(ren_out_west) begin 
            packet_count <= packet_count + 1;
        end else if (tick_ready) begin
            packet_count <= 0;
        end
    end

    always @(negedge clk or negedge reset_n) begin
        if(~reset_n) begin
            packet_to_router_count <= 0;
        end else if (scheduler_wen) begin
            packet_to_router_count <= packet_to_router_count +1;
        end else if (tick_ready) begin
            packet_to_router_count <= 0;
        end
    end

    always @(negedge clk or negedge reset_n) begin
        if(~reset_n) begin
            tick_ready <= 0;
        end else if (packet_to_router_count == packet_count && packet_to_router_count != 0) begin
            tick_ready <= 1;
        end else if (tick_ready) begin
            tick_ready <= 0;
        end
    end
    
Scheduler Scheduler (
    .clk(clk),
    .reset_n(reset_n),
    .wen(scheduler_wen),
    .set(scheduler_set),
    .packet(scheduler_packet),
    .axon_spikes(axon_spikes),
    .error(scheduler_error),
    .clr(scheduler_clr)
);

neuron_grid_1x1 #(
    .CORE_NUMBER(CORE_NUMBER)
)
neuron_grid(
    .local_buffers_full(local_buffers_full),
    .clk(clk),
    .reset_n(reset_n),
    .tick(tick),
    .axon_spikes(axon_spikes),
    .error(token_controller_error),
    .scheduler_set(scheduler_set),
    .scheduler_clr(scheduler_clr),
    .done(done),
    .packet_out(spike_out_packet),
    .spike_out_valid(spike_out_valid),
    .param_wen           (param_wen          ),
    .param_address       (param_address      ),
    .param_data_in       (param_data_in      ),
    .neuron_inst_wen     (neuron_inst_wen    ),
    .neuron_inst_address (neuron_inst_address),
    .neuron_inst_data_in (neuron_inst_data_in), 
    .wait_packets (wait_packets)
);


Router Router (
    .clk(clk),
    .reset_n(reset_n),
    .din_local(spike_out_packet),
    .din_local_wen(spike_out_valid),
    .din_west(west_in),
    .din_east(east_in),
    .din_north(north_in),
    .din_south(south_in),
    .ren_in_west(ren_in_west),
    .ren_in_east(ren_in_east),
    .ren_in_north(ren_in_north),
    .ren_in_south(ren_in_south),
    .empty_in_west(empty_in_west),
    .empty_in_east(empty_in_east),
    .empty_in_north(empty_in_north),
    .empty_in_south(empty_in_south),
    .dout_west(west_out),
    .dout_east(east_out),
    .dout_north(north_out),
    .dout_south(south_out),
    .dout_local(scheduler_packet),
    .dout_wen_local(scheduler_wen),
    .ren_out_west(ren_out_west),
    .ren_out_east(ren_out_east),
    .ren_out_north(ren_out_north),
    .ren_out_south(ren_out_south),
    .empty_out_west(empty_out_west),
    .empty_out_east(empty_out_east),
    .empty_out_north(empty_out_north),
    .empty_out_south(empty_out_south),
    .local_buffers_full(local_buffers_full)
);

endmodule
