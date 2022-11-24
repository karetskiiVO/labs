#include "security.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void account_encryption (int N, client* bank, client* bank_ciphr, key* ciphr) {
    for (int i = 0; i < N; i++) {
        char* ptr = NULL;
        char str[1000] = "";
        int a1, a2;

        sprintf(str, "%lld", bank[i].identification_number);

        int len = strlen(str);
        for (int i = len - 1; i >= 1; i--) {
            if (str[i] != '0' && str[i - 1] != '0') {
                a1 = str[i] - '0' + str[i - 1] - '0';
                break;
            }
        }

        ptr = strrchr(str, '0');
        while (ptr) {
            strcpy(ptr, ptr + 1);
            ptr = strrchr(str, '0');
        }    
        a2 = str[1] -'0';

        ciphr[i].key_1 = a2 * resheto(a1); 

        bank_ciphr[i].amount = bank[i].amount + ciphr[i].key_1;
    }
}

void amount_encryption  (int N, client* bank, client* bank_ciphr, key* ciphr) {
    for (int i = 0; i < N; i++) {
        char* ptr = NULL;
        char str[1000] = "";
        int a1, a2, a3;

        sprintf(str, "%lld", bank[i].identification_number);

        ptr = strrchr(str, '0');
        while (ptr) {
            strcpy(ptr, ptr + 1);
            ptr = strrchr(str, '0');
        }    
        
        a1 = str[3] - '0';
        //////////////////
        sscanf(str, "%d", &a2);
        a2 %= 1000;
        str[3] = '\0';
        sscanf(str, "%d", &a3);
        
        ciphr[i].key_2 = a1 * gcd(a2, a3);

        bank_ciphr[i].amount = bank[i].amount + ciphr[i].key_2;
    }
}

void code_encryption    (int N, client* bank, client* bank_ciphr, key* ciphr) {
    for (int i = 0; i < N; i++) {
        char str[1000] = "";
        int a1 = 0, a2 = 0, a3 = 0;

        sprintf(str, "%lld", bank[i].identification_number);

        int len = strlen(str);

        for (int i = 0; i < 3; i++) {
            a1 += str[len - 1 - i] - '0';
        }

        if (a1 == 0) {
            a1 = 27;
        } 

        sprintf(str, "%d%c", bank[i].code, '\0');

        a2 = str[0] - '0';
        if (a1 < a2) {
            a3 = a2;
            a2 = a1;
            a1 = a3;
        }

        ciphr[i].key_3 = combination(a1, a2);

        bank_ciphr[i].amount = bank[i].amount + ciphr[i].key_3;   
    }
}

int resheto (int n) {
    int arrsize = n * ceil(log2(n * 1.0) + 10); 
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
    return gcd(n2 % n1, n1);
}

long long int combination (int n, int m) {
    if (m == 0 || m == n) return 1;

    return combination(n - 1, m - 1) + combination(n - 1, m);
}

