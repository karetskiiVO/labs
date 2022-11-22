#include "enter.h"
#include "banktypes.h"
#include <stdio.h>
#include <string.h>

void currency_reference (currency *val)
{
    char currency_name_buf[10];
    char leter_code_buf[4];
    int currency_code_buf;
    for (int i = 0; i < 5; i++)
    {
        scanf ("%s %s %d", currency_name_buf, leter_code_buf, &currency_code_buf);
        strcpy ((val+i)->currency_name, currency_name_buf);
        strcpy ((val+i)->leter_code, leter_code_buf);
        (val+i)->currency_code = currency_code_buf;
    }
}

void customer_base (int N, client *bank, currency *val, balance *total_balance)
{
    long long int id_num_buf;
    int account_buf;
    int amount_buf;
    int code_buf;
    int n_buf;

    int i = 0;
    int code_flag = 0;
    while (i < N)
    {
        code_flag = 0;
        scanf ("%d %lld %d %d %d", &n_buf, &id_num_buf, &account_buf, &amount_buf, &code_buf);
        for (int j = 0; j < 5; j++)
        {
            if (code_buf == (val+j)->currency_code)
            code_flag = 1;
        }
        if (code_flag == 0)
        {
            printf ("wrong code in customer base, try again\n");
            continue;
        }
        else
        {
        (bank+i)->identification_number = id_num_buf;
        (bank+i)->account = account_buf;
        (bank+i)->amount = amount_buf;
        (bank+i)->code = code_buf;
        i++;
        }
    }
}
