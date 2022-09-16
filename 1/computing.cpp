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
		if (fabs(*(resistance + i) - resistance_average) <= EPS * resistance_average)
		{
			*(resistance + current_element) = *(resistance + i);
			++current_element;
		}
	}

	for (int i = current_element; i < M; i++)
	{
		*(resistance + i) = 0;
	}

	return current_element;
}