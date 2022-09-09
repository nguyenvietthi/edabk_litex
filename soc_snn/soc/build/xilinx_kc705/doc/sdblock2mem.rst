SDBLOCK2MEM
===========

Register Listing for SDBLOCK2MEM
--------------------------------

+--------------------------------------------------------+--------------------------------------------+
| Register                                               | Address                                    |
+========================================================+============================================+
| :ref:`SDBLOCK2MEM_DMA_BASE1 <SDBLOCK2MEM_DMA_BASE1>`   | :ref:`0xf0002800 <SDBLOCK2MEM_DMA_BASE1>`  |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_BASE0 <SDBLOCK2MEM_DMA_BASE0>`   | :ref:`0xf0002804 <SDBLOCK2MEM_DMA_BASE0>`  |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_LENGTH <SDBLOCK2MEM_DMA_LENGTH>` | :ref:`0xf0002808 <SDBLOCK2MEM_DMA_LENGTH>` |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_ENABLE <SDBLOCK2MEM_DMA_ENABLE>` | :ref:`0xf000280c <SDBLOCK2MEM_DMA_ENABLE>` |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_DONE <SDBLOCK2MEM_DMA_DONE>`     | :ref:`0xf0002810 <SDBLOCK2MEM_DMA_DONE>`   |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_LOOP <SDBLOCK2MEM_DMA_LOOP>`     | :ref:`0xf0002814 <SDBLOCK2MEM_DMA_LOOP>`   |
+--------------------------------------------------------+--------------------------------------------+
| :ref:`SDBLOCK2MEM_DMA_OFFSET <SDBLOCK2MEM_DMA_OFFSET>` | :ref:`0xf0002818 <SDBLOCK2MEM_DMA_OFFSET>` |
+--------------------------------------------------------+--------------------------------------------+

SDBLOCK2MEM_DMA_BASE1
^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x0 = 0xf0002800`

    Bits 32-63 of `SDBLOCK2MEM_DMA_BASE`.

    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_BASE1

        {
            "reg": [
                {"name": "dma_base[63:32]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDBLOCK2MEM_DMA_BASE0
^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x4 = 0xf0002804`

    Bits 0-31 of `SDBLOCK2MEM_DMA_BASE`.

    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_BASE0

        {
            "reg": [
                {"name": "dma_base[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDBLOCK2MEM_DMA_LENGTH
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x8 = 0xf0002808`


    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_LENGTH

        {
            "reg": [
                {"name": "dma_length[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


SDBLOCK2MEM_DMA_ENABLE
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0xc = 0xf000280c`


    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_ENABLE

        {
            "reg": [
                {"name": "dma_enable", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDBLOCK2MEM_DMA_DONE
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x10 = 0xf0002810`


    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_DONE

        {
            "reg": [
                {"name": "dma_done", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDBLOCK2MEM_DMA_LOOP
^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x14 = 0xf0002814`


    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_LOOP

        {
            "reg": [
                {"name": "dma_loop", "bits": 1},
                {"bits": 31},
            ], "config": {"hspace": 400, "bits": 32, "lanes": 4 }, "options": {"hspace": 400, "bits": 32, "lanes": 4}
        }


SDBLOCK2MEM_DMA_OFFSET
^^^^^^^^^^^^^^^^^^^^^^

`Address: 0xf0002800 + 0x18 = 0xf0002818`


    .. wavedrom::
        :caption: SDBLOCK2MEM_DMA_OFFSET

        {
            "reg": [
                {"name": "dma_offset[31:0]", "bits": 32}
            ], "config": {"hspace": 400, "bits": 32, "lanes": 1 }, "options": {"hspace": 400, "bits": 32, "lanes": 1}
        }


