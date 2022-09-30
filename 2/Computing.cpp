#include <stdio.h>
#include <math.h>

static double func_nonlin(double *radioctivity, double *time, double decay_rate, int N)
{
    double res = 0;
    for(int i = 0;i < N;i++)
    {
        res += (time[i] * exp((-1) * time[i] / decay_rate) * (radioctivity[i] - exp((-1) * time[i] / decay_rate)));
    }
    return res;
}

static double func_lin(double *radioctivity, double *time, double decay_rate , int N)
{
    double res = 0;
    for (int i = 0; i < N;i++)
    {
        res += (time[i] * (radioctivity[i] - (1 - time[i] / decay_rate)));
    }
    return res;
}

double nonlinear_equation(double *radioctivity,double *time , int N, double precision)
{
    double interval1 = 0 , interval2 = 0;
    scanf("%lf %lf" , &interval1 , interval2);

    double f1=func_nonlin(radioctivity , time , interval1 , N);
    double middle = (interval1 + interval2) / 2.0;
    double f2=func_nonlin(radioctivity , time , middle , N);
    if (f1 * f2 <= 0)
    {
        interval2 = middle;
    }
    else
    {
        interval1 = middle;
    }

    while (fabs(interval2 - interval1) > precision)
    {
    middle = (interval1 + interval2) / 2.0;
    f1=func_nonlin(radioctivity , time , middle , N);
    if (fabs(f1) <= 0.0001)
    {
            return middle;
    }
    }
}
