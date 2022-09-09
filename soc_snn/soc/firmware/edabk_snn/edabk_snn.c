#include "edabk_snn.h"
#include "../sd/sd.h"
#include <generated/csr.h>
#include <stdlib.h>

void load_neuron_parameter(void){
    char parasdsm[10000];
	uint16_t index = 0;
    read_file("csram.mem", parasdsm);

	uint32_t param[256][11];

    do {
		if (!edabk_snn_snn_status_param_wfull_read()) {
			edabk_snn_param_wdata0_write  (param[index][0]) ;
			edabk_snn_param_wdata1_write  (param[index][1]) ;			
			edabk_snn_param_wdata2_write  (param[index][2]) ;			
			edabk_snn_param_wdata3_write  (param[index][3]) ;			
			edabk_snn_param_wdata4_write  (param[index][4]) ;			
			edabk_snn_param_wdata5_write  (param[index][5]) ;			
			edabk_snn_param_wdata6_write  (param[index][6]) ;			
			edabk_snn_param_wdata7_write  (param[index][7]) ;			
			edabk_snn_param_wdata8_write  (param[index][8]) ;			
			edabk_snn_param_wdata9_write  (param[index][9]) ;			
			edabk_snn_param_wdata10_write (param[index][10]);			
			edabk_snn_param_wdata11_write (param[index][11]);			
			index++;
		}
	} while (index < 256);
}

void load_neuron_inst(void){
    char neuron_inst_string[10000];
	uint16_t index = 0;
    read_file("neuron_inst.mem", neuron_inst_string);

	uint8_t neuron_inst[256];

    do {
		if (!edabk_snn_snn_status_neuron_inst_wfull_read()) {
			edabk_snn_neuron_inst_wdata_write (neuron_inst[index]) ;		
			index++;
		}
	} while (index < 256);
}


void load_packet_in(void){
    char packet_in_string[10000];
	uint16_t index = 0;
    read_file("neuron_inst.mem", packet_in_string);

	uint32_t packet_in[256];

    do {
		if (!edabk_snn_snn_status_packet_wfull_read()) {
			edabk_snn_packet_wdata_write (packet_in[index]) ;		
			index++;
		}
	} while (index < 256);
}
