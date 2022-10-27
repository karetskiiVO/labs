#include <stdio.h>

#define MAX_SIZE 1000

int main(void)
{
    double x[MAX_SIZE];
    int n = 0; 
    scanf("%d",&n);
    printf("enter x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", x[i]);
    }

    printf("enter coef\n");
    double coef[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &coef[i]);
    }

    return 0;
}