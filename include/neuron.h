//
//	Neuron creation first attempt
//	By : Akash Chandra 		A.K.A.	$KY;
//
//
#ifndef _NEURON_H_
#define _NEURON_H_

typedef struct {
	int weight;
	float sum;
}Neuron;

typedef struct {
	Neuron* in;
}Input_Layer;

typedef struct {
	Neuron* hid;
}Hidden_Layer;

typedef struct {
	Neuron* out;
}Output_Layer;
//Input Layer initialize
Input_Layer* _init_input(int total_input);
//Output Layer initialize
Output_Layer* _init_output(int total_output);
//Hidden Layer initialize
Hidden_Layer** _init_hidden(int total_hidden_layers,int total_hidden);
void _destroy(Input_Layer**,Output_Layer**,Hidden_Layer***,int total_hidden_layer);
#endif
