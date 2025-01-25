#include"model.h"
#ifndef MONEY_SERVICE_H
#define MONEY_SERVICE_H
MoneyNode* ReturnMoneyList();
int InitMoneyList();
int addMoney(Money money);
MoneyNode* searchMoney(char ch[]);
int beforeMoneyExit();
#endif 