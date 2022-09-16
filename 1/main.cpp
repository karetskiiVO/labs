#include "computing.h"
#include "control.h"
#include "getresults.h"
#include "input.h"

#include <stdio.h>

int main () {
    float resistance[100];

    int expcnt = preparation(resistance);
    int rescnt = data_select(expcnt, resistance);

    float resistance_final = results(rescnt, resistance);
    printf("%d\n", check(rescnt, resistance, resistance_final));

    return 0;
}