#include <stdio.h>
#include "banktypes.h"
#include "enter.h"
#include "security.h"
#include "decryption.h"
#include "verification.h"

int main() {
  int N = 0;
  scanf("%d", &N);
  const int CLIENT_NUMBER = 10000;
  currency val[5];
  client bank[CLIENT_NUMBER];
  client bank_ciphr[CLIENT_NUMBER];
  client bank_new[CLIENT_NUMBER];
  key ciphr[CLIENT_NUMBER];
  balance total_balance;
  currency_reference(val);
  for (int i = 0; i < 5; ++i) {
    printf("Currency name - %s\tLeter code - %s\tCurrency code - %d\n", 
           val[i].currency_name, val[i].leter_code, val[i].currency_code);
  }
  customer_base(N, bank, val, &total_balance);
  account_encryption(N, bank, bank_ciphr, ciphr);
  amount_encryption(N, bank, bank_ciphr, ciphr);
  code_encryption(N, bank, bank_ciphr, ciphr);
  for (int i = 0; i < N; ++i) {
    printf("Index - %d\tFirst key - %d\tSecond key - %d\tThird key - %d\n",
           i, ciphr[i].key_1, ciphr[i].key_2, ciphr[i].key_3);
  }
  for (int i = 0; i < N; ++i) {
    printf("Index - %d\tIdentification number - %lld\tAccount - %d\tAmount - %d\tCode - %d\n",
           i, bank_ciphr[i].identification_number, bank_ciphr[i].account, bank_ciphr[i].amount, bank_ciphr[i].code);
  }
  decryption(N, bank_ciphr, bank_new, ciphr, &total_balance, val);
  if (!verification(N, bank, bank_new)) 
    return 1;
  if (!check(&total_balance))
    return 1;
  return 0;
}