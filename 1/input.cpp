#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "input.h"

int preparation (float* resistance)
{
    assert(resistance != NULL);

    int number_elems = 0;

    float voltage = NAN;
    float current = NAN;
    while (scanf("%f%*c%f", &voltage, &current) && number_elems < MAX_SIZE && resistance != NULL)
    {
        voltage *= 1000;
        *resistance = voltage / current;
        resistance++;

        number_elems++;
    }

    return number_elems;
}
