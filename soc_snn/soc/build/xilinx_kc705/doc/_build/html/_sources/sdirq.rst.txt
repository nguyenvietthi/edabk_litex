SDIRQ
=====

Register Listing for SDIRQ
--------------------------

+--------------------------------------+-----------------------------------+
| Register                             | Address                           |
+======================================+===================================+
| :ref:`SDIRQ_STATUS <SDIRQ_STATUS>`   | :ref:`0xf0003800 <SDIRQ_STATUS>`  |
+--------------------------------------+-----------------------------------+
| :ref:`SDIRQ_PENDING <SDIRQ_PENDING>` | :ref:`0xf0003804 <SDIRQ_PENDING>` |
+--------------------------------------+-----------------------------------+
| :ref:`SDIRQ_ENABLE <SDIRQ_ENABLE>`   | :ref:`0xf0003808 <SDIRQ_ENABLE>`  |
+--------------------------------------+-----------------------------------+

SDIRQ_STATUS
^^^^^^^^^^^^

`Address: 0xf0003800 + 0x0 = 0xf0003800`

    Command completed.

    .. wavedrom::
        :caption: SDIRQ_STATUS

        {
            "reg": [
                {"name": "card_detect",  "bits": 1},
                {"name": "block2mem_dma",  "bits": 1},
                {"name": "mem2block_dma",  "bits": 1},
                {"name": "cmd_done",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------------+--------------------------------------+
| Field | Name          | Description                          |
+=======+===============+======================================+
| [0]   | CARD_DETECT   | Level of the ``card_detect`` event   |
+-------+---------------+--------------------------------------+
| [1]   | BLOCK2MEM_DMA | Level of the ``block2mem_dma`` event |
+-------+---------------+--------------------------------------+
| [2]   | MEM2BLOCK_DMA | Level of the ``mem2block_dma`` event |
+-------+---------------+--------------------------------------+
| [3]   | CMD_DONE      | Level of the ``cmd_done`` event      |
+-------+---------------+--------------------------------------+

SDIRQ_PENDING
^^^^^^^^^^^^^

`Address: 0xf0003800 + 0x4 = 0xf0003804`

    Command completed.

    .. wavedrom::
        :caption: SDIRQ_PENDING

        {
            "reg": [
                {"name": "card_detect",  "bits": 1},
                {"name": "block2mem_dma",  "bits": 1},
                {"name": "mem2block_dma",  "bits": 1},
                {"name": "cmd_done",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------------+-----------------------------------+
| Field | Name          | Description                       |
+=======+===============+===================================+
| [0]   | CARD_DETECT   | SDCard has been ejected/inserted. |
+-------+---------------+-----------------------------------+
| [1]   | BLOCK2MEM_DMA | Block2Mem DMA terminated.         |
+-------+---------------+-----------------------------------+
| [2]   | MEM2BLOCK_DMA | Mem2Block DMA terminated.         |
+-------+---------------+-----------------------------------+
| [3]   | CMD_DONE      | Command completed.                |
+-------+---------------+-----------------------------------+

SDIRQ_ENABLE
^^^^^^^^^^^^

`Address: 0xf0003800 + 0x8 = 0xf0003808`

    Command completed.

    .. wavedrom::
        :caption: SDIRQ_ENABLE

        {
            "reg": [
                {"name": "card_detect",  "bits": 1},
                {"name": "block2mem_dma",  "bits": 1},
                {"name": "mem2block_dma",  "bits": 1},
                {"name": "cmd_done",  "bits": 1},
                {"bits": 28}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


+-------+---------------+-----------------------------------------------------+
| Field | Name          | Description                                         |
+=======+===============+=====================================================+
| [0]   | CARD_DETECT   | Write a ``1`` to enable the ``card_detect`` Event   |
+-------+---------------+-----------------------------------------------------+
| [1]   | BLOCK2MEM_DMA | Write a ``1`` to enable the ``block2mem_dma`` Event |
+-------+---------------+-----------------------------------------------------+
| [2]   | MEM2BLOCK_DMA | Write a ``1`` to enable the ``mem2block_dma`` Event |
+-------+---------------+-----------------------------------------------------+
| [3]   | CMD_DONE      | Write a ``1`` to enable the ``cmd_done`` Event      |
+-------+---------------+-----------------------------------------------------+

