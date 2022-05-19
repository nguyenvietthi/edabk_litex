onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb/user_btn_r
add wave -noupdate /tb/user_btn_l
add wave -noupdate /tb/seven_seg0
add wave -noupdate /tb/seven_seg1
add wave -noupdate /tb/seven_seg2
add wave -noupdate /tb/seven_seg3
add wave -noupdate /tb/seven_seg4
add wave -noupdate /tb/seven_seg5
add wave -noupdate /tb/clk50
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {364139221 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {616816890 ps}
