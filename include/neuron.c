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
	free(output);

	if(neuron == NULL && hidden_layers_neuron_count == NULL && output == NULL)	{
		return 0;
	}
	else return 1;
}

// Function for providing i/p to NN
void assign_input(int* input)	{
	for(int i=0; i<ip_neuron_count; ++i)	{
		*(neuron+i)->input = *(input+i);
	}
}

// Function to get output after processing
float* get_output()	{
	output = (float*) malloc(sizeof(*output) * op_neuron_count);

	int op_offset = tl_neurons - op_neuron_count;

	for(int i=0; i<op_neuron_count; ++i)	{
		*(output+i) = *(neuron-op_offset+i)->input;
	}

	return output;
}

// TODO
/*
	Add feedforward function
	Add backup function
	Add restore function
	Add backpropagation function [but not now]
*/
