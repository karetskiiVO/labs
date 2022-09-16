#include <math.h>
#include <stdio.h>
#include "control.h"

int check (int K, float *resistance, float resistance_final)
{
    double epsilon = 1e-4;
    double av_devation = 0;

    for (int i = 0; i < K; i++)
    {
        av_devation += (resistance[i] - resistance_final);
    }

    av_devation /= K;
    printf("Average deviation = %f\n", av_devation);

    if (fabs (av_devation) < epsilon)
    {
        return 1;
    }
    return 0;
}
