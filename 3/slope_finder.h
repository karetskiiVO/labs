#ifndef SLOPE_FINDER
#define SLOPE_FINDER

void matrix_of_slopes(int N, struct position *ship, struct fig triangle, 
                      struct position port, float (*slopes)[4]);

void danger_identification(int N,float (*slopes)[4],int *danger);

#endif // slope_finder.h