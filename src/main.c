#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/neuron.h"

int main(int argc, char** argv)	{

	// Checking the number of arguments
	if(argc < 4)	{
		printf("Usage: %s input_layer hidden layer/s output_layer\n", argv[0]);
		exit(-1);
	}

	// Converting the ascii values to ints for total layer
	int total_neurons = 0;
	Neuron* neuron;
	
	for(int i=1; i<argc-1; ++i)	total_neurons += atoi(argv[i]);

	//Assigning total neurons to memory
	neuron = (Neuron*) malloc(sizeof(*neuron) * (total_neurons));
	
	if(neuron == NULL)	{
		// If neurons are not available exit from the program
		printf("Sufficient memory isn't available, exiting...\n");
		exit(-1);
	}

	int ip_layer_count = atoi(argv[1]);
	int op_layer_count = atoi(argv[argc-1]);
	int *hidden_layer_count = (int*) malloc(sizeof(*hidden_layer_count) * (argc - 3));

	for(int i=2, j=0; i<argc-1; ++i, ++j)	{
		hidden_layer_count[j] = atoi(argv[i]);
	}

	printf("Input Layer neurons: %d\n", ip_layer_count);
	printf("Output Layer neurons: %d\n", op_layer_count);
	printf("Hidden Layer neurons: ");
	
	// Hidden layers would be total_args - (program_name + ip_layer_count + op_layer_count);
	for(int i=0; i<argc-3; ++i)	{
		printf("%d ", hidden_layer_count[i]);
	}
	printf("\n");

	free(neuron);
	free(hidden_layer_count);

	if(neuron == NULL)	printf("Neuron memory freed...");
	if(hidden_layer_count == NULL)	printf("Hidden Layer memory freed...");

	return 0;
}
