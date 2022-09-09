################################################################################
# IO constraints
################################################################################
# cpu_reset:0
set_property LOC AB7 [get_ports {cpu_reset}]
set_property IOSTANDARD LVCMOS15 [get_ports {cpu_reset}]

# clk200:0.p
set_property LOC AD12 [get_ports {clk200_p}]
set_property IOSTANDARD LVDS [get_ports {clk200_p}]

# clk200:0.n
set_property LOC AD11 [get_ports {clk200_n}]
set_property IOSTANDARD LVDS [get_ports {clk200_n}]

# serial:0.cts
set_property LOC L27 [get_ports {serial_cts}]
set_property IOSTANDARD LVCMOS25 [get_ports {serial_cts}]

# serial:0.rts
set_property LOC K23 [get_ports {serial_rts}]
set_property IOSTANDARD LVCMOS25 [get_ports {serial_rts}]

# serial:0.tx
set_property LOC K24 [get_ports {serial_tx}]
set_property IOSTANDARD LVCMOS25 [get_ports {serial_tx}]

# serial:0.rx
set_property LOC M19 [get_ports {serial_rx}]
set_property IOSTANDARD LVCMOS25 [get_ports {serial_rx}]

# sdcard:0.clk
set_property LOC AB23 [get_ports {sdcard_clk}]
set_property SLEW FAST [get_ports {sdcard_clk}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_clk}]

# sdcard:0.cmd
set_property LOC AB22 [get_ports {sdcard_cmd}]
set_property SLEW FAST [get_ports {sdcard_cmd}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_cmd}]
set_property PULLUP True [get_ports {sdcard_cmd}]

# sdcard:0.data
set_property LOC AC20 [get_ports {sdcard_data[0]}]
set_property SLEW FAST [get_ports {sdcard_data[0]}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_data[0]}]
set_property PULLUP True [get_ports {sdcard_data[0]}]

# sdcard:0.data
set_property LOC AA23 [get_ports {sdcard_data[1]}]
set_property SLEW FAST [get_ports {sdcard_data[1]}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_data[1]}]
set_property PULLUP True [get_ports {sdcard_data[1]}]

# sdcard:0.data
set_property LOC AA22 [get_ports {sdcard_data[2]}]
set_property SLEW FAST [get_ports {sdcard_data[2]}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_data[2]}]
set_property PULLUP True [get_ports {sdcard_data[2]}]

# sdcard:0.data
set_property LOC AC21 [get_ports {sdcard_data[3]}]
set_property SLEW FAST [get_ports {sdcard_data[3]}]
set_property IOSTANDARD LVCMOS25 [get_ports {sdcard_data[3]}]
set_property PULLUP True [get_ports {sdcard_data[3]}]

