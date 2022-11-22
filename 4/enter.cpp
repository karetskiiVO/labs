#include "enter.h"
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
        strcpy (val[i].currency_name, currency_name_buf);
        strcpy (val[i].leter_code, leter_code_buf);
        val[i].currency_code = currency_code_buf;
    }
}
