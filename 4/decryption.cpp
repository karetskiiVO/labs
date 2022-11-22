#include "banktypes.h"
#include "decryption.h"
#include <stdio.h>

void decryption(int N,
                client* bank_ciphr,
                client* bank_new,
                key* cipher,
                balance* total_balance,
                currency* val)
{
    for (int i = 0; i < N; ++i)
    {
        (bank_new + i)->identification_number = (bank_ciphr + i)->identification_number - (cipher + i)->ind_num;
        (bank_new + i)->account = (bank_ciphr + i)->account - (cipher + i)->key_1;
        (bank_new + i)->amount = (bank_ciphr + i)->amount - (cipher + i)->key_2;
        (bank_new + i)->code = (bank_ciphr + i)->code - (cipher + i)->key_3;

        if((bank_new + i)->code == (val + 0)->currency_code)
        {
            total_balance->currency_cipher[0] += (bank_new + i)->amount;
        }
        else if((bank_new + i)->code == (val + 1)->currency_code)
        {
            total_balance->currency_cipher[1] += (bank_new + i)->amount;
        }
        else if((bank_new + i)->code == (val + 2)->currency_code)
        {
            total_balance->currency_cipher[2] += (bank_new + i)->amount;
        }
        else if((bank_new + i)->code == (val + 3)->currency_code)
        {
            total_balance->currency_cipher[3] += (bank_new + i)->amount;
        }
        else 
        {
            total_balance->currency_cipher[4] += (bank_new + i)->amount;
        }
    }

    for (int j = 0; j < 5; ++j)
    {
        printf("Cur_name- %s\tLetter_name- %s\tCode- %d\tStart_amount- %d\tCipher_amount- %d",
        (val + j)->currency_name, (val + j)->leter_code, (val + j)->currency_code, 
         total_balance->currency_start[j], total_balance->currency_cipher[j]);
    }

}