LEDS
====

Register Listing for LEDS
-------------------------

+----------------------------+------------------------------+
| Register                   | Address                      |
+============================+==============================+
| :ref:`LEDS_OUT <LEDS_OUT>` | :ref:`0xf0002000 <LEDS_OUT>` |
+----------------------------+------------------------------+

LEDS_OUT
^^^^^^^^

`Address: 0xf0002000 + 0x0 = 0xf0002000`

    Led Output(s) Control.

    .. wavedrom::
        :caption: LEDS_OUT

        {
            "reg": [
                {"name": "out[7:0]", "bits": 8},
                {"bits": 24},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


