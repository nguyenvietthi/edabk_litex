parameter [5:0] CMD0_GO_IDLE         = 'd0,
                CMD1_SEND_OP_COND    = 'd1,
                CMD2_ALL_SEND_CID    = 'd2,
                CMD3_SEND_REL_ADDR   = 'd3,
                CMD4_SET_DSR         = 'd4,
                CMD6_SWITCH_FUNC     = 'd6,
                CMD7_SEL_CARD        = 'd7,
                CMD8_SEND_IF_COND    = 'd8,
                CMD9_SEND_CSD        = 'd9,
                CMD10_SEND_CID       = 'd10,
                CMD12_STOP           = 'd12,
                CMD13_SEND_STATUS    = 'd13,
                CMD15_GO_INACTIVE    = 'd15,
                CMD16_SET_BLOCKLEN   = 'd16,
                CMD17_READ_SINGLE    = 'd17,
                CMD18_READ_MULTIPLE  = 'd18,
                CMD24_WRITE_SINGLE   = 'd24,
                CMD25_WRITE_MULTIPLE = 'd25,
                CMD27_PROGRAM_CSD    = 'd27,

                CMD32_ERASE_START    = 'd32,
                CMD33_ERASE_END      = 'd33,
                CMD38_ERASE          = 'd38,

                CMD42_LOCK_UNLOCK    = 'd42,

                CMD55_APP_CMD        = 'd55,
                CMD56_GEN_CMD        = 'd56,

                CMD58_READ_OCR       = 'd58,
                CMD59_CRC_ON_OFF     = 'd59,

                // unsupported
                CMD28_SET_WRITE_PROT = 'd28,
                CMD29_CLR_WRITE_PROT = 'd29,
                CMD30_SND_WRITE_PROT = 'd30,
                CMD40_INVALID        = 'd40,

                CMD_LAST             = 'd63;

parameter [5:0] ACMD6_SET_BUS_WIDTH  = 'd6,
                ACMD13_SD_STATUS     = 'd13,
                ACMD22_NUM_WR_BLK    = 'd22,
                ACMD23_SET_WR_BLK    = 'd23,
                ACMD41_SEND_OP_COND  = 'd41,
                ACMD42_SET_CARD_DET  = 'd42,
                ACMD51_SEND_SCR      = 'd51,

                ACMD_LAST            = 'd63;

parameter [3:0] RESP_NONE = 'd0,
                RESP_R1   = 'd1,
                RESP_R1B  = 'd8,
                RESP_R2   = 'd2,
                RESP_R3   = 'd3,
                RESP_R6   = 'd6,
                RESP_R7   = 'd7,
                RESP_BAD  = 'd14,
                RESP_LAST = 'd15;

parameter [4:0] STAT_OUT_OF_RANGE       = 'd31,
                STAT_ADDRESS_ERROR      = 'd30,
                STAT_BLOCK_LEN_ERROR    = 'd29,
                STAT_ERASE_SEQ_ERROR    = 'd28,
                STAT_ERASE_PARAM        = 'd27,
                STAT_WP_VIOLATION       = 'd26,
                STAT_CARD_IS_LOCKED     = 'd25,
                STAT_LOCK_UNLOCK_FAILED = 'd24,
                STAT_COM_CRC_ERROR      = 'd23,
                STAT_ILLEGAL_COMMAND    = 'd22,
                STAT_CARD_ECC_FAILED    = 'd21,
                STAT_CC_ERROR           = 'd20,
                STAT_ERROR              = 'd19,
                STAT_CSD_OVERWRITE      = 'd16,
                STAT_WP_ERASE_SKIP      = 'd15,
                STAT_CARD_ECC_DISABLED  = 'd14,
                STAT_ERASE_RESET        = 'd13,
                STAT_READY_FOR_DATA     = 'd8,
                STAT_APP_CMD            = 'd5,
                STAT_AKE_SEQ_ERROR      = 'd3;

parameter [4:0] OCR_POWERED_UP          = 'd31,
                OCR_CARD_CAPACITY       = 'd30;

parameter [3:0] CARD_IDLE   = 'd0,
                CARD_READY  = 'd1,
                CARD_IDENT  = 'd2,
                CARD_STBY   = 'd3,
                CARD_TRAN   = 'd4,
                CARD_DATA   = 'd5,
                CARD_RCV    = 'd6,
                CARD_PRG    = 'd7,
                CARD_DIS    = 'd8,
                CARD_INA    = 'd9,
                CARD_RESVD1 = 'd10,
                CARD_RESVD2 = 'd11,
                CARD_RESVD3 = 'd12,
                CARD_RESVD4 = 'd13,
                CARD_RESVD5 = 'd14,
                CARD_RESVD6 = 'd15;

parameter [7:0] SPI_START_TOKEN       = 'hFE,
                SPI_START_BLOCK_TOKEN = 'hFC,
                SPI_STOP_TRAN_TOKEN   = 'hFD;
