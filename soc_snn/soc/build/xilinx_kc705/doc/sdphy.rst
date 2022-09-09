SDPHY
=====

Register Listing for SDPHY
--------------------------

+------------------------------------------------------+-------------------------------------------+
| Register                                             | Address                                   |
+======================================================+===========================================+
| :ref:`SDPHY_CARD_DETECT <SDPHY_CARD_DETECT>`         | :ref:`0xf0004800 <SDPHY_CARD_DETECT>`     |
+------------------------------------------------------+-------------------------------------------+
| :ref:`SDPHY_CLOCKER_DIVIDER <SDPHY_CLOCKER_DIVIDER>` | :ref:`0xf0004804 <SDPHY_CLOCKER_DIVIDER>` |
+------------------------------------------------------+-------------------------------------------+
| :ref:`SDPHY_INIT_INITIALIZE <SDPHY_INIT_INITIALIZE>` | :ref:`0xf0004808 <SDPHY_INIT_INITIALIZE>` |
+------------------------------------------------------+-------------------------------------------+
| :ref:`SDPHY_DATAW_STATUS <SDPHY_DATAW_STATUS>`       | :ref:`0xf000480c <SDPHY_DATAW_STATUS>`    |
+------------------------------------------------------+-------------------------------------------+

SDPHY_CARD_DETECT
^^^^^^^^^^^^^^^^^

`Address: 0xf0004800 + 0x0 = 0xf0004800`


    .. wavedrom::
        :caption: SDPHY_CARD_DETECT

        {
            "reg": [
                {"name": "card_detect", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDPHY_CLOCKER_DIVIDER
^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004800 + 0x4 = 0xf0004804`


    .. wavedrom::
        :caption: SDPHY_CLOCKER_DIVIDER

        {
            "reg": [
                {"name": "clocker_divider[8:0]", "attr": 'reset: 256', "bits": 9},
                {"bits": 23},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDPHY_INIT_INITIALIZE
^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0004800 + 0x8 = 0xf0004808`


    .. wavedrom::
        :caption: SDPHY_INIT_INITIALIZE

        {
            "reg": [
                {"name": "init_initialize", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDPHY_DATAW_STATUS
^^^^^^^^^^^^^^^^^^

`Address: 0xf0004800 + 0xc = 0xf000480c`


    .. wavedrom::
        :caption: SDPHY_DATAW_STATUS

        {
            "reg": [
                {"name": "accepted",  "bits": 1},
                {"name": "crc_error",  "bits": 1},
                {"name": "write_error",  "bits": 1},
                {"bits": 29}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+-------------+-------------+
| Field | Name        | Description |
+=======+=============+=============+
+-------+-------------+-------------+
+-------+-------------+-------------+
+-------+-------------+-------------+

