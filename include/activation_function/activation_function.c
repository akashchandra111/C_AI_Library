#include <math.h>
#include "activation_function.h"

// Typical sigmoid function the most commonly used function for activation of neurons
float sigmoid(float sum)	{
	return (1 / (1 + exp(-sum)));
}
