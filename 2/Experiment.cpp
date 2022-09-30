#include "ExDispid.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int experiment (double* radioactivity, double* time, double start_time, double end_time, double step) {
    double const decay_time = 3.5;

    double t = start_time;
    int cnt;

    while (t <= end_time) {
        radioactivity[cnt] = exp(- t / decay_time);
        time[cnt] = t;

        cnt++;
        t += step;
    }
    
    return cnt;
}

void add_noise (double *radiactivity, int N) {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        radiactivity[i] += round(((double)rand() / (double)INT_MAX) * 1e5) / 1e5 * 0.05; 
    }
}