#include <stdio.h>
#include "banktypes.h"
#include "verification.h"

int verification(int N, client* bank, client* bank_new) {
  for (int i = 0; i < N; ++i) {
    if ((bank + i)->identification_number != (bank_new + i)->identification_number) {
      printf("Error in identification number of client %d\n", i);
      return 0;
    } if ((bank + i)->account != (bank_new + i)->account) {
        printf("Error in account of client %d\n", i);
        return 0;
    } if ((bank + i)->amount != (bank_new + i)->amount) {
        printf("Error in amount of client %d\n", i);
        return 0;
    } if ((bank + i)->code != (bank_new + i)->code) {
        printf("Error in code of client %d\n", i);
        return 0;
    } 
  } 
  return 1;
}

int check(balance* total_balance) {
  for (int i = 0; i < 5; i++) {
    if (total_balance->currency_start[i] != total_balance->currency_cipher[i]) {
      printf("Error in %d", i);
      return 0;
    }
  }
  return 1;
}