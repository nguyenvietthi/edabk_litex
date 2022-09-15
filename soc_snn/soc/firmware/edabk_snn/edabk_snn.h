#ifndef __EDABK_SNN
#define __EDABK_SNN

#include <stdio.h>

void load_neuron_parameter(void);
void load_neuron_inst(void);
void load_packet_in(const char* path, uint8_t num_inputs);
void handling_packets(const char* path, uint8_t num_inputs);
void test_function(void);
#endif 