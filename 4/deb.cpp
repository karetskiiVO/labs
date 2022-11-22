#include "security.h"

#include <stdio.h>

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", combination(n, m));
    return 0;
}