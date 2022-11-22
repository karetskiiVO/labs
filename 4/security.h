#pragma once

#include "banktypes.h"

void account_encryption (int N, client * bank, client * bank_ciphr, key *ciphr);

void amount_encryption  (int N, client * bank, client * bank_ciphr, key *ciphr);

void code_encryption    (int N, client * bank, client * bank_ciphr, key *ciphr);

int resheto (int n);

int gcd (int n, int m);

long long int combination (int n, int m);






