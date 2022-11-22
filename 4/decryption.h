#ifndef DECRYPTION
#define DECRYPTION

void decryption(int N, 
                struct client* bank_ciphr, 
                struct client* bank_new, 
                struct key* shiphr, 
                struct balans* total_balans);

#endif // decryption.h