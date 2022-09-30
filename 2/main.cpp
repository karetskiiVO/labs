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

    double time_differences = precision_analysis (radioactivity, time, 100);


    return 0;
}
