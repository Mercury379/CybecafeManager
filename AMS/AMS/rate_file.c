#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"global.h"
#include"model.h"
#include"tool.h"
#include"rate_service.h"
#define RATECHARNUM 256

int saveRate(RateNode* pRate, const char* pPath) {
	FILE* fp = NULL;
	fp = fopen(pPath, "w");
	if (fp == NULL) {
		return 0;
	}
	pRate = pRate->next;
	while (pRate) {
		char startTime[10000];
		timeToString(pRate->data.change, startTime);
		fprintf(fp, "%s##%.1f##%d##%d##%d\n", startTime,pRate->data.charge, pRate->data.Status, pRate->data.unit, pRate->data.way);
		pRate = pRate->next;
	}
	fclose(fp);
	return 1;
}
int readRate(RateNode* pRate, const char* pPath) {
	FILE* fp = NULL;
	Rate rate;
	const char* delims = "##";
	char flag[5][20] = { 0 };
	int index = 0;
	char* buf = NULL, * str = NULL;
	char aBuf[RATECHARNUM] = { 0 };
	fp = fopen(pPath, "r");
	if (fp == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		memset(aBuf, 0, RATECHARNUM);		//Çå¿ÕÊý×é
		if (fgets(aBuf, RATECHARNUM, fp) != NULL) {
			if (strlen(aBuf) > 0) {
				buf = aBuf;
				while ((str = strtok(buf, delims)) != NULL) {
					strcpy(flag[index], str);
					buf = NULL;
					index++;
				}
				rate.change = stringToTime(flag[0]);
				rate.charge = atof(flag[1]);
				rate.Status = atoi(flag[2]);
				rate.unit= atoi(flag[3]);
				rate.way = atoi(flag[4]);
				addRate(rate);
				index = 0;
			}
		}
	}
}