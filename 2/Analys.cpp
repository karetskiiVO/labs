#include "Analys.h"

int main (void)
{
    return 0;
}

double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
    double sum_residuals1 = 0;

    for (int i = 0; i < M; i++)
    {
        sum_residuals1 += pow (radioactivity[i] - pow (M_E, - (time[i] / decay_time)), 2);
    }

    double deviation1 = sqrt (sum_residuals1) / M;

    return deviation1;
}

double dev_linear(double *radioaktivity, double *time, int M, double decay_rate)
{
    double sum_residuals2 = 0;

    for (int i = 0; i < M; i++)
    {
        sum_residuals2 += pow (radioaktivity[i] - (1 - (time[i] / decay_rate)), 2);
    }

    double deviation2 = sqrt (sum_residuals2) / M;

    return deviation2;
}

double precision_analysis (double *radioaktivity, double *time, int N, double decay_time, double decay_rate)
{
    double time_differences = 0;
    for (int M = 1; M < N; N++)
    {
        double deviation1 = dev_exp (radioaktivity, time, M, decay_time);
        double deviation2 = dev_linear (radioaktivity, time, M, decay_rate);

        if (deviation2 > deviation1 * 2)
        {
            double time_differences = time[M];
            return time_differences;
        }
    }

    printf("Error in precision_analysis\n");
    return 0;
}

