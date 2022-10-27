#include <stdio.h>
#include "functions.h"

int main(void)
{
    double x[MAX_SIZE]; // массив x 
    int n = 0; 
    scanf("%d",&n);
    printf("enter x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    printf("enter coef\n"); 
    double coef[3];  // массив коэф
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf", &coef[i]);
    }

    double ln_mas_x[MAX_SIZE]; //массив ln(x)
    return 0;
}