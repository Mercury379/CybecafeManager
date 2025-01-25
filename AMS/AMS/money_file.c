#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"global.h"
#include"model.h"
#include"tool.h"
#include"money_service.h"
#define MONEYCHARNUM 256

int saveMoney(MoneyNode* pMoney, const char* pPath) {
	FILE* fp = NULL;
	fp = fopen(pPath, "w");
	if (fp == NULL) {
		return 0;
	}
	pMoney = pMoney->next;
	while (pMoney) {
		char startTime[10000];
		timeToString(pMoney->data.time, startTime);
		fprintf(fp, "%.1f##%s##%d##%s\n",pMoney->data.amount,pMoney->data.Name,pMoney->data.Status,startTime);
		pMoney = pMoney->next;
	}
	fclose(fp);
	return 1;
}
int readMoney(MoneyNode* pMoney, const char* pPath) {
	FILE* fp = NULL;
	Money money;
	const char* delims = "##";
	char flag[4][20] = { 0 };
	int index = 0;
	char* buf = NULL, * str = NULL;
	char aBuf[MONEYCHARNUM] = { 0 };
	fp = fopen(pPath, "r");
	if (fp == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		memset(aBuf, 0, MONEYCHARNUM);		//Çå¿ÕÊý×é
		if (fgets(aBuf, MONEYCHARNUM, fp) != NULL) {
			if (strlen(aBuf) > 0) {
				buf = aBuf;
				while ((str = strtok(buf, delims)) != NULL) {
					strcpy(flag[index], str);
					buf = NULL;
					index++;
				}
				money.amount = atof(flag[0]);
				strcpy(money.Name, flag[1]);
				money.Status = atoi(flag[2]);
				money.time = stringToTime(flag[3]);
				addMoney(money);
				index = 0;
			}
		}
	}
}