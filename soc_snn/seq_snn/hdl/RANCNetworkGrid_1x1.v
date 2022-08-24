module RANCNetworkGrid_1x1 (
    input clk,
    input reset_n,
    input tick,
    input input_buffer_empty,
    input [29:0] packet_in,
    output [7:0] packet_out,
    output packet_out_valid,
    output ren_to_input_buffer,
    output token_controller_error,
    output scheduler_error
);

wire [29:0] west_out [0:1];
wire [29:0] east_out [0:1];
wire [20:0] north_out [0:1];
wire [20:0] south_out [0:1];

wire [1:0] ren_out_west, ren_out_east, ren_out_north, ren_out_south;
wire [1:0] empty_out_west, empty_out_east, empty_out_north, empty_out_south;


Core_1x1 #(
    .CORE_NUMBER(0)
)
Core0
(
    .clk(clk), 
    .tick(tick), 
    .reset_n(reset_n), 
    .ren_in_west(1'b0), .ren_in_east(1'b0), .ren_in_north(ren_out_south[1]), .ren_in_south(1'b0),
    .empty_in_west(input_buffer_empty), //
    .empty_in_east(1'b1), .empty_in_north(empty_out_south[1]), .empty_in_south(1'b1),
    .west_in(packet_in),                //
    .east_in({30{1'b0}}), .north_in(south_out[1]), .south_in({21{1'b0}}),
    .ren_out_west(ren_to_input_buffer), //
    .ren_out_east(ren_out_east[0]), .ren_out_north(ren_out_north[0]), .ren_out_south(ren_out_south[0]),
    .empty_out_west(empty_out_west[0]), .empty_out_east(empty_out_east[0]), .empty_out_north(empty_out_north[0]), .empty_out_south(empty_out_south[0]),
    .east_out(east_out[0]), .west_out(west_out[0]), .north_out(north_out[0]), .south_out(south_out[0]),
    .token_controller_error(token_controller_error), .scheduler_error(scheduler_error)
);

OutputBus #(
    .NUM_OUTPUTS(250)
) OutputBus(
    .clk(clk),
    .reset_n(reset_n), 
    .ren_in_west(1'b1), .ren_in_east(1'b1), .ren_in_north(1'b1), .ren_in_south(ren_out_north[0]),
    .empty_in_west(1'b1), //
    .empty_in_east(1'b1), .empty_in_north(1'b1), .empty_in_south(empty_out_north[0]),
    .west_in({30{1'b0}}),                //
    .east_in({30{1'b0}}), .north_in({21{1'b0}}), .south_in(north_out[0]),
    .ren_out_west(ren_out_west[1]), //
    .ren_out_east(ren_out_east[1]), .ren_out_north(ren_out_north[1]), .ren_out_south(ren_out_south[1]),
    .empty_out_west(empty_out_west[1]), .empty_out_east(empty_out_east[1]), .empty_out_north(empty_out_north[1]), .empty_out_south(empty_out_south[1]),
    .east_out(east_out[1]), .west_out(west_out[1]), .north_out(north_out[1]), .south_out(south_out[1]),
    .packet_out(packet_out),
    .packet_out_valid(packet_out_valid),
    .token_controller_error(token_controller_error_output), .scheduler_error(scheduler_error_output)
);
    
endmodule