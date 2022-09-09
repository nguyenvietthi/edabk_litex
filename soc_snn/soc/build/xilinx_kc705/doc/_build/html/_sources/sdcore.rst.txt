SDCORE
======

Register Listing for SDCORE
---------------------------

+----------------------------------------------------+------------------------------------------+
| Register                                           | Address                                  |
+====================================================+==========================================+
| :ref:`SDCORE_CMD_ARGUMENT <SDCORE_CMD_ARGUMENT>`   | :ref:`0xf0003000 <SDCORE_CMD_ARGUMENT>`  |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_COMMAND <SDCORE_CMD_COMMAND>`     | :ref:`0xf0003004 <SDCORE_CMD_COMMAND>`   |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_SEND <SDCORE_CMD_SEND>`           | :ref:`0xf0003008 <SDCORE_CMD_SEND>`      |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_RESPONSE3 <SDCORE_CMD_RESPONSE3>` | :ref:`0xf000300c <SDCORE_CMD_RESPONSE3>` |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_RESPONSE2 <SDCORE_CMD_RESPONSE2>` | :ref:`0xf0003010 <SDCORE_CMD_RESPONSE2>` |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_RESPONSE1 <SDCORE_CMD_RESPONSE1>` | :ref:`0xf0003014 <SDCORE_CMD_RESPONSE1>` |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_RESPONSE0 <SDCORE_CMD_RESPONSE0>` | :ref:`0xf0003018 <SDCORE_CMD_RESPONSE0>` |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_CMD_EVENT <SDCORE_CMD_EVENT>`         | :ref:`0xf000301c <SDCORE_CMD_EVENT>`     |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_DATA_EVENT <SDCORE_DATA_EVENT>`       | :ref:`0xf0003020 <SDCORE_DATA_EVENT>`    |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_BLOCK_LENGTH <SDCORE_BLOCK_LENGTH>`   | :ref:`0xf0003024 <SDCORE_BLOCK_LENGTH>`  |
+----------------------------------------------------+------------------------------------------+
| :ref:`SDCORE_BLOCK_COUNT <SDCORE_BLOCK_COUNT>`     | :ref:`0xf0003028 <SDCORE_BLOCK_COUNT>`   |
+----------------------------------------------------+------------------------------------------+

SDCORE_CMD_ARGUMENT
^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x0 = 0xf0003000`

    SDCard Cmd Argument.

    .. wavedrom::
        :caption: SDCORE_CMD_ARGUMENT

        {
            "reg": [
                {"name": "cmd_argument[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_CMD_COMMAND
^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x4 = 0xf0003004`


    .. wavedrom::
        :caption: SDCORE_CMD_COMMAND

        {
            "reg": [
                {"name": "cmd_type",  "bits": 2},
                {"bits": 3},
                {"name": "data_type",  "bits": 2},
                {"bits": 1},
                {"name": "cmd",  "bits": 6},
                {"bits": 18}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+--------+-----------+------------------------------+
| Field  | Name      | Description                  |
+========+===========+==============================+
| [1:0]  | CMD_TYPE  | Core/PHY Cmd transfer type.  |
+--------+-----------+------------------------------+
| [6:5]  | DATA_TYPE | Core/PHY Data transfer type. |
+--------+-----------+------------------------------+
| [13:8] | CMD       | SDCard Cmd.                  |
+--------+-----------+------------------------------+

SDCORE_CMD_SEND
^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x8 = 0xf0003008`

    Run Cmd/Data transfer.

    .. wavedrom::
        :caption: SDCORE_CMD_SEND

        {
            "reg": [
                {"name": "cmd_send", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDCORE_CMD_RESPONSE3
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0xc = 0xf000300c`

    Bits 96-127 of `SDCORE_CMD_RESPONSE`. SDCard Cmd Response.

    .. wavedrom::
        :caption: SDCORE_CMD_RESPONSE3

        {
            "reg": [
                {"name": "cmd_response[127:96]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_CMD_RESPONSE2
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x10 = 0xf0003010`

    Bits 64-95 of `SDCORE_CMD_RESPONSE`.

    .. wavedrom::
        :caption: SDCORE_CMD_RESPONSE2

        {
            "reg": [
                {"name": "cmd_response[95:64]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_CMD_RESPONSE1
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x14 = 0xf0003014`

    Bits 32-63 of `SDCORE_CMD_RESPONSE`.

    .. wavedrom::
        :caption: SDCORE_CMD_RESPONSE1

        {
            "reg": [
                {"name": "cmd_response[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_CMD_RESPONSE0
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x18 = 0xf0003018`

    Bits 0-31 of `SDCORE_CMD_RESPONSE`.

    .. wavedrom::
        :caption: SDCORE_CMD_RESPONSE0

        {
            "reg": [
                {"name": "cmd_response[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_CMD_EVENT
^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x1c = 0xf000301c`


    .. wavedrom::
        :caption: SDCORE_CMD_EVENT

        {
            "reg": [
                {"name": "done",  "bits": 1},
                {"name": "error",  "bits": 1},
                {"name": "timeout",  "bits": 1},
                {"name": "crc",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------+------------------------------------------+
| Field | Name    | Description                              |
+=======+=========+==========================================+
| [0]   | DONE    | Cmd transfer has been executed.          |
+-------+---------+------------------------------------------+
| [1]   | ERROR   | Cmd transfer has failed due to error(s). |
+-------+---------+------------------------------------------+
| [2]   | TIMEOUT | Timeout error.                           |
+-------+---------+------------------------------------------+
| [3]   | CRC     | CRC Error.                               |
+-------+---------+------------------------------------------+

SDCORE_DATA_EVENT
^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x20 = 0xf0003020`


    .. wavedrom::
        :caption: SDCORE_DATA_EVENT

        {
            "reg": [
                {"name": "done",  "bits": 1},
                {"name": "error",  "bits": 1},
                {"name": "timeout",  "bits": 1},
                {"name": "crc",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------+-------------------------------------------+
| Field | Name    | Description                               |
+=======+=========+===========================================+
| [0]   | DONE    | Data transfer has been executed.          |
+-------+---------+-------------------------------------------+
| [1]   | ERROR   | Data transfer has failed due to error(s). |
+-------+---------+-------------------------------------------+
| [2]   | TIMEOUT | Timeout Error.                            |
+-------+---------+-------------------------------------------+
| [3]   | CRC     | CRC Error.                                |
+-------+---------+-------------------------------------------+

SDCORE_BLOCK_LENGTH
^^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x24 = 0xf0003024`

    Data transfer Block Length (in bytes).

    .. wavedrom::
        :caption: SDCORE_BLOCK_LENGTH

        {
            "reg": [
                {"name": "block_length[9:0]", "bits": 10},
                {"bits": 22},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDCORE_BLOCK_COUNT
^^^^^^^^^^^^^^^^^^

`Address: 0xf0003000 + 0x28 = 0xf0003028`

    Data transfer Block Count.

    .. wavedrom::
        :caption: SDCORE_BLOCK_COUNT

        {
            "reg": [
                {"name": "block_count[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


