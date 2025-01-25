#include"model.h"
#ifndef BILLING_SERVICE_H
#define BILLING_SERVICE_H
BillingNode* ReturnBillingList();
int InitBillingList();
int addBilling(Billing billing);
BillingNode* searchBilling(char ch[]);
double getAmount(BillingNode* p);
int beforeBillingExit();
int numOfComputer();
#endif 