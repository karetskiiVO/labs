#include "functions.h"

double line_func(double *coef, double x) // линейная функция 
{
    return coef[0] * x + coef[1];
}

double quadratic_func(double *coef,double x) //квадратичная функция 
{
    return coef[0] * x * x + coef[1] * x + coef[2];
}

double exponential_func(double *coef, double x) // показательная функция 
{
    return pow(coef[0],coef[1] * x + coef[2]);
}

void least_squares(int n,double *x,double *coef,double (*f)(double *coef, double x)) //мнк 
{
    double medium_x = 0,medium_y = 0; // cреднее значения x и y начало 
    double sum_product = 0; // сумма значений произведения x и y начало
    double squre_sum_x = 0, squre_sum_y = 0; // сумма значений квадратов x и y 
    double sum_x = 0, sum_y = 0; // сумма значений x и y
    for (int i = 0; i < n ; i++)
    {
        sum_x += x[i];
        sum_y += f(coef, x[i]);
        sum_product += (x[i] * f(coef, x[i]));
        squre_sum_x += (x[i] * x[i]);
        squre_sum_y += (f(coef, x[i]) * f(coef, x[i]));
    }

    double a = (n * sum_product - sum_x * sum_y) / (n * squre_sum_x - sum_x * sum_x); //первый коэф мнк 
    double b = (sum_y - a * sum_x) / n; //второй коэф мнк

    double medium_squre_sum_x = squre_sum_x / n, medium_squre_sum_y = squre_sum_y / n;// средние квадраты 
    double Sx = medium_squre_sum_x - medium_x * medium_x;
    double Sy = medium_squre_sum_y - medium_y * medium_y;

    double delta_a = 2 * sqrt((Sy / Sx - a) / (n-2));//погрешность для а
    double delta_b = delta_a * sqrt(Sx + medium_x * medium_x);
}