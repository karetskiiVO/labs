#include "Experiment.h"
#include "Computing.h"
#include "Analys.h"

#include <stdio.h>

#define datread(var) printf("input %s\t\t\t ", #var);scanf("%lg", &(var))

int main () {
    double time[100] = {0};
    double radiactivity[100] = {0};

    double starttime, endtime, step, precision;

    datread(starttime);
    datread(endtime);
    datread(step);
    datread(precision);

    int num_data = experiment(radiactivity, time, starttime, endtime, step);
    add_noise(radiactivity, num_data);

    double decay_time = nonlinear_equation (radiactivity, time, num_data, precision);
    double decay_rate = linear_equation(radiactivity,time,num_data);

    double time_differences = precision_analysis (radiactivity, time, num_data);

    printf("decay_time: %lg\ndecay_rate: %lg\ntime_differences: %lg\n", decay_time, decay_rate, time_differences);

    return 0;
}
