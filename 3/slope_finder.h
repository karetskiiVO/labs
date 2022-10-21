#ifndef SLOPE_FINDER
#define SLOPE_FINDER

void matrix_of_slopes(int N, struct position *ship, struct fig triangle, 
                      struct position port, float (*slopes)[4]);

#endif // slope_finder.h