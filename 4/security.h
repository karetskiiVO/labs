#pragma once

#include "banktypes.h"

void account_encryption (int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr);

void amount_encryption  (int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr);

void code_encryption    (int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr);

int resheto (int n);

int nod (int n, int n1);

long long int combination (int n, int m);






