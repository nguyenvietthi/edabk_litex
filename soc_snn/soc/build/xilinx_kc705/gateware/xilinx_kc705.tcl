
# Create Project

create_project -force -name xilinx_kc705 -part xc7k325t-ffg900-2
set_msg_config -id {Common 17-55} -new_severity {Warning}

# Add Sources

read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/hdl/load_param_fifo.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/hdl/snn_1x1_wrapper.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/async_fifo.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/rptr_empty.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/sync_ptr.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/sync_r2w.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/sync_w2r.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/wptr_full.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/async_fifo/hdl/fifomem.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/neuron_grid_controller.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/neuron_grid_1x1.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/neuron_block.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/buffer.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/SchedulerSRAM.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Scheduler.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Router.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/RANCNetworkGrid_1x1.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/PathDecoder3Way.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/PathDecoder2Way.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/OutputBus.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Merge3.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Merge2.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/LocalIn.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/FromLocal.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/ForwardNorthSouth.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/ForwardEastWest.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Counter.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/Core_1x1.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/snn_1x1/hdl/neuron_grid_datapath_1x1.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/seq_snn/libs/sync_signal/hdl/sync_signal.v}
read_verilog {/home/thinv0/litex/pythondata-cpu-vexriscv/pythondata_cpu_vexriscv/verilog/VexRiscv.v}
read_verilog {/home/thinv0/edabk_litex/soc_snn/soc/build/xilinx_kc705/gateware/xilinx_kc705.v}

# Add EDIFs


# Add IPs


# Add constraints

read_xdc xilinx_kc705.xdc
set_property PROCESSING_ORDER EARLY [get_files xilinx_kc705.xdc]

# Add pre-synthesis commands


# Synthesis

synth_design -directive default -top xilinx_kc705 -part xc7k325t-ffg900-2

# Synthesis report

report_timing_summary -file xilinx_kc705_timing_synth.rpt
report_utilization -hierarchical -file xilinx_kc705_utilization_hierarchical_synth.rpt
report_utilization -file xilinx_kc705_utilization_synth.rpt

# Optimize design

opt_design -directive default

# Add pre-placement commands


# Placement

place_design -directive default

# Placement report

report_utilization -hierarchical -file xilinx_kc705_utilization_hierarchical_place.rpt
report_utilization -file xilinx_kc705_utilization_place.rpt
report_io -file xilinx_kc705_io.rpt
report_control_sets -verbose -file xilinx_kc705_control_sets.rpt
report_clock_utilization -file xilinx_kc705_clock_utilization.rpt

# Add pre-routing commands


# Routing

route_design -directive default
phys_opt_design -directive default
write_checkpoint -force xilinx_kc705_route.dcp

# Routing report

report_timing_summary -no_header -no_detailed_paths
report_route_status -file xilinx_kc705_route_status.rpt
report_drc -file xilinx_kc705_drc.rpt
report_timing_summary -datasheet -max_paths 10 -file xilinx_kc705_timing.rpt
report_power -file xilinx_kc705_power.rpt
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]

# Bitstream generation

write_bitstream -force xilinx_kc705.bit 
write_cfgmem -force -format bin -interface spix4 -size 16 -loadbit "up 0x0 xilinx_kc705.bit" -file xilinx_kc705.bin

# End

quit