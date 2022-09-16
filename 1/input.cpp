#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "input.h"

int preparation (float* resistance)
{
    assert(resistance != NULL);

    int number_elems = 0;

    float voltage = 0;
    float current = 0;
    while (scanf("%f%*c%f", &voltage, &current) && number_elems < MAX_SIZE)
    {
        *resistance = 1000 * voltage / current;
        resistance++;

        number_elems++;
    }

    return number_elems;
}
