#include <stdio.h>
#include "getresults.h"
#include <math.h>

float results(int K, float *resistance){
    double resistance_final = 0 ;
    double deviation = 0;
    for (int i = 0; i < K ;i++){
        resistance_final += resistance[i];
    }
    resistance_final /= K;
    for (int i = 0; i < K; i++){
        deviation += pow(resistance_final - resistance[i] , 2) ;
    }
    deviation = sqrt(deviation) / K;
    printf("%f ± %f", resistance_final,deviation);
    printf("\n");
    return (float)resistance_final;
}