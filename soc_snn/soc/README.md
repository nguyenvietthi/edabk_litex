[> Build SOC with EDABK SNN and SDcard
----------------------
python3 soc.py --build --with-sdcard --integrated-sram-size=0x20000

[> Load bitstream
----------------------
python3 soc.py --load
