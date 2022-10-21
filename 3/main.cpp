#include "input.h"
#include "specialtypes.h"
#include "slope_finder.h"
#include "danger_identification.h"

#include <stdio.h>

#define SHIPS_NUMBER 100

int main () {
    position ships[SHIPS_NUMBER] = {0};
    int counter = 0;
    scanf("%d", &counter);
    input_ship(counter, ships);



    return 0;
}