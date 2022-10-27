#ifndef FUNCTIONS
#define FUNCTIONS
#include <math.h>

double line_func(double *coef, double x);

double quadratic_func(double *coef, double x);

double exponential_func(double *coef, double x);

void line_equation(double *x,double (*f)(double x));



#endif //functions.h