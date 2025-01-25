#include<string.h>
#include<stdlib.h>
#include"global.h"
#include"billing_file.h"
#include"model.h"
#include"global.h"
#include"rate_service.h"

BillingNode* billingList = NULL;

BillingNode* ReturnBillingList() {
	return billingList;
}

int InitBillingList() {
	billingList = (BillingNode*)malloc(sizeof(BillingNode));
	Billing billing = { 0 };
	billingList->data = billing;
	if (billingList != NULL) {
		billingList->next = NULL;
		readBiling(billingList,BILLINGPATH);
		return 1;
	}
	return 0;
}

int addBilling(Billing billing) {
	BillingNode* billingNode = (BillingNode*)malloc(sizeof(BillingNode));
	billingNode->data = billing;
	BillingNode* p = billingList;
	while (p->next) {
		p = p->next;
	}
	p->next = billingNode;
	billingNode->next = NULL;
}
BillingNode* searchBilling(char ch[]) {
	BillingNode* p = billingList;
	while (p) {
		if (strstr(p->data.Name, ch) != NULL) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
//int deleteCard(char ch[]) {
//	CardNode* p = cardList;
//	int flag = 0;
//	while (p) {
//		if (strcmp(p->data.Name, ch) == 0) {
//			flag = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (flag) {
//		CardNode* q = cardList;
//		while (q->next != p) {
//			q = q->next;
//		}
//		q->next = p->next;
//		free(p);
//	}
//	return flag;
//}
int beforeBillingExit() {
	if (billingList->next) {
		saveBiling(billingList, BILLINGPATH);
	}
	BillingNode* p = billingList;
	while (p) {
		BillingNode* q = p;
		p = p->next;
		free(q);
	}
}
double getAmount(BillingNode* p) {
	int sec = p->data.End - p->data.Start;
	int min =(sec / 60)+1;
	double amount;
	RateNode* rate = searchRateNow();
	if (min % rate->data.unit == 0) {
		amount = rate->data.charge * (min / rate->data.unit);
	}
	else {
		amount= rate->data.charge * (min / rate->data.unit+1);
	}
	return amount;
}
int numOfComputer() {
	int num = 0;
	BillingNode* temp = billingList;
	temp = temp->next;
	while (temp) {
		if (temp->data.Status == 0) {
			num++;
		}
		temp = temp->next;
	}
	return num;
}