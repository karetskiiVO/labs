#ifndef FUNCTIONS
#define FUNCTIONS
#include <math.h>

#define MAX_SIZE 1000

double line_func(double *coef, double x);

double quadratic_func(double *coef, double x);

double exponential_func(double *coef, double x);

void ln_x(int n,double *x,double *ln_mas_x);

double approximation_exp_func(double *ceof,double *ln_mas_x);

void least_squares(int n,double *x,double *coef,double (*f)(double *coef, double x),double *error_coef);

#endif //functions.h