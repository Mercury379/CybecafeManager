#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"global.h"
#include"model.h"
#include"tool.h"
#include"billing_service.h"
#define BILLCHARNUM 256

int saveBiling(BillingNode* pBilling, const char* pPath) {
	FILE* fp = NULL;
	fp = fopen(pPath, "w");
	if (fp == NULL) {
		return 0;
	}
	pBilling = pBilling->next;
	while (pBilling) {
		char startTime[10000], endTime[10000];
		timeToString(pBilling->data.Start, startTime);
		timeToString(pBilling->data.End, endTime);
		fprintf(fp, "%s##%s##%s##%.1f##%d##%d\n", pBilling->data.Name,startTime, endTime, pBilling->data.Amount,pBilling->data.Status,pBilling->data.Del);
		pBilling = pBilling->next;
	}
	fclose(fp);
	return 1;
}
int readBiling(BillingNode* pBilling, const char* pPath) {
	FILE* fp = NULL;
	Billing billing;
	const char* delims = "##";
	char flag[6][20] = { 0 };
	int index = 0;
	char* buf = NULL, * str = NULL;
	char aBuf[BILLCHARNUM] = { 0 };
	fp = fopen(pPath, "r");
	if (fp == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		memset(aBuf, 0, BILLCHARNUM);		//Çå¿ÕÊý×é
		if (fgets(aBuf, BILLCHARNUM, fp) != NULL) {
			if (strlen(aBuf) > 0) {
				buf = aBuf;
				while ((str = strtok(buf, delims)) != NULL) {
					strcpy(flag[index], str);
					buf = NULL;
					index++;
				}
				strcpy(billing.Name, flag[0]);
				billing.Start = stringToTime(flag[1]);
				billing.End = stringToTime(flag[2]);
				billing.Amount = atof(flag[3]);
				billing.Status = atoi(flag[4]);
				billing.Del = atoi(flag[5]);
				addBilling(billing);
				index = 0;
			}
		}
	}
}