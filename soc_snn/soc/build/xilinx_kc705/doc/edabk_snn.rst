EDABK_SNN
=========

EDABK SNN
---------


Register Listing for EDABK_SNN
------------------------------

+------------------------------------------------------------------+-------------------------------------------------+
| Register                                                         | Address                                         |
+==================================================================+=================================================+
| :ref:`EDABK_SNN_TICK <EDABK_SNN_TICK>`                           | :ref:`0xf0000000 <EDABK_SNN_TICK>`              |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PACKET_WDATA <EDABK_SNN_PACKET_WDATA>`           | :ref:`0xf0000004 <EDABK_SNN_PACKET_WDATA>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA0 <EDABK_SNN_PARAM_WDATA0>`           | :ref:`0xf0000008 <EDABK_SNN_PARAM_WDATA0>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA1 <EDABK_SNN_PARAM_WDATA1>`           | :ref:`0xf000000c <EDABK_SNN_PARAM_WDATA1>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA2 <EDABK_SNN_PARAM_WDATA2>`           | :ref:`0xf0000010 <EDABK_SNN_PARAM_WDATA2>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA3 <EDABK_SNN_PARAM_WDATA3>`           | :ref:`0xf0000014 <EDABK_SNN_PARAM_WDATA3>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA4 <EDABK_SNN_PARAM_WDATA4>`           | :ref:`0xf0000018 <EDABK_SNN_PARAM_WDATA4>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA5 <EDABK_SNN_PARAM_WDATA5>`           | :ref:`0xf000001c <EDABK_SNN_PARAM_WDATA5>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA6 <EDABK_SNN_PARAM_WDATA6>`           | :ref:`0xf0000020 <EDABK_SNN_PARAM_WDATA6>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA7 <EDABK_SNN_PARAM_WDATA7>`           | :ref:`0xf0000024 <EDABK_SNN_PARAM_WDATA7>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA8 <EDABK_SNN_PARAM_WDATA8>`           | :ref:`0xf0000028 <EDABK_SNN_PARAM_WDATA8>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA9 <EDABK_SNN_PARAM_WDATA9>`           | :ref:`0xf000002c <EDABK_SNN_PARAM_WDATA9>`      |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA10 <EDABK_SNN_PARAM_WDATA10>`         | :ref:`0xf0000030 <EDABK_SNN_PARAM_WDATA10>`     |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PARAM_WDATA11 <EDABK_SNN_PARAM_WDATA11>`         | :ref:`0xf0000034 <EDABK_SNN_PARAM_WDATA11>`     |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_NEURON_INST_WDATA <EDABK_SNN_NEURON_INST_WDATA>` | :ref:`0xf0000038 <EDABK_SNN_NEURON_INST_WDATA>` |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PACKET_OUT_RINC <EDABK_SNN_PACKET_OUT_RINC>`     | :ref:`0xf000003c <EDABK_SNN_PACKET_OUT_RINC>`   |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_PACKET_OUT <EDABK_SNN_PACKET_OUT>`               | :ref:`0xf0000040 <EDABK_SNN_PACKET_OUT>`        |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_TICK_READY <EDABK_SNN_TICK_READY>`               | :ref:`0xf0000044 <EDABK_SNN_TICK_READY>`        |
+------------------------------------------------------------------+-------------------------------------------------+
| :ref:`EDABK_SNN_SNN_STATUS <EDABK_SNN_SNN_STATUS>`               | :ref:`0xf0000048 <EDABK_SNN_SNN_STATUS>`        |
+------------------------------------------------------------------+-------------------------------------------------+

EDABK_SNN_TICK
^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x0 = 0xf0000000`

    Send tick to SNN

    .. wavedrom::
        :caption: EDABK_SNN_TICK

        {
            "reg": [
                {"name": "tick", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


EDABK_SNN_PACKET_WDATA
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x4 = 0xf0000004`

    Packet data send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PACKET_WDATA

        {
            "reg": [
                {"name": "packet_wdata[29:0]", "bits": 30},
                {"bits": 2},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA0
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x8 = 0xf0000008`

    Param data0 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA0

        {
            "reg": [
                {"name": "param_wdata0[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA1
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0xc = 0xf000000c`

    Param data1 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA1

        {
            "reg": [
                {"name": "param_wdata1[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA2
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x10 = 0xf0000010`

    Param data2 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA2

        {
            "reg": [
                {"name": "param_wdata2[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA3
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x14 = 0xf0000014`

    Param data3 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA3

        {
            "reg": [
                {"name": "param_wdata3[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA4
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x18 = 0xf0000018`

    Param data4 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA4

        {
            "reg": [
                {"name": "param_wdata4[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA5
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x1c = 0xf000001c`

    Param data5 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA5

        {
            "reg": [
                {"name": "param_wdata5[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA6
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x20 = 0xf0000020`

    Param data6 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA6

        {
            "reg": [
                {"name": "param_wdata6[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA7
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x24 = 0xf0000024`

    Param data7 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA7

        {
            "reg": [
                {"name": "param_wdata7[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA8
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x28 = 0xf0000028`

    Param data8 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA8

        {
            "reg": [
                {"name": "param_wdata8[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA9
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x2c = 0xf000002c`

    Param data9 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA9

        {
            "reg": [
                {"name": "param_wdata9[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA10
^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x30 = 0xf0000030`

    Param data10 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA10

        {
            "reg": [
                {"name": "param_wdata10[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_PARAM_WDATA11
^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x34 = 0xf0000034`

    Param data11 send SNN

    .. wavedrom::
        :caption: EDABK_SNN_PARAM_WDATA11

        {
            "reg": [
                {"name": "param_wdata11[15:0]", "bits": 16},
                {"bits": 16},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_NEURON_INST_WDATA
^^^^^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x38 = 0xf0000038`

    neuron_inst data send SNN

    .. wavedrom::
        :caption: EDABK_SNN_NEURON_INST_WDATA

        {
            "reg": [
                {"name": "neuron_inst_wdata[1:0]", "bits": 2},
                {"bits": 30},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


EDABK_SNN_PACKET_OUT_RINC
^^^^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x3c = 0xf000003c`

    Enable signal read packet out data

    .. wavedrom::
        :caption: EDABK_SNN_PACKET_OUT_RINC

        {
            "reg": [
                {"name": "packet_out_rinc", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


EDABK_SNN_PACKET_OUT
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x40 = 0xf0000040`

    Packet out data

    .. wavedrom::
        :caption: EDABK_SNN_PACKET_OUT

        {
            "reg": [
                {"name": "packet_out[7:0]", "bits": 8},
                {"bits": 24},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


EDABK_SNN_TICK_READY
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x44 = 0xf0000044`

    Tick ready

    .. wavedrom::
        :caption: EDABK_SNN_TICK_READY

        {
            "reg": [
                {"name": "tick_ready", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


EDABK_SNN_SNN_STATUS
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0000000 + 0x48 = 0xf0000048`

    SNN status

    .. wavedrom::
        :caption: EDABK_SNN_SNN_STATUS

        {
            "reg": [
                {"name": "packet_wfull",  "bits": 1},
                {"name": "param_wfull",  "bits": 1},
                {"name": "neuron_inst_wfull",  "bits": 1},
                {"name": "packet_out_rempty",  "bits": 1},
                {"name": "token_controller_error",  "bits": 1},
                {"name": "scheduler_error",  "bits": 1},
                {"name": "wait_packets",  "bits": 1},
                {"bits": 25}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+------------------------+-------------------------------------------------------+
| Field | Name                   | Description                                           |
+=======+========================+=======================================================+
| [0]   | PACKET_WFULL           | flag full                                             |
+-------+------------------------+-------------------------------------------------------+
| [1]   | PARAM_WFULL            | flag full                                             |
+-------+------------------------+-------------------------------------------------------+
| [2]   | NEURON_INST_WFULL      | flag full                                             |
+-------+------------------------+-------------------------------------------------------+
| [3]   | PACKET_OUT_REMPTY      | Packet out data is empty                              |
+-------+------------------------+-------------------------------------------------------+
| [4]   | TOKEN_CONTROLLER_ERROR | Token controller error                                |
+-------+------------------------+-------------------------------------------------------+
| [5]   | SCHEDULER_ERROR        | Scheduler error                                       |
+-------+------------------------+-------------------------------------------------------+
| [6]   | WAIT_PACKETS           | Wait for packet to put on snn/ Time to read packetout |
+-------+------------------------+-------------------------------------------------------+