# ddram:0.a
set_property LOC AH12 [get_ports {ddram_a[0]}]
set_property SLEW FAST [get_ports {ddram_a[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[0]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[0]}]

# ddram:0.a
set_property LOC AG13 [get_ports {ddram_a[1]}]
set_property SLEW FAST [get_ports {ddram_a[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[1]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[1]}]

# ddram:0.a
set_property LOC AG12 [get_ports {ddram_a[2]}]
set_property SLEW FAST [get_ports {ddram_a[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[2]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[2]}]

# ddram:0.a
set_property LOC AF12 [get_ports {ddram_a[3]}]
set_property SLEW FAST [get_ports {ddram_a[3]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[3]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[3]}]

# ddram:0.a
set_property LOC AJ12 [get_ports {ddram_a[4]}]
set_property SLEW FAST [get_ports {ddram_a[4]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[4]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[4]}]

# ddram:0.a
set_property LOC AJ13 [get_ports {ddram_a[5]}]
set_property SLEW FAST [get_ports {ddram_a[5]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[5]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[5]}]

# ddram:0.a
set_property LOC AJ14 [get_ports {ddram_a[6]}]
set_property SLEW FAST [get_ports {ddram_a[6]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[6]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[6]}]

# ddram:0.a
set_property LOC AH14 [get_ports {ddram_a[7]}]
set_property SLEW FAST [get_ports {ddram_a[7]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[7]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[7]}]

# ddram:0.a
set_property LOC AK13 [get_ports {ddram_a[8]}]
set_property SLEW FAST [get_ports {ddram_a[8]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[8]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[8]}]

# ddram:0.a
set_property LOC AK14 [get_ports {ddram_a[9]}]
set_property SLEW FAST [get_ports {ddram_a[9]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[9]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[9]}]

# ddram:0.a
set_property LOC AF13 [get_ports {ddram_a[10]}]
set_property SLEW FAST [get_ports {ddram_a[10]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[10]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[10]}]

# ddram:0.a
set_property LOC AE13 [get_ports {ddram_a[11]}]
set_property SLEW FAST [get_ports {ddram_a[11]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[11]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[11]}]

# ddram:0.a
set_property LOC AJ11 [get_ports {ddram_a[12]}]
set_property SLEW FAST [get_ports {ddram_a[12]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[12]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[12]}]

# ddram:0.a
set_property LOC AH11 [get_ports {ddram_a[13]}]
set_property SLEW FAST [get_ports {ddram_a[13]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[13]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[13]}]

# ddram:0.a
set_property LOC AK10 [get_ports {ddram_a[14]}]
set_property SLEW FAST [get_ports {ddram_a[14]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[14]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[14]}]

# ddram:0.a
set_property LOC AK11 [get_ports {ddram_a[15]}]
set_property SLEW FAST [get_ports {ddram_a[15]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_a[15]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_a[15]}]

# ddram:0.ba
set_property LOC AH9 [get_ports {ddram_ba[0]}]
set_property SLEW FAST [get_ports {ddram_ba[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_ba[0]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_ba[0]}]

# ddram:0.ba
set_property LOC AG9 [get_ports {ddram_ba[1]}]
set_property SLEW FAST [get_ports {ddram_ba[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_ba[1]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_ba[1]}]

# ddram:0.ba
set_property LOC AK9 [get_ports {ddram_ba[2]}]
set_property SLEW FAST [get_ports {ddram_ba[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_ba[2]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_ba[2]}]

# ddram:0.ras_n
set_property LOC AD9 [get_ports {ddram_ras_n}]
set_property SLEW FAST [get_ports {ddram_ras_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_ras_n}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_ras_n}]

# ddram:0.cas_n
set_property LOC AC11 [get_ports {ddram_cas_n}]
set_property SLEW FAST [get_ports {ddram_cas_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_cas_n}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_cas_n}]

# ddram:0.we_n
set_property LOC AE9 [get_ports {ddram_we_n}]
set_property SLEW FAST [get_ports {ddram_we_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_we_n}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_we_n}]

# ddram:0.cs_n
set_property LOC AC12 [get_ports {ddram_cs_n}]
set_property SLEW FAST [get_ports {ddram_cs_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_cs_n}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_cs_n}]

# ddram:0.dm
set_property LOC Y16 [get_ports {ddram_dm[0]}]
set_property SLEW FAST [get_ports {ddram_dm[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[0]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[0]}]

# ddram:0.dm
set_property LOC AB17 [get_ports {ddram_dm[1]}]
set_property SLEW FAST [get_ports {ddram_dm[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[1]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[1]}]

# ddram:0.dm
set_property LOC AF17 [get_ports {ddram_dm[2]}]
set_property SLEW FAST [get_ports {ddram_dm[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[2]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[2]}]

# ddram:0.dm
set_property LOC AE16 [get_ports {ddram_dm[3]}]
set_property SLEW FAST [get_ports {ddram_dm[3]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[3]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[3]}]

# ddram:0.dm
set_property LOC AK5 [get_ports {ddram_dm[4]}]
set_property SLEW FAST [get_ports {ddram_dm[4]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[4]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[4]}]

# ddram:0.dm
set_property LOC AJ3 [get_ports {ddram_dm[5]}]
set_property SLEW FAST [get_ports {ddram_dm[5]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[5]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[5]}]

# ddram:0.dm
set_property LOC AF6 [get_ports {ddram_dm[6]}]
set_property SLEW FAST [get_ports {ddram_dm[6]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[6]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[6]}]

# ddram:0.dm
set_property LOC AC7 [get_ports {ddram_dm[7]}]
set_property SLEW FAST [get_ports {ddram_dm[7]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dm[7]}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_dm[7]}]

# ddram:0.dq
set_property LOC AA15 [get_ports {ddram_dq[0]}]
set_property SLEW FAST [get_ports {ddram_dq[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[0]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[0]}]

# ddram:0.dq
set_property LOC AA16 [get_ports {ddram_dq[1]}]
set_property SLEW FAST [get_ports {ddram_dq[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[1]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[1]}]

# ddram:0.dq
set_property LOC AC14 [get_ports {ddram_dq[2]}]
set_property SLEW FAST [get_ports {ddram_dq[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[2]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[2]}]

# ddram:0.dq
set_property LOC AD14 [get_ports {ddram_dq[3]}]
set_property SLEW FAST [get_ports {ddram_dq[3]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[3]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[3]}]

# ddram:0.dq
set_property LOC AA17 [get_ports {ddram_dq[4]}]
set_property SLEW FAST [get_ports {ddram_dq[4]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[4]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[4]}]

# ddram:0.dq
set_property LOC AB15 [get_ports {ddram_dq[5]}]
set_property SLEW FAST [get_ports {ddram_dq[5]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[5]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[5]}]

# ddram:0.dq
set_property LOC AE15 [get_ports {ddram_dq[6]}]
set_property SLEW FAST [get_ports {ddram_dq[6]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[6]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[6]}]

# ddram:0.dq
set_property LOC Y15 [get_ports {ddram_dq[7]}]
set_property SLEW FAST [get_ports {ddram_dq[7]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[7]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[7]}]

# ddram:0.dq
set_property LOC AB19 [get_ports {ddram_dq[8]}]
set_property SLEW FAST [get_ports {ddram_dq[8]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[8]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[8]}]

# ddram:0.dq
set_property LOC AD16 [get_ports {ddram_dq[9]}]
set_property SLEW FAST [get_ports {ddram_dq[9]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[9]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[9]}]

# ddram:0.dq
set_property LOC AC19 [get_ports {ddram_dq[10]}]
set_property SLEW FAST [get_ports {ddram_dq[10]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[10]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[10]}]

# ddram:0.dq
set_property LOC AD17 [get_ports {ddram_dq[11]}]
set_property SLEW FAST [get_ports {ddram_dq[11]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[11]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[11]}]

# ddram:0.dq
set_property LOC AA18 [get_ports {ddram_dq[12]}]
set_property SLEW FAST [get_ports {ddram_dq[12]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[12]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[12]}]

# ddram:0.dq
set_property LOC AB18 [get_ports {ddram_dq[13]}]
set_property SLEW FAST [get_ports {ddram_dq[13]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[13]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[13]}]

# ddram:0.dq
set_property LOC AE18 [get_ports {ddram_dq[14]}]
set_property SLEW FAST [get_ports {ddram_dq[14]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[14]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[14]}]

# ddram:0.dq
set_property LOC AD18 [get_ports {ddram_dq[15]}]
set_property SLEW FAST [get_ports {ddram_dq[15]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[15]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[15]}]

# ddram:0.dq
set_property LOC AG19 [get_ports {ddram_dq[16]}]
set_property SLEW FAST [get_ports {ddram_dq[16]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[16]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[16]}]

# ddram:0.dq
set_property LOC AK19 [get_ports {ddram_dq[17]}]
set_property SLEW FAST [get_ports {ddram_dq[17]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[17]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[17]}]

# ddram:0.dq
set_property LOC AG18 [get_ports {ddram_dq[18]}]
set_property SLEW FAST [get_ports {ddram_dq[18]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[18]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[18]}]

# ddram:0.dq
set_property LOC AF18 [get_ports {ddram_dq[19]}]
set_property SLEW FAST [get_ports {ddram_dq[19]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[19]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[19]}]

# ddram:0.dq
set_property LOC AH19 [get_ports {ddram_dq[20]}]
set_property SLEW FAST [get_ports {ddram_dq[20]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[20]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[20]}]

# ddram:0.dq
set_property LOC AJ19 [get_ports {ddram_dq[21]}]
set_property SLEW FAST [get_ports {ddram_dq[21]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[21]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[21]}]

# ddram:0.dq
set_property LOC AE19 [get_ports {ddram_dq[22]}]
set_property SLEW FAST [get_ports {ddram_dq[22]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[22]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[22]}]

# ddram:0.dq
set_property LOC AD19 [get_ports {ddram_dq[23]}]
set_property SLEW FAST [get_ports {ddram_dq[23]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[23]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[23]}]

# ddram:0.dq
set_property LOC AK16 [get_ports {ddram_dq[24]}]
set_property SLEW FAST [get_ports {ddram_dq[24]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[24]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[24]}]

# ddram:0.dq
set_property LOC AJ17 [get_ports {ddram_dq[25]}]
set_property SLEW FAST [get_ports {ddram_dq[25]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[25]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[25]}]

# ddram:0.dq
set_property LOC AG15 [get_ports {ddram_dq[26]}]
set_property SLEW FAST [get_ports {ddram_dq[26]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[26]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[26]}]

# ddram:0.dq
set_property LOC AF15 [get_ports {ddram_dq[27]}]
set_property SLEW FAST [get_ports {ddram_dq[27]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[27]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[27]}]

# ddram:0.dq
set_property LOC AH17 [get_ports {ddram_dq[28]}]
set_property SLEW FAST [get_ports {ddram_dq[28]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[28]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[28]}]

# ddram:0.dq
set_property LOC AG14 [get_ports {ddram_dq[29]}]
set_property SLEW FAST [get_ports {ddram_dq[29]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[29]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[29]}]

# ddram:0.dq
set_property LOC AH15 [get_ports {ddram_dq[30]}]
set_property SLEW FAST [get_ports {ddram_dq[30]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[30]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[30]}]

# ddram:0.dq
set_property LOC AK15 [get_ports {ddram_dq[31]}]
set_property SLEW FAST [get_ports {ddram_dq[31]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[31]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[31]}]

# ddram:0.dq
set_property LOC AK8 [get_ports {ddram_dq[32]}]
set_property SLEW FAST [get_ports {ddram_dq[32]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[32]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[32]}]

# ddram:0.dq
set_property LOC AK6 [get_ports {ddram_dq[33]}]
set_property SLEW FAST [get_ports {ddram_dq[33]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[33]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[33]}]

# ddram:0.dq
set_property LOC AG7 [get_ports {ddram_dq[34]}]
set_property SLEW FAST [get_ports {ddram_dq[34]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[34]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[34]}]

# ddram:0.dq
set_property LOC AF7 [get_ports {ddram_dq[35]}]
set_property SLEW FAST [get_ports {ddram_dq[35]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[35]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[35]}]

# ddram:0.dq
set_property LOC AF8 [get_ports {ddram_dq[36]}]
set_property SLEW FAST [get_ports {ddram_dq[36]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[36]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[36]}]

# ddram:0.dq
set_property LOC AK4 [get_ports {ddram_dq[37]}]
set_property SLEW FAST [get_ports {ddram_dq[37]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[37]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[37]}]

# ddram:0.dq
set_property LOC AJ8 [get_ports {ddram_dq[38]}]
set_property SLEW FAST [get_ports {ddram_dq[38]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[38]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[38]}]

# ddram:0.dq
set_property LOC AJ6 [get_ports {ddram_dq[39]}]
set_property SLEW FAST [get_ports {ddram_dq[39]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[39]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[39]}]

# ddram:0.dq
set_property LOC AH5 [get_ports {ddram_dq[40]}]
set_property SLEW FAST [get_ports {ddram_dq[40]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[40]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[40]}]

# ddram:0.dq
set_property LOC AH6 [get_ports {ddram_dq[41]}]
set_property SLEW FAST [get_ports {ddram_dq[41]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[41]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[41]}]

# ddram:0.dq
set_property LOC AJ2 [get_ports {ddram_dq[42]}]
set_property SLEW FAST [get_ports {ddram_dq[42]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[42]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[42]}]

# ddram:0.dq
set_property LOC AH2 [get_ports {ddram_dq[43]}]
set_property SLEW FAST [get_ports {ddram_dq[43]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[43]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[43]}]

# ddram:0.dq
set_property LOC AH4 [get_ports {ddram_dq[44]}]
set_property SLEW FAST [get_ports {ddram_dq[44]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[44]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[44]}]

# ddram:0.dq
set_property LOC AJ4 [get_ports {ddram_dq[45]}]
set_property SLEW FAST [get_ports {ddram_dq[45]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[45]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[45]}]

# ddram:0.dq
set_property LOC AK1 [get_ports {ddram_dq[46]}]
set_property SLEW FAST [get_ports {ddram_dq[46]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[46]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[46]}]

# ddram:0.dq
set_property LOC AJ1 [get_ports {ddram_dq[47]}]
set_property SLEW FAST [get_ports {ddram_dq[47]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[47]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[47]}]

# ddram:0.dq
set_property LOC AF1 [get_ports {ddram_dq[48]}]
set_property SLEW FAST [get_ports {ddram_dq[48]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[48]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[48]}]

# ddram:0.dq
set_property LOC AF2 [get_ports {ddram_dq[49]}]
set_property SLEW FAST [get_ports {ddram_dq[49]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[49]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[49]}]

# ddram:0.dq
set_property LOC AE4 [get_ports {ddram_dq[50]}]
set_property SLEW FAST [get_ports {ddram_dq[50]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[50]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[50]}]

# ddram:0.dq
set_property LOC AE3 [get_ports {ddram_dq[51]}]
set_property SLEW FAST [get_ports {ddram_dq[51]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[51]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[51]}]

# ddram:0.dq
set_property LOC AF3 [get_ports {ddram_dq[52]}]
set_property SLEW FAST [get_ports {ddram_dq[52]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[52]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[52]}]

# ddram:0.dq
set_property LOC AF5 [get_ports {ddram_dq[53]}]
set_property SLEW FAST [get_ports {ddram_dq[53]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[53]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[53]}]

# ddram:0.dq
set_property LOC AE1 [get_ports {ddram_dq[54]}]
set_property SLEW FAST [get_ports {ddram_dq[54]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[54]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[54]}]

# ddram:0.dq
set_property LOC AE5 [get_ports {ddram_dq[55]}]
set_property SLEW FAST [get_ports {ddram_dq[55]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[55]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[55]}]

# ddram:0.dq
set_property LOC AC1 [get_ports {ddram_dq[56]}]
set_property SLEW FAST [get_ports {ddram_dq[56]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[56]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[56]}]

# ddram:0.dq
set_property LOC AD3 [get_ports {ddram_dq[57]}]
set_property SLEW FAST [get_ports {ddram_dq[57]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[57]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[57]}]

# ddram:0.dq
set_property LOC AC4 [get_ports {ddram_dq[58]}]
set_property SLEW FAST [get_ports {ddram_dq[58]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[58]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[58]}]

# ddram:0.dq
set_property LOC AC5 [get_ports {ddram_dq[59]}]
set_property SLEW FAST [get_ports {ddram_dq[59]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[59]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[59]}]

# ddram:0.dq
set_property LOC AE6 [get_ports {ddram_dq[60]}]
set_property SLEW FAST [get_ports {ddram_dq[60]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[60]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[60]}]

# ddram:0.dq
set_property LOC AD6 [get_ports {ddram_dq[61]}]
set_property SLEW FAST [get_ports {ddram_dq[61]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[61]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[61]}]

# ddram:0.dq
set_property LOC AC2 [get_ports {ddram_dq[62]}]
set_property SLEW FAST [get_ports {ddram_dq[62]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[62]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[62]}]

# ddram:0.dq
set_property LOC AD4 [get_ports {ddram_dq[63]}]
set_property SLEW FAST [get_ports {ddram_dq[63]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dq[63]}]
set_property IOSTANDARD SSTL15_T_DCI [get_ports {ddram_dq[63]}]

# ddram:0.dqs_p
set_property LOC AC16 [get_ports {ddram_dqs_p[0]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[0]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[0]}]

# ddram:0.dqs_p
set_property LOC Y19 [get_ports {ddram_dqs_p[1]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[1]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[1]}]

# ddram:0.dqs_p
set_property LOC AJ18 [get_ports {ddram_dqs_p[2]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[2]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[2]}]

# ddram:0.dqs_p
set_property LOC AH16 [get_ports {ddram_dqs_p[3]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[3]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[3]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[3]}]

# ddram:0.dqs_p
set_property LOC AH7 [get_ports {ddram_dqs_p[4]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[4]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[4]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[4]}]

# ddram:0.dqs_p
set_property LOC AG2 [get_ports {ddram_dqs_p[5]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[5]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[5]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[5]}]

# ddram:0.dqs_p
set_property LOC AG4 [get_ports {ddram_dqs_p[6]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[6]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[6]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[6]}]

# ddram:0.dqs_p
set_property LOC AD2 [get_ports {ddram_dqs_p[7]}]
set_property SLEW FAST [get_ports {ddram_dqs_p[7]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_p[7]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_p[7]}]

# ddram:0.dqs_n
set_property LOC AC15 [get_ports {ddram_dqs_n[0]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[0]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[0]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[0]}]

# ddram:0.dqs_n
set_property LOC Y18 [get_ports {ddram_dqs_n[1]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[1]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[1]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[1]}]

# ddram:0.dqs_n
set_property LOC AK18 [get_ports {ddram_dqs_n[2]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[2]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[2]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[2]}]

# ddram:0.dqs_n
set_property LOC AJ16 [get_ports {ddram_dqs_n[3]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[3]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[3]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[3]}]

# ddram:0.dqs_n
set_property LOC AJ7 [get_ports {ddram_dqs_n[4]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[4]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[4]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[4]}]

# ddram:0.dqs_n
set_property LOC AH1 [get_ports {ddram_dqs_n[5]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[5]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[5]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[5]}]

# ddram:0.dqs_n
set_property LOC AG3 [get_ports {ddram_dqs_n[6]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[6]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[6]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[6]}]

# ddram:0.dqs_n
set_property LOC AD1 [get_ports {ddram_dqs_n[7]}]
set_property SLEW FAST [get_ports {ddram_dqs_n[7]}]
set_property VCCAUX_IO HIGH [get_ports {ddram_dqs_n[7]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_dqs_n[7]}]

# ddram:0.clk_p
set_property LOC AG10 [get_ports {ddram_clk_p}]
set_property SLEW FAST [get_ports {ddram_clk_p}]
set_property VCCAUX_IO HIGH [get_ports {ddram_clk_p}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_clk_p}]

# ddram:0.clk_n
set_property LOC AH10 [get_ports {ddram_clk_n}]
set_property SLEW FAST [get_ports {ddram_clk_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_clk_n}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddram_clk_n}]

# ddram:0.cke
set_property LOC AF10 [get_ports {ddram_cke}]
set_property SLEW FAST [get_ports {ddram_cke}]
set_property VCCAUX_IO HIGH [get_ports {ddram_cke}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_cke}]

# ddram:0.odt
set_property LOC AD8 [get_ports {ddram_odt}]
set_property SLEW FAST [get_ports {ddram_odt}]
set_property VCCAUX_IO HIGH [get_ports {ddram_odt}]
set_property IOSTANDARD SSTL15 [get_ports {ddram_odt}]

# ddram:0.reset_n
set_property LOC AK3 [get_ports {ddram_reset_n}]
set_property SLEW FAST [get_ports {ddram_reset_n}]
set_property VCCAUX_IO HIGH [get_ports {ddram_reset_n}]
set_property IOSTANDARD LVCMOS15 [get_ports {ddram_reset_n}]

# user_led:0
set_property LOC AB8 [get_ports {user_led0}]
set_property IOSTANDARD LVCMOS15 [get_ports {user_led0}]

# user_led:1
set_property LOC AA8 [get_ports {user_led1}]
set_property IOSTANDARD LVCMOS15 [get_ports {user_led1}]

# user_led:2
set_property LOC AC9 [get_ports {user_led2}]
set_property IOSTANDARD LVCMOS15 [get_ports {user_led2}]

# user_led:3
set_property LOC AB9 [get_ports {user_led3}]
set_property IOSTANDARD LVCMOS15 [get_ports {user_led3}]

# user_led:4
set_property LOC AE26 [get_ports {user_led4}]
set_property IOSTANDARD LVCMOS25 [get_ports {user_led4}]

# user_led:5
set_property LOC G19 [get_ports {user_led5}]
set_property IOSTANDARD LVCMOS25 [get_ports {user_led5}]

# user_led:6
set_property LOC E18 [get_ports {user_led6}]
set_property IOSTANDARD LVCMOS25 [get_ports {user_led6}]

# user_led:7
set_property LOC F16 [get_ports {user_led7}]
set_property IOSTANDARD LVCMOS25 [get_ports {user_led7}]

################################################################################
# Design constraints
################################################################################


set_property CFGBVS VCCO [current_design]
set_property CONFIG_VOLTAGE 2.5 [current_design]


set_property DCI_CASCADE {32 34} [get_iobanks 33]

################################################################################
# Clock constraints
################################################################################


create_clock -name clk200_p -period 5.0 [get_ports clk200_p]

set_clock_groups -group [get_clocks -include_generated_clocks -of [get_nets sys_clk]] -group [get_clocks -include_generated_clocks -of [get_nets main_crg_clkin]] -asynchronous

################################################################################
# False path constraints
################################################################################


set_false_path -quiet -through [get_nets -hierarchical -filter {mr_ff == TRUE}]

set_false_path -quiet -to [get_pins -filter {REF_PIN_NAME == PRE} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE || ars_ff2 == TRUE}]]

set_max_delay 2 -quiet -from [get_pins -filter {REF_PIN_NAME == C} -of_objects [get_cells -hierarchical -filter {ars_ff1 == TRUE}]] -to [get_pins -filter {REF_PIN_NAME == D} -of_objects [get_cells -hierarchical -filter {ars_ff2 == TRUE}]]