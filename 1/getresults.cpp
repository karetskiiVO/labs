#include <stdio.h>
#include "getresults.h"
#include <math.h>

float results(int K, float *resistance){
    float resistance_final = 0 ;
    float deviation = 0;
    for (int i = 0; i < K ;i++){
        resistance_final += resistance[i];
    }
    resistance_final /= K;
    for (int i = 0; i < K; i++){
        deviation += (resistance_final - resistance[i]) * (resistance_final - resistance[i]);
    }
    deviation = sqrt(deviation) / K;
    printf("%f ± %f", resistance_final,deviation);
    printf("\n");
    return resistance_final;
}