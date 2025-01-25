#include<string.h>
#include<stdlib.h>
#include"global.h"
#include"card_file.h"
#include"model.h"
#include"global.h"
#include"billing_file.h"
#include"service.h"

CardNode* cardList = NULL;

CardNode* ReturnCardList() {
	return cardList;
}

int InitCardList() {
	cardList = (CardNode*)malloc(sizeof(CardNode));
	Card card = { 0 };
	cardList->data = card;
	if (cardList != NULL) {
		cardList->next = NULL;
		readCard(cardList, CARDPATH);
		return 1;
	}
	return 0;
}

int addCard(Card card) {
	CardNode* cardNode = (CardNode*)malloc(sizeof(CardNode));
	cardNode->data = card;
	CardNode* p = cardList;
	while (p->next) {
		p = p->next;
	}
	p->next = cardNode;
	cardNode->next = NULL;
}
CardNode* searchCard(char ch[]) {
	CardNode* p = cardList;
	while (p) {
		if (strstr(p->data.Name, ch) != NULL) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
int deleteCard(char ch[]) {
	CardNode* p = cardList;
	int flag = 0;
	while (p) {
		if (strcmp(p->data.Name, ch) == 0) {
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag) {
		CardNode* q = cardList;
		while (q->next != p) {
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
	return flag;
}

int beforeCardExit() {
	saveCard(cardList, CARDPATH);
	CardNode* p = cardList;
	while (p) {
		CardNode* q = p;
		p = p->next;
		free(q);
	}
}

CardNode* doLogon(char* name,char* pwd) {
	CardNode* p = searchCard(name);
	if (numOfComputer() >= COMPUTERNUM) {
		printf("可用电脑已满，加入排队队列中……\n");
		EnQueue(p->data);
		return NULL;
	}
	if (p && strcmp(p->data.Pwd,pwd)==0) {
		p->data.Status = 1;
		p->data.UseCount++;
		p->data.LastUse = time(NULL);  //最后使用时间为当前时间
		return p;
	}
	else {
		return NULL;
	}
}
CardNode* doSettle(char* name, char* pwd) {
	CardNode* p = searchCard(name);
	if (p && strcmp(p->data.Pwd, pwd) == 0 && p->data.Status==1 ) {
		return p;
	}
	else {
		return NULL;
	}
}