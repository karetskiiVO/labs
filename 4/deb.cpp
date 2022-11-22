#include "security.h"

#include <stdio.h>
#include <string.h>

int main () {
    long n;
    scanf("%ld", &n);

    char* ptr = NULL;
    char str[1000] = "";
    sprintf(str, "%ld", n);
    

    printf("%s\n", str);


    return 0;
}