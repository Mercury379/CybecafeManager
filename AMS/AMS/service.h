#include<time.h>
#ifndef SERVICE_H
#define SERVICE_H
int InitQueue();
int EnQueue(Card e);
int DeQueue(Card* e);
CardNode* GetHead();
LinkQueue ReturnQueue();
#endif