#include "edabk_snn.h"
#include "../sd/sd.h"
#include <generated/csr.h>
#include <stdlib.h>
#include <string.h>

void load_neuron_parameter(void){
    char param_string[23809];
	uint16_t index = 0;
    read_file("csram.mem", param_string);
	
	uint32_t param[256][12];
	char value[9];
	for(int i = 0; i < 256; i++){
		for (int j = 0; j < 12; j++){
			if(j == 0){
            	strncpy(value, param_string + i * 93, 4);
            	value[4] = 0; 
        	} else{
            	strncpy(value, param_string + i * 93 + 4 + (j - 1) * 8, 8);
            	value[8] = 0; 
       		}
			param[i][j] = strtol(value, (char **)NULL, 16);
		}
	}
	#ifdef DEBUG
	for(int i = 0; i < 256; i++){
		printf("parameter %d: %x %x %x %x %x %x %x %x %x %x %x %x \n", i, param[i][0],param[i][1],param[i][2],param[i][3],param[i][4],param[i][5], param[i][6] ,param[i][7],param[i][8],param[i][9],param[i][10],param[i][11]);
	}
	#endif

    do {
		if (!edabk_snn_snn_status_param_wfull_read()) {
			edabk_snn_param_wdata0_write  (param[index][11]) ;
			edabk_snn_param_wdata1_write  (param[index][10]) ;			
			edabk_snn_param_wdata2_write  (param[index][9]) ;			
			edabk_snn_param_wdata3_write  (param[index][8]) ;			
			edabk_snn_param_wdata4_write  (param[index][7]) ;			
			edabk_snn_param_wdata5_write  (param[index][6]) ;			
			edabk_snn_param_wdata6_write  (param[index][5]) ;			
			edabk_snn_param_wdata7_write  (param[index][4]) ;			
			edabk_snn_param_wdata8_write  (param[index][3]) ;			
			edabk_snn_param_wdata9_write  (param[index][2]) ;			
			edabk_snn_param_wdata10_write (param[index][1]);			
			edabk_snn_param_wdata11_write (param[index][0]);			
			index++;
		}
	} while (index < 256);
}

void load_neuron_inst(void){
    char neuron_inst_string[769];
	uint16_t index = 0;
    read_file("neuron_inst.mem", neuron_inst_string);

	uint8_t neuron_inst[256];
	char value[3];
	for (int i = 0; i < 256; i++){
		strncpy(value, neuron_inst_string + i * 3, 2);
		neuron_inst[i] = strtol(value, (char **)NULL, 16);
	}

	#ifdef DEBUG
	for(int i = 0; i < 256; i++){
		printf("inst %d: %x\n", i,neuron_inst[i]);
	}
	#endif
	
    do {
		if (!edabk_snn_snn_status_neuron_inst_wfull_read()) {
			edabk_snn_neuron_inst_wdata_write (neuron_inst[index]) ;		
			index++;
		}
	} while (index < 256);
}


void load_packet_in(void){
    char packet_in_string[133];
	uint16_t index = 0;
    read_file("tb_input.txt", packet_in_string);

	uint32_t packet_in[22];
	char value[6];
	for (int i = 0; i < 6; i++){
		strncpy(value, packet_in_string + i * 6, 5);
		packet_in[i] = strtol(value, (char **)NULL, 16);
	}
	
	#ifdef DEBUG
	for(int i = 0; i < 22; i++){
		printf("packet in %d: %x\n", i,packet_in[i]);
	}
	#endif

    do {
		if (!edabk_snn_snn_status_packet_wfull_read()) {
			edabk_snn_packet_wdata_write (packet_in[index]) ;		
			index++;
		}
	} while (index < 22);
}
