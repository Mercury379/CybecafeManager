#include"model.h"
#ifndef CARD_FILE_H
#define CARD_FILE_H
int saveCard(const Card* pCard, const char* pPath);
int readCard(CardNode* pCard, const char* pPath);
#endif 
