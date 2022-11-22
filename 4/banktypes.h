#pragma once

enum CURENCY {
    CUR_USD,
    CUR_RUB,
    CUR_EUR,
    CUR_GBP,
    CUP_CNY
};


typedef struct {
    char currency_name[10];
    char leter_code[4];
    int currency_code;
}  currency;

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



