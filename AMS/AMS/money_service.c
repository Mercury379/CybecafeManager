#include<string.h>
#include<stdlib.h>
#include"global.h"
#include"money_file.h"
#include"model.h"
#include"global.h"
#include"money_service.h"

MoneyNode* moneyList = NULL;

MoneyNode* ReturnMoneyList() {
	return moneyList;
}

int InitMoneyList() {
	moneyList = (MoneyNode*)malloc(sizeof(MoneyNode));
	Money money = { 0 };
	moneyList->data = money;
	if (moneyList != NULL) {
		moneyList->next = NULL;
		readMoney(moneyList, MONEYPATH);
		return 1;
	}
	return 0;
}

int addMoney(Money money) {
	MoneyNode* moneyNode = (MoneyNode*)malloc(sizeof(MoneyNode));
	moneyNode->data = money;
	MoneyNode* p = moneyList;
	while (p->next) {
		p = p->next;
	}
	p->next = moneyNode;
	moneyNode->next = NULL;
}
MoneyNode* searchMoney(char ch[]) {
	MoneyNode* p = moneyList;
	while (p) {
		if (strcmp(p->data.Name, ch) != NULL) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
int beforeMoneyExit() {
	if (moneyList->next) {
		saveMoney(moneyList, MONEYPATH);
	}
	MoneyNode* p = moneyList;
	while (p) {
		MoneyNode* q = p;
		p = p->next;
		free(q);
	};
}