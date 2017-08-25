#include <malloc.h>
#include "neuron.h"

Input_Layer* _init_input(int total_input)	{
	Input_Layer* input = malloc(total_input * sizeof(*input));
	if (input == NULL)	fprintf(stderr,"Error Creating Input Layer\nMemory not allocated successfully.");	
	else return input;
}

Output_Layer* _init_output(int total_output)	{
	Output_Layer* output = malloc(total_output * sizeof(*output));
	if (output == NULL)	fprintf(stderr,"Error Creating Output Layer\nMemory not allocated successfully.");	
	else return output;
}

Hidden_Layer** _init_hidden(int total_hidden_layers,int total_hidden)	{
	Hidden_Layer** hidden_layer = malloc(total_hidden_layers * sizeof(*hidden_layer));
	for (int i=0 ; i<total_hidden_layers ; i++)	{
		 hidden_layer[i] = malloc(total_hidden * sizeof(**hidden_layer));
	}
	if (hidden_layer == NULL)	fprintf(stderr,"Error Creating Hidden Layer\nMemory not allocated successfully.");	
	else return hidden_layer;
}

void _destroy(Input_Layer** input,Output_Layer** output,Hidden_Layer*** hidden,int total_hidden_layer)	{
	if (*input != NULL)	free(*input);
	if(*output != NULL)	free(*output);
	if(*hidden != NULL)	{
	for (int i=0 ; i<total_hidden_layer ; i++)	{
		free(*hidden[i]);
	}
	free(*hidden);
	}	
}

