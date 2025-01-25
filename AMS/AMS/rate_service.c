#include<string.h>
#include<stdlib.h>
#include"global.h"
#include"card_file.h"
#include"model.h"
#include"global.h"
#include"Rate_file.h"

RateNode* rateList = NULL;

RateNode* ReturnRateList() {
	return rateList;
}

int InitRateList() {
	rateList = (RateNode*)malloc(sizeof(RateNode));
	if (rateList != NULL) {
		rateList->data.change = time(NULL);
		rateList->data.unit = 15;
		rateList->data.charge = 0.5;
		rateList->data.Status = 0;
		rateList->next = NULL;
		rateList->data.way = 0;
		readRate(rateList, RATEPATH);
		return 1;
	}
	return 0;
}

int addRate(Rate rate) {
	RateNode* rateNode = (RateNode*)malloc(sizeof(RateNode));
	rateNode->data = rate;
	RateNode* p = rateList;
	while (p->next) {
		p = p->next;
	}
	p->next = rateNode;
	rateNode->next = NULL;
}

RateNode* searchRateNow() {
	RateNode* p = rateList;
	if (p->next == NULL) {
		p->data.Status = 1;
	}
	while (p) {
		if (p->data.Status == 1) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int beforeRateExit() {
	if (rateList->next) {
		saveRate(rateList, RATEPATH);
	}
	RateNode* p = rateList;
	while (p) {
		RateNode* q = p;
		p = p->next;
		free(q);
	}
}