#include"model.h"
#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
CardNode* ReturnCardList();
int InitCardList();
int addCard(Card card);
CardNode* searchCard(char ch[]);
int deleteCard(char ch[]);
int beforeCardExit();
CardNode* doLogon();
CardNode* doSettle(char* name, char* pwd);
#endif 
