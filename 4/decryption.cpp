#include "decryption.h"
#include "banktypes.h"
#include <stdio.h>

void decryption(int N,
                client* bank_ciphr,
                client* bank_new,
                key* cipher,
                balance* total_balance,
                currency* val)
{
    for (int i = 0; i < N; i++)
    {
        (bank_new + i)->identification_number = (bank_ciphr + i)->identification_number - (cipher + i)->ind_num;
        (bank_new + i)->account = (bank_ciphr + i)->account - (cipher + i)->key_1;
        (bank_new + i)->amount = (bank_ciphr + i)->amount - (cipher + i)->key_2;
        (bank_new + i)->code = (bank_ciphr + i)->code - (cipher + i)->key_3;

        for (int j = 0; j < 5; j++)
        {
            int tmp = (val + j)->currency_code;
            (total_balance + i)->currency_cipher[j] += (tmp * (bank_new + i)->amount); 
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", (total_balance + i)->currency_cipher[j]);
        }
        printf("\n");
    }

}