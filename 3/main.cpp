#include "input.h"
#include "output.h"
#include "specialtypes.h"
#include "slope_finder.h"
#include "danger_identification.h"

#include <stdio.h>

#define SHIPS_NUMBER 100

int main () {
    position ships[SHIPS_NUMBER];
    int counter = 0;
    scanf("%d", &counter);
    input_ship(counter, ships);
    fig triangle = input_triangle();
    position port = input_port();

    float slopes[SHIPS_NUMBER][4];
    matrix_of_slopes(counter, ships, triangle, port, slopes);
    int danger[SHIPS_NUMBER];
    danger_identification(counter, slopes, danger);

    danger_signal(counter, danger);
    return 0;
}