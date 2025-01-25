#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"global.h"
#include"model.h"
#include"tool.h"
#include"card_service.h"
#define CARDCHARNUM 256

int saveCard(CardNode* pCard,const char* pPath) {
	FILE* fp = NULL;
	fp = fopen(pPath,"w");
	if (fp == NULL) {
		return 0;
	}
	pCard = pCard->next;
	while (pCard) {
		char startTime[10000],endTime[10000],lastTime[10000];
		timeToString(pCard->data.Start, startTime);
		timeToString(pCard->data.End, endTime);
		timeToString(pCard->data.LastUse, lastTime);
		fprintf(fp, "%s##%s##%d##%s##%s##%.1f##%s##%d##%.1f##%d\n",pCard->data.Name,pCard->data.Pwd,pCard->data.Status,
			startTime,endTime,pCard->data.TotalUse,lastTime,pCard->data.UseCount,pCard->data.Balance,pCard->data.Del);
		pCard = pCard->next;
	}
	fclose(fp);
	return 1;
}
int readCard(CardNode* pCard, const char* pPath) {
	FILE* fp = NULL;
	Card card;
	const char* delims = "##";
	char flag[10][20] = { 0 };
	int index = 0;
	char* buf = NULL,*str=NULL;
	char aBuf[CARDCHARNUM] = {0};
	fp = fopen(pPath, "r");
	if (fp == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		memset(aBuf,0,CARDCHARNUM);		//Çå¿ÕÊý×é
		if (fgets(aBuf,CARDCHARNUM,fp) != NULL) {
			if (strlen(aBuf) > 0) {
				buf = aBuf;
				while ((str = strtok(buf, delims)) != NULL) {
					strcpy(flag[index],str);
					buf = NULL;
					index++;
				}
				strcpy(card.Name,flag[0]);
				strcpy(card.Pwd, flag[1]);
				card.Status = atoi(flag[2]);
				card.Start=stringToTime(flag[3]);
				card.End=stringToTime(flag[4]);
				card.TotalUse = atof(flag[5]);
				card.LastUse = stringToTime(flag[6]);
				card.UseCount = atoi(flag[7]);
				card.Balance = atof(flag[8]);
				card.Del = atoi(flag[9]);
				addCard(card);
				index = 0;
			}
		}
	}
}