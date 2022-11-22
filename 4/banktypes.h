#pragma once

enum CURENCY {
    CUR_RUB = 1,
    CUR_USD = 2,
    CUR_EUR = 3,
    CUR_GBP = 4,
    CUP_CNY = 5
};


typedef struct {
    char currency_name[10];
    char leter_code[4];
    int currency_code;
} currency;

typedef struct {
    long long int identification_number;
    int account;
    int amount;
    int code;
} client;

typedef struct {
    int ind_num;
    int key_1;
    int key_2;
    int key_3;
} key;

typedef struct {
    int currency_start[5];
    int currency_cipher[5];
} balance;





