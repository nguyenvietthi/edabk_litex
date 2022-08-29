module neuron_grid_controller(
    input tick,
    input done_neuron, done_axon,
    input clk,
    input reset_n,
    output reg process_spike,
    output reg scheduler_clr,
    output reg scheduler_set,
    output reg inc_neuron_num, initial_neuron_num,
    output reg initial_axon_num, inc_axon_num,
    output reg new_neuron,
    output reg update_potential,
    output reg done,
    output reg error,
    output     wait_packets
);

localparam IDLE     = 0;
localparam GET_DATA = 1;
localparam INITIAL  = 2;
localparam SPIKE_IN = 3;
localparam UPDATE   = 4;
localparam END      = 5;

reg [2:0] current_state, next_state;

assign wait_packets = current_state == IDLE;

always @(*) begin
    initial_axon_num = 0;
    initial_neuron_num = 0;
    scheduler_set = 0;
    scheduler_clr = 0;
    new_neuron = 0;
    process_spike = 0;
    inc_axon_num = 0;
    update_potential = 0;
    done = 0;
    inc_neuron_num = 0;
    //////
    case(current_state)
    IDLE: begin
        next_state = tick ? GET_DATA : IDLE;
    end
    GET_DATA: begin
        initial_neuron_num = 1;
        scheduler_set = 1;
        next_state = INITIAL;
        new_neuron = 1;
    end
    INITIAL: begin
        initial_axon_num = 1;
        process_spike = 1;
        next_state = SPIKE_IN;
    end
    SPIKE_IN: begin
        process_spike = 1;
        if(done_axon) begin
            next_state = UPDATE;
        end
        else begin
            inc_axon_num = 1;
            next_state = SPIKE_IN;
        end
    end
    UPDATE: begin
        update_potential = 1;
        next_state = END;
    end
    END: begin
        if(done_neuron) begin
            scheduler_clr = 1;
            done = 1;
            next_state = IDLE;
        end
        else begin
            new_neuron = 1;
            inc_neuron_num = 1;
            next_state = INITIAL;
        end
    end
    default: next_state = IDLE;

    endcase
end

always @(posedge clk, negedge reset_n) begin
    if(~reset_n) begin
        current_state <= IDLE;
        error <= 0;
    end
    else begin
        current_state <= next_state;
        if(~error && current_state != IDLE && tick) error <= ~error;
        else error <= error;
    end
end



endmodule