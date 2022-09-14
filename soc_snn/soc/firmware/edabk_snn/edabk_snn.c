#include "edabk_snn.h"
#include "../sd/sd.h"
#include <generated/csr.h>
#include <stdlib.h>
#include <string.h>
#include <liblitesdcard/sdcard.h>
#include <libfatfs/ff.h>			
#include <libfatfs/diskio.h>

static const long hextable[] = {
   [0 ... 255] = -1, // bit aligned access into this table is considerably
   ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // faster for most modern processors,
   ['A'] = 10, 11, 12, 13, 14, 15,       // for the space conscious, reduce to
   ['a'] = 10, 11, 12, 13, 14, 15        // signed char.
};

long hexdec(unsigned const char *hex) {
   long ret = 0; 
   while (*hex && ret >= 0) {
      ret = (ret << 4) | hextable[*hex++];
   }
   return ret; 
}

void load_neuron_parameter(void){
	FIL fptr[1];
	FRESULT op = f_open(fptr, "csram.mem", FA_READ);
	if (op != FR_OK){
		printf("Could not open file: %s\n", "csram.mem");
	}
	char param_string[93];
	int line_index = 93;
	uint16_t index = 0;
	int param[256][12];
	int i = 0;

	while ((f_eof(fptr) == 0)){
		f_gets((char*)param_string, 93, fptr);// read current line
		f_lseek(fptr, line_index);// move to the next line
		// printf("param: %s\n", param_string);
		line_index = line_index + 93;
		char value[9];
		for (int j = 0; j < 12; j++){
			if(j == 0){
            	strncpy(value, param_string, 4);
            	value[5] = 0; 
        	} else{
            	strncpy(value, param_string + 4 + (j - 1) * 8, 8);
            	value[9] = 0; 
       		}	   
			param[i][j] = hexdec(value);
		}
		i++;
	}
	
	#ifdef DEBUG
	for(int i = 0; i < 256; i++){
		printf("parameter %3d: %8X %8X %8X %8X %8X %8X %8X %8X %8X %8X %8X %8X \n", i, \
		param[i][0],param[i][1],param[i][2],param[i][3],param[i][4],param[i][5], param[i][6] \
		,param[i][7],param[i][8],param[i][9],param[i][10],param[i][11]);
	}
	#endif

    do {
		if (!edabk_snn_snn_status_param_wfull_read()) {
			edabk_snn_param_wdata0_write  (param[index][11]);
			edabk_snn_param_wdata1_write  (param[index][10]);			
			edabk_snn_param_wdata2_write  (param[index][9]) ;			
			edabk_snn_param_wdata3_write  (param[index][8]) ;			
			edabk_snn_param_wdata4_write  (param[index][7]) ;			
			edabk_snn_param_wdata5_write  (param[index][6]) ;			
			edabk_snn_param_wdata6_write  (param[index][5]) ;			
			edabk_snn_param_wdata7_write  (param[index][4]) ;			
			edabk_snn_param_wdata8_write  (param[index][3]) ;			
			edabk_snn_param_wdata9_write  (param[index][2]) ;			
			edabk_snn_param_wdata10_write (param[index][1]) ;			
			edabk_snn_param_wdata11_write (param[index][0]) ;			
			index++;
		}
	} while (index < 256);

	printf("Parameter load successful!!!\n\n");

}

void load_neuron_inst(void){
	FIL fptr[1];
	FRESULT op = f_open(fptr, "inst.mem", FA_READ);
	if (op != FR_OK){
		printf("Could not open file: %s\n", "inst.mem");
	}

	char neuron_inst_string[3];
	int line_index = 3;
	uint16_t index = 0;
	uint8_t neuron_inst[256];
	int i = 0;

	while ((f_eof(fptr) == 0)){
		f_gets((char*)neuron_inst_string, sizeof(neuron_inst_string), fptr);
		f_lseek(fptr, line_index);
		line_index = line_index + 3;
		neuron_inst_string[3] = 0;
		neuron_inst[i] = strtol(neuron_inst_string, (char **)NULL, 16);
		i++;
	}

	#ifdef DEBUG
	for(int i = 0; i < 256; i++){
		printf("Neuron instructions %3d: 0x%x\n", i, neuron_inst[i]);
	}
	#endif
	
    do {
		if (!edabk_snn_snn_status_neuron_inst_wfull_read()) {
			edabk_snn_neuron_inst_wdata_write (neuron_inst[index]);		
			index++;
		}
	} while (index < 256);
	printf("Neuron instructions successful!!!\n\n");

}


void load_packet_in(void){
	FIL fptr[1];
	FRESULT op = f_open(fptr, "input.mem", FA_READ);

	if (op != FR_OK){
		printf("Could not open file: %s\n", "input.mem");
	}

	char value[6];
	int line_index = 6;
	uint16_t index = 0;
	uint32_t packet_in[22];
	int i = 0;

	while ((f_eof(fptr) == 0)){
		f_gets((char*)value, sizeof(value), fptr);
		f_lseek(fptr, line_index);
		line_index = line_index + 6;
		value[6] = 0;
		packet_in[i] = strtol(value, (char **)NULL, 16);
		i++;
	}

	#ifdef DEBUG
	for(int i = 0; i < 22; i++){
		printf("Packet in %3d: 0x%x\n", i ,packet_in[i]);
	}
	#endif
	
    do {
		if (!edabk_snn_snn_status_packet_wfull_read()) {
			edabk_snn_packet_wdata_write (packet_in[index]) ;		
			index++;
		}
	} while (index < 22);

}

void test_function(void){
	
	load_neuron_parameter();
	load_neuron_inst();
	load_packet_in();

	while (!edabk_snn_tick_ready_read()){
		printf("Waiting tick_ready!!!!!!!!\n");
	}

	edabk_snn_tick_ready_write(0);
	printf("\nTick ready!!!!!!!!\n");
	
	edabk_snn_tick_write(1);

	while(!edabk_snn_snn_status_wait_packets_read()){
		printf("Waiting!!!!!!!!\n");
	}
	printf("\nRead packet out!!!!!!!!\n");

	while (1)
	{
		if(!edabk_snn_snn_status_packet_out_rempty_read()){
			printf("Packet out: %x\n", edabk_snn_packet_out_read());
			edabk_snn_packet_out_rinc_write(1);
		}

		if (readchar_nonblock()) {
  			getchar();
  			break;
  		}
	}
}
