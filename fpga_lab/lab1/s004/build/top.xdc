################################################################################
# IO constraints
################################################################################
# user_led:0
set_property LOC H17 [get_ports {user_led0}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led0}]

# user_sw:0
set_property LOC J15 [get_ports {user_sw0}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw0}]

# user_led:1
set_property LOC K15 [get_ports {user_led1}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led1}]

# user_sw:1
set_property LOC L16 [get_ports {user_sw1}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw1}]

# user_led:2
set_property LOC J13 [get_ports {user_led2}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led2}]

# user_sw:2
set_property LOC M13 [get_ports {user_sw2}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw2}]

# user_led:3
set_property LOC N14 [get_ports {user_led3}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led3}]

# user_sw:3
set_property LOC R15 [get_ports {user_sw3}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw3}]

# user_led:4
set_property LOC R18 [get_ports {user_led4}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led4}]

# user_sw:4
set_property LOC R17 [get_ports {user_sw4}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw4}]

# user_led:5
set_property LOC V17 [get_ports {user_led5}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led5}]

# user_sw:5
set_property LOC T18 [get_ports {user_sw5}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw5}]

# user_led:6
set_property LOC U17 [get_ports {user_led6}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led6}]

# user_sw:6
set_property LOC U18 [get_ports {user_sw6}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw6}]

# user_led:7
set_property LOC U16 [get_ports {user_led7}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led7}]

# user_sw:7
set_property LOC R13 [get_ports {user_sw7}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw7}]

# user_led:8
set_property LOC V16 [get_ports {user_led8}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led8}]

# user_sw:8
set_property LOC T8 [get_ports {user_sw8}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw8}]

# user_led:9
set_property LOC T15 [get_ports {user_led9}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led9}]

# user_sw:9
set_property LOC U8 [get_ports {user_sw9}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw9}]

# user_led:10
set_property LOC U14 [get_ports {user_led10}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led10}]

# user_sw:10
set_property LOC R16 [get_ports {user_sw10}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw10}]

# user_led:11
set_property LOC T16 [get_ports {user_led11}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led11}]

# user_sw:11
set_property LOC T13 [get_ports {user_sw11}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw11}]

# user_led:12
set_property LOC V15 [get_ports {user_led12}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led12}]

# user_sw:12
set_property LOC H6 [get_ports {user_sw12}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw12}]

# user_led:13
set_property LOC V14 [get_ports {user_led13}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led13}]

# user_sw:13
set_property LOC U12 [get_ports {user_sw13}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw13}]

# user_led:14
set_property LOC V12 [get_ports {user_led14}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led14}]

# user_sw:14
set_property LOC U11 [get_ports {user_sw14}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw14}]

# user_led:15
set_property LOC V11 [get_ports {user_led15}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_led15}]

# user_sw:15
set_property LOC V10 [get_ports {user_sw15}]
set_property IOSTANDARD LVCMOS33 [get_ports {user_sw15}]

# clk100:0
set_property LOC E3 [get_ports {clk100}]
set_property IOSTANDARD LVCMOS33 [get_ports {clk100}]

################################################################################
# Design constraints
################################################################################

################################################################################
# Clock constraints
################################################################################


create_clock -name clk100 -period 10.0 [get_ports clk100]

################################################################################
# False path constraints
################################################################################


set_false_path -quiet -through [get_nets -hierarchical -filter {mr_ff == TRUE}]

set_false_path -quiet -to [get_pins -filter {REF_PIN_NAME == PRE} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE || ars_ff2 == TRUE}]]

set_max_delay 2 -quiet -from [get_pins -filter {REF_PIN_NAME == C} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE}]] -to [get_pins -filter {REF_PIN_NAME == D} -of_objects [get_cells -hierarchical -filter {ars_ff2 == TRUE}]]