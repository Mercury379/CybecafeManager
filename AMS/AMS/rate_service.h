#include"model.h"
#ifndef RATE_SERVICE_H
#define RATE_SERVICE_H
RateNode* ReturnRateList();
int InitRateList();
int addRate(Rate rate);
RateNode* searchRateNow();
int beforeRateExit();
void UpdateRate();
#endif 
