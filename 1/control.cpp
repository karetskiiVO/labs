#include "control.h"

int check (int K, float *resistance, float resistance_final)
{
    double epsilon = 1e-1;
    double av_devation = 0;

    for (int i = 0; i < K; i++)
    {
        av_devation += (resistance[i] - resistance_final);
    }

    av_devation /= K;

    if (fabs (av_devation) < epsilon)
    {
        return 1;
    }
    return 0;
}
