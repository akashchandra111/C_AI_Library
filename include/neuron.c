#include "neuron.h"
#include <malloc.h>

// Generates neural net assignes values to variable for keeping track and returns 0 if NN is successfully created
int init_network(int input_neuron_count, int hidden_layers, int* hidden_layers_neuron_count, int output_neuron_count, int total_neurons)	{

	// Assigning to local variables for operations
	ip_neuron_count = input_neuron_count;
	op_neuron_count = output_neuron_count;
	hn_layers = hidden_layers;
	hn_layers_neuron_count = hidden_layers_neuron_count;
	tl_neurons = total_neurons;

	neuron = (Neuron*) malloc(sizeof(*neuron) * tl_neurons);

	if(neuron != NULL)	{
		return 0;
	}
	else 	{
		return 1;
	}
}

// Returns 0 if neural network is successfully exited
int destroy_network()	{
	free(neuron);
	free(hidden_layers_neuron_count);

	if(neuron == NULL && hidden_layers_neuron_count == NULL)	{
		return 0;
	}
	else return 1;
}
