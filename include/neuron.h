#ifndef _NEURON_H_
#define _NEURON_H_

int ip_neuron_count = 1, op_neuron_count = 1, hn_layers = 1, tl_neurons = 3;
int* hn_layers_neuron_count;

typedef struct	{
	int input;
	int weight;
} Neuron;

// This contains all the network
Neuron* neuron;

// Used to return the o/p to user
float* output;

int init_network(int ip_neuron_count, int hn_layers, int* hn_layers_neuron_count, int op_neuron_count, int tl_neurons);
int destroy_network();

#endif
