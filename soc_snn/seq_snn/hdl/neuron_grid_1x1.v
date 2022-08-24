module neuron_grid_1x1 #(
    parameter CORE_NUMBER = 0
)(
    input local_buffers_full,
    input clk,
    input reset_n,
    input tick,
    input [255:0] axon_spikes,
    output error,
    output scheduler_set,
    output scheduler_clr,
    output done,
    output [29:0] packet_out,
    output spike_out_valid
);


neuron_grid_controller controller(
    .tick(tick),
    .done_neuron(done_neuron), .done_axon(done_axon),
    .clk(clk),
    .reset_n(reset_n),
    .process_spike(process_spike),
    .scheduler_clr(scheduler_clr),
    .scheduler_set(scheduler_set),
    .inc_neuron_num(inc_neuron_num),
    .initial_neuron_num(initial_neuron_num),
    .initial_axon_num(initial_axon_num),
    .inc_axon_num(inc_axon_num),
    .new_neuron(new_neuron),
    .update_potential(update_potential),
    .done(done),
    .error(error)
);

neuron_grid_datapath_1x1 #(
    .CORE_NUMBER(CORE_NUMBER)
) datapath(
    .local_buffers_full(local_buffers_full),
    .axon_spikes(axon_spikes),
    .clk(clk),
    .reset_n(reset_n),
    .initial_axon_num(initial_axon_num),
    .inc_axon_num(inc_axon_num),
    .initial_neuron_num(initial_neuron_num),
    .inc_neuron_num(inc_neuron_num),
    .new_neuron(new_neuron),
    .process_spike(process_spike),
    .done_neuron(done_neuron),
    .done_axon(done_axon),
    .packet_out(packet_out),
    .spike_out_valid(spike_out_valid),
    .update_potential(update_potential)
);

endmodule

