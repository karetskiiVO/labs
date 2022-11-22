#ifndef DECRYPTION
#define DECRYPTION

void decryption(int N, 
                client* bank_ciphr, 
                client* bank_new, 
                key* cipher, 
                balance* total_balance,
                currency* val);

#endif // decryption.h