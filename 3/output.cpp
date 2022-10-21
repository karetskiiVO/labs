#include "output.h"

#include <stdio.h>

void danger_signal (int N, int *danger) {
    for (int i = 0; i < N; i++) {
        printf("%d\t%s\n", i, (danger[i]) ? ("YES\a") : ("No"));
    }
}