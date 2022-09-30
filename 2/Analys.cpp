#include "Analys.h"

#include <math.h>
#include <stdio.h>

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
    double sum_residuals1 = 0;

    for (int i = 0; i < M; i++)
    {
        sum_residuals1 += pow (radioactivity[i] - exp( - (time[i] / decay_time)), 2);
    }

    double deviation1 = sqrt (sum_residuals1) / M;

    return deviation1;
}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    double sum_residuals2 = 0;

    for (int i = 0; i < M; i++)
    {
        sum_residuals2 += pow (radioactivity[i] - (1 - (time[i] / decay_rate)), 2);
    }

    double deviation2 = sqrt (sum_residuals2) / M;

    return deviation2;
}

double precision_analysis (double *radioactivity, double *time, int N)
{

    double time_differences = 0;
    for (int M = 10; M < N; M++)
    {
        double decay_rate = 0;
        double nom = 0;
        double denom = 0;
        for (int i = 0; i < M; i++)
        {
            nom  += pow (time[i], 2);
            denom += time[i] * (1 - radioactivity[i]);
        }
        decay_rate = nom / denom;

        double decay_time = 0;
        for (int i = 0; i < M; i++)
        {
            decay_time = time[i] / - log (radioactivity[i]);
        }
        decay_time /= M;

        double deviation1 = dev_exp (radioactivity, time, M, decay_time);
        double deviation2 = dev_linear (radioactivity, time, M, decay_rate);

        if (deviation2 > deviation1 * 2)
        {
            double time_differences = time[M];
            return time_differences;
        }
    }

    printf("Error in precision_analysis\n");
    return 0;
}

