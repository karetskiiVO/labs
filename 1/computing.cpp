#include <stdio.h>
#include <math.h>
#include "computing.h"

int data_select(int M, float *resistance)
{
	double resistance_average = 0;
	int current_element = 0;
	const double EPS = 3e-2;

	for (int i = 0; i < M; i++)
	{
		resistance_average += *(resistance + i);
	}
	resistance_average /= M;

	for (int i = 0; i < M; i++) 
	{
		if (fabs(*(resistance + i) - resistance_average) / resistance_average <= EPS)
		{
			*(resistance + current_element) = *(resistance + i);
			++current_element;
		}
	}

	return current_element + 1;
}