#include "Computing.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

static double func_nonlin(double *radioactivity,
                          double *time, 
                          double decay_time,
                          int N)
{

    double res = 0;

    for(int i = 0;i < N;i++)
        {
        res += (time[i] * exp((-1) * time[i] / decay_time) ) * 
        (radioactivity[i] - exp((-1) * time[i] / decay_time));
        }


    return res;

}

static double func_lin(double *radioactivity,
                       double *time,
                       double decay_rate ,
                       int N)
{

    double res = 0;

    for (int i = 0; i < N;i++)
        {
        res += (time[i] * (radioactivity[i] - (1 - time[i] / decay_rate)));
        }
    return res;

}

double nonlinear_equation(double *radioactivity,
                          double *time ,
                          int N,
                          double precision)
{
    printf("input interval: ");
    double interval1 = 0,interval2 = 0;
    scanf("%lf %lf" , &interval1 , &interval2);
    assert(interval2 > interval1);

    double middle = 0 ;


    while (fabs(interval2 - interval1) > precision)
        {

        middle = (interval1 + interval2) / 2;

        double f1 = func_nonlin(radioactivity , time , interval1 , N);
        double f2 = func_nonlin(radioactivity , time, middle , N);


        if(f1 * f2 < 0)
            {
            interval2 = middle;
            }
        else
            {
            interval1 = middle;
            }
        }

    double f = func_nonlin(radioactivity , time , middle, N);
    assert(fabs(f) < precision);
    return middle;

}

double model(double *radioactivity , double *time , int N, double point)
{

    double medium_rad = 0,medium_time = 0,medium_time_rad = 0,medium_time_squre = 0;
    
    for (int i = 0; i < N; i++)
        {
        medium_rad += radioactivity[i];
        medium_time += time[i];
        medium_time_rad += (time[i] * radioactivity[i]);
        medium_time_squre += (time[i] * time[i]);
        }
    
    medium_rad = medium_rad / N;
    medium_time = medium_time / N;

    double a = (N * medium_time_rad - medium_rad * medium_time) / 
        (medium_time_squre - medium_time * medium_time);

    double b = (medium_rad - a * medium_time) / N;

    return a * point + b;
}

double linear_equation(double *radioactivity , double *time , int N)
{

    double decay_rate = 0,sum_time = 0,sum_rad = 0; 

    for (int i = 0; i < N; i++)
        {
        sum_time += (time[i] * time[i]);
        }
    
    for(int i = 0; i < N;i++)
        {
        sum_rad += (time[i] * (1 - radioactivity[i]));
        }

    decay_rate = sum_time / sum_rad;

    return decay_rate;

}