[> Build SOC with SDcard and EDABK SNN
----------------------
python3 soc.py --build --with-sdcard --integrated-sram-size=0x20000

[> Load bitstream
----------------------
python3 soc.py --load
