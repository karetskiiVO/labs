#include "security.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void account_encryption (int N, client * bank, client * bank_ciphr, key *ciphr);

void amount_encryption  (int N, client * bank, client * bank_ciphr, key *ciphr);

void code_encryption    (int N, client * bank, client * bank_ciphr, key *ciphr);

int resheto (int n) {
    size_t arrsize = n * ceil(log2(n * 1.0) + 10); 
    bool* arr = (bool*)calloc(arrsize, sizeof(bool));
    memset(arr, true, arrsize * sizeof(bool));
    int iter  = 0;
    int answ  = 0;
    for (int i = 2; i < arrsize; i++) {
        if (arr[i]) {
            for (int j = 2 * i; j < arrsize; j += i) {
                arr[j] = false;
            }
            iter++;
        }

        if (iter == n) {
            answ = i;
            break;
        }
    }
    free(arr);

    return answ;
}

int gcd (int n1, int n2) {
    if (n1 == 0) {
        return n2;
    }
    return gcd(n2%n1, n1);
}

long long int combination (int n, int m) {
    if (m == 0 || m == n) return 1;

    return combination(n - 1, m - 1) + combination(n - 1, m);
}

