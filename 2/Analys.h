#ifndef ANALYS
#define ANALYS

#include <math.h>
#include <stdio.h>

double precision_analysis (double *radioaktivity, double *time, int N, double decay_time, double decay_rate);
double dev_exp(double *radioactivity, double *time, int M, double decay_time);
double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);

#endif // Analys.h
