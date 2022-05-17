################################################################################
# IO constraints
################################################################################
# user_rgb_led_r:0
set_property LOC N16 [get_ports {user_rgb_led_r}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_rgb_led_r}]

# user_rgb_led_g:0
set_property LOC R11 [get_ports {user_rgb_led_g}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_rgb_led_g}]

# user_rgb_led_b:0
set_property LOC G14 [get_ports {user_rgb_led_b}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_rgb_led_b}]

# clk100:0
set_property LOC E3 [get_ports {clk100}]
set_property IOSTANDARD LVCMOS33 [get_ports {clk100}]

################################################################################
# Design constraints
################################################################################

################################################################################
# Clock constraints
################################################################################


create_clock -name clk100 -period 0.01 [get_ports clk100]

################################################################################
# False path constraints
################################################################################


set_false_path -quiet -through [get_nets -hierarchical -filter {mr_ff == TRUE}]

set_false_path -quiet -to [get_pins -filter {REF_PIN_NAME == PRE} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE || ars_ff2 == TRUE}]]

set_max_delay 2 -quiet -from [get_pins -filter {REF_PIN_NAME == C} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE}]] -to [get_pins -filter {REF_PIN_NAME == D} -of_objects [get_cells -hierarchical -filter {ars_ff2 == TRUE}]]