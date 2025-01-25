#include<stdio.h>
#include<string.h>
#include"model.h"
#include"menu.h"
#include"tool.h"
#include"global.h"
#include"card_service.h"
#include"billing_service.h"
#include"rate_service.h"
#include"money_service.h"
#include"service.h"
int MainMenu() {
	int command;
	printf("********************网吧计费管理系统主菜单********************\n");
	printf("\t\t\t1.用户卡管理\n");
	printf("\t\t\t2.计费标准管理\n");
	printf("\t\t\t3.计费管理\n");
	printf("\t\t\t4.费用管理\n");
	printf("\t\t\t5.查询统计\n");
	printf("\t\t\t6.排队查询\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择主菜单编号(0~5):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出网吧计费管理系统……\n");
		return 0;
	case 1:
		while (1) {
			if (UserCardMenu() == 0) {
				break;
			}
		}
		break;
	case 2:
		while (1) {
			if (CountStandardMenu() == 0) {
				break;
			}
		}
		break;
	case 3:
		while (1) {
			if (CountMoneyMenu() == 0) {
				break;
			}
		}
		break;
	case 4:
		while (1) {
			if (MoneyMenu() == 0) {
				break;
			}
		}
		break;
	case 5:
		while (1) {
			if (SearchMenu() == 0) {
				break;
			}
		}
		break;
	case 6:
		while (1) {
			if (SearchQueue() == 0) {
				break;
			}
		}
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int UserCardMenu() {
	int command;
	printf("************************用户卡管理菜单************************\n");
	printf("\t\t\t1.添加卡\n");
	printf("\t\t\t2.查询卡\n");
	printf("\t\t\t3.注销卡\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择主菜单编号(0~3):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出用户卡管理菜单……\n");
		return 0;
	case 1:
		Add();
		break;
	case 2:
		Search();
		break;
	case 3:
		Delete();
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int CountStandardMenu() {
	int command;
	printf("***********************计费标准管理菜单***********************\n");
	printf("\t\t\t1.新增标准\n");
	printf("\t\t\t2.查询标准\n");
	printf("\t\t\t3.修改标准\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择计费标准管理菜单编号(0~3):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出计费标准管理菜单……\n");
		return 0;
	case 1:
		NewRate();
		break;
	case 2:
		SearchRate();
		break;
	case 3:
		UpdateRate();
		break;
	default:
		printf("选择菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int CountMoneyMenu() {
	int command;
	printf("*************************计费管理菜单*************************\n");
	printf("\t\t\t1.上机\n");
	printf("\t\t\t2.下机\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择计费管理菜单编号(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出计费管理菜单……\n");
		return 0;
	case 1:
		Logon();
		break;
	case 2:
		Settle();
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int MoneyMenu() {
	int command;
	printf("*************************费用管理菜单*************************\n");
	printf("\t\t\t1.充值\n");
	printf("\t\t\t2.退费\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择费用管理菜单编号(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出费用管理菜单……\n");
		return 0;
	case 1:
		AddMoney();
		break;
	case 2:
		RefundMoney();
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int SearchMenu() {
	int command;
	printf("*************************查询统计菜单*************************\n");
	printf("\t\t\t1.查询消费记录\n");
	printf("\t\t\t2.统计营业额\n");
	printf("\t\t\t3.查询充值记录\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择查询统计菜单编号(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出查询统计菜单……\n");
		return 0;
	case 1:
		SearchBillings();
		break;
	case 2:
		CountAllMoney();
		break;
	case 3:
		SearchMoney();
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
int SearchQueue() {
	int command;
	printf("*************************排队查询菜单*************************\n");
	printf("\t\t\t1.查看队列\n");
	printf("\t\t\t2.待排查询\n");
	printf("\t\t\t0.退出\n");
	printf("**************************************************************\n");
	printf("请选择排队查询菜单编号(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("退出排队查询菜单……\n");
		return 0;
	case 1:
		SeeQueue();
		break;
	case 2:
		SearchInQueue();
		break;
	default:
		printf("选择主菜单编号不在范围内，请重新输入！\n");
	}
	return 1;
}
void Add() {
	printf("***************************添加卡***************************\n");
	Card card;
	char tempName[100];
	char tempPwd[100];
	printf("请输入卡号<长度为1~18>:");
	scanf("%s",&tempName);
	printf("请输入密码<长度为1~8>:");
	scanf("%s",&tempPwd);
	if (strlen(tempName) > 18 || strlen(tempPwd) > 8) {
		printf("输入的卡号或密码超过规定长度！\n");
		return;
	}
	strcpy(card.Name,tempName);
	strcpy(card.Pwd, tempPwd);
	printf("请输入开卡金额:");
	scanf("%lf",&card.Balance);
	card.TotalUse = card.Balance;
	card.UseCount = 0;
	card.Status = 0;
	card.Del = 0;
	card.Start = time(NULL);
	card.End = time(NULL);
	struct tm* startTime;
	struct tm* endTime;
	startTime = localtime(&card.Start);
	endTime = localtime(&card.End);
	endTime->tm_year = startTime->tm_year + 1;
	card.End = mktime(endTime);
	card.LastUse = time(NULL);
	Money money;
	money.time = time(NULL);
	money.amount = card.Balance;
	money.Status = 1;
	strcpy(money.Name, tempName);
	addMoney(money);
	printf("**********************添加的卡信息如下**********************\n");
	printf("卡号\t密码\t卡状态\t余额\n");
	printf("%s\t%s\t%d\t%0.1f\n",card.Name,card.Pwd,card.Status,card.Balance);
	addCard(card);
}
void Search() {
	printf("***************************查询卡***************************\n");
	printf("请输入你想要查询的卡号:");
	char ch[100];
	scanf("%s",&ch);
	CardNode* temp = searchCard(ch);
	if (temp) {
		char pBuf[10000];
		timeToString(temp->data.LastUse, pBuf);
		printf("**********************查询到卡信息如下**********************\n");
		printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
		printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", temp->data.Name, temp->data.Status, temp->data.Balance, temp->data.TotalUse,temp->data.UseCount,pBuf);
		temp = temp->next;
		while (temp) {
			if (strstr(temp->data.Name, ch)) {
				char pBuf[10000];
				timeToString(temp->data.LastUse, pBuf);
				printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", temp->data.Name, temp->data.Status, temp->data.Balance, temp->data.TotalUse, temp->data.UseCount, pBuf);
			}
			temp = temp->next;
		}
	}
	else {
		printf("未查询到该卡！\n");
	}
}
void Delete() {
	printf("***************************注销卡***************************\n");
	printf("请输入你想要注销的卡号:");
	char ch[100];
	scanf("%s", &ch);
	int flag = deleteCard(ch);
	if (flag) {
		printf("注销卡成功！\n");
	}
	else {
		printf("未找到该注销卡!\n");
	}
}
void Logon() {
	printf("***************************上机****************************\n");
	printf("请输入上机卡号：");
	char ch[100];
	char pwd[100];
	scanf("%s",&ch);
	printf("请输入上机密码：");
	scanf("%s", &pwd);
	CardNode* p = doLogon(ch, pwd);
	if (p != NULL) {
		printf("上机成功！\n");
		Billing billing;
		strcpy(billing.Name, ch);
		billing.Status = 0;
		billing.Del = 0;
		billing.Amount = 0;
		billing.End = time(NULL);
		billing.Start = time(NULL);
		addBilling(billing);
	}
	else {
		printf("上机失败！\n");
	}
}
void SearchBillings() {
	printf("*************************查询消费记录**************************\n");
	printf("请输入你想要查询消费记录的卡号:");
	char ch[100];
	scanf("%s", &ch);
	BillingNode* temp = searchBilling(ch);
	if (temp) {
		char pStart[10000];
		char pEnd[10000];
		timeToString(temp->data.Start, pStart);
		timeToString(temp->data.End, pEnd);
		printf("********************查询到该卡的消费记录如下********************\n");
		printf("卡号\t上机时间\t\t下机时间\t\t消费金额\n");
		printf("%s\t%s\t%s\t%0.1f\n", temp->data.Name, pStart,pEnd,temp->data.Amount);
		temp = temp->next;
		while (temp) {
			if (strstr(temp->data.Name, ch)) {
				char pStart[10000];
				char pEnd[10000];
				timeToString(temp->data.Start, pStart);
				timeToString(temp->data.End, pEnd);
				printf("%s\t%s\t%s\t%0.1f\n", temp->data.Name, pStart, pEnd, temp->data.Amount);
			}
			temp = temp->next;
		}
	}
	else {
		printf("未查询到该卡的消费记录！\n");
	}
}
void Settle() {
	printf("***************************下机****************************\n");
	printf("请输入下机卡号：");
	char ch[100];
	char pwd[100];
	scanf("%s", &ch);
	printf("请输入下机密码：");
	scanf("%s", &pwd);
	CardNode* p = doSettle(ch, pwd);
	if (p != NULL) {
		p->data.Status = 0;
		BillingNode* bill = ReturnBillingList();
		bill = bill->next;
		while (bill) {
			if (strcmp(bill->data.Name, ch) == 0 && bill->data.Status==0) {
				bill->data.End = time(NULL);
				double amount = getAmount(bill);
				if (p->data.Balance >= amount) {
					p->data.Balance = p->data.Balance - amount;
					bill->data.Amount = amount;
				}
				else {
					printf("余额不足，请充值！\n");
				}
				bill->data.Status = 1;
				break;
			}
			bill = bill->next;
		}
		if (bill == NULL) {
			printf("下机失败！\n");
		}
		printf("下机成功！\n");
		Card card;
		if (DeQueue(&card)) {
			printf("下一位上机的客人为：%s\n",card.Name);
		}
	}
	else {
		printf("下机失败！\n");
	}
}
void NewRate() {
	printf("**************************新增标准***************************\n");
	int minus;
	double pay;
	printf("新增标准的计费单元为：");
	scanf("%d",&minus);
	printf("新增标准的每单元收费为：");
	scanf("%lf",&pay);
	Rate rate;
	rate.Status = 1;
	rate.change = time(NULL);
	rate.charge = pay;
	rate.unit = minus;
	rate.way = 1;
	RateNode* temp = ReturnRateList();
	while (temp) {
		if (temp->data.Status == 1) {
			temp->data.Status = 0;
		}
		temp = temp->next;
	}
	addRate(rate);
	printf("新增标准成功！\n");
}
void SearchRate() {
	printf("**************************查询标准***************************\n");
	RateNode* rate = ReturnRateList();
	printf("修改时间\t\t修改方式\t最小收费单元\t单元收费\n");
	while (rate) {
		char pEnd[100],change[100];
		timeToString(rate->data.change, pEnd);
		if (rate->data.way == 0) {
			strcpy(change,"初始化");
		}
		else if (rate->data.way == 1) {
			strcpy(change, "新建");
		}
		else {
			strcpy(change, "修改");
		}
		printf("%s\t%s\t\t%d\t\t%.1f\n",pEnd,change,rate->data.unit,rate->data.charge);
		rate = rate->next;
	}
	printf("正在使用的计费标准为：\n");
	printf("修改时间\t\t修改方式\t最小收费单元\t单元收费\n");
	RateNode* new = searchRateNow();
	char pEnd[100], change[100];
	timeToString(new->data.change, pEnd);
	if (new->data.way == 0) {
		strcpy(change, "初始化");
	}
	else if (new->data.way == 1) {
		strcpy(change, "新建");
	}
	else {
		strcpy(change, "修改");
	}
	printf("%s\t%s\t\t%d\t\t%.1f\n", pEnd, change, new->data.unit, new->data.charge);
}
void UpdateRate() {
	printf("**************************修改标准***************************\n");
	printf("正在使用的计费标准为：\n");
	printf("修改时间\t\t修改方式\t最小收费单元\t单元收费\n");
	RateNode* new = searchRateNow();
	char pEnd[100], change[100];
	timeToString(new->data.change, pEnd);
	if (new->data.way == 0) {
		strcpy(change, "初始化");
	}
	else if (new->data.way == 1) {
		strcpy(change, "新建");
	}
	else {
		strcpy(change, "修改");
	}
	printf("%s\t%s\t\t%d\t\t%.1f\n", pEnd, change, new->data.unit, new->data.charge);
	int unit;
	double charge;
	printf("请输入你想要修改的最小计费单元：");
	scanf("%d",&unit);
	printf("请输入你想要修改的每单元收费：");
	scanf("%lf",&charge);
	Rate rate = new->data;
	rate.unit = unit;
	rate.way = 2;
	rate.charge = charge;
	addRate(rate);
	new->data.Status = 0;
	printf("修改计费标准成功！\n");
}

void AddMoney() {
	printf("***************************充值****************************\n");
	char name[18];
	char pwd[20];
	printf("请输入充值卡号：");
	scanf("%s",&name);
	printf("请输入充值密码：");
	scanf("%s",&pwd);
	CardNode* card=searchCard(name);
	if (card) {
		if (strcmp(card->data.Pwd, pwd) == 0) {
			int amount;
			printf("请输入你想要充值的金额：");
			scanf("%d",&amount);
			Money money;
			money.time = time(NULL);
			money.amount = amount;
			money.Status = 1;
			strcpy(money.Name, name);
			addMoney(money);
			CardNode* card = searchCard(name);
			card->data.Balance += amount;
			printf("充值成功！\n");
		}
		else {
			printf("密码输入错误，充值失败！\n");
		}
	}
	else {
		printf("充值失败！\n");
	}
}
void RefundMoney(){
	printf("***************************退费****************************\n");
	char name[18];
	char pwd[20];
	printf("请输入退费卡号：");
	scanf("%s", &name);
	printf("请输入退费密码：");
	scanf("%s", &pwd);
	CardNode* card = searchCard(name);
	if (card) {
		if (strcmp(card->data.Pwd, pwd) == 0) {
			if (card->data.UseCount == 0) {
				Money money;
				money.time = time(NULL);
				money.amount = card->data.Balance;
				money.Status = 0;
				strcpy(money.Name, name);
				addMoney(money);
				deleteCard(name);
				printf("退费成功！\n");
			}
			else {
				printf("该卡已使用，无法退费！\n");
			}
		}
		else {
			printf("密码输入错误，退费失败！\n");
		}
	}
	else {
		printf("退费失败！\n");
	}
}
int CountAllMoney() {
	printf("*************************统计营业额***************************\n");
	int year,month,day;
	double amount = 0;
	printf("请输入你想要统计营业额的日期(年.月.日)：");
	scanf("%d.%d.%d",&year,&month,&day);
	struct tm tm1 = { 0 };
	time_t time1;
	tm1.tm_year = year;
	tm1.tm_mon = month;
	tm1.tm_mday = day;
	tm1.tm_hour = 0;
	tm1.tm_min = 0;
	tm1.tm_year = tm1.tm_year - 1900;
	tm1.tm_mon = tm1.tm_mon - 1;
	time1 = mktime(&tm1);
	BillingNode* bill = ReturnBillingList();
	MoneyNode* money = ReturnMoneyList();
	bill = bill->next;
	money = money->next;
	while (bill) {
		if (bill->data.End >= time1 && bill->data.End < time1 + 86400) {
			if (bill->data.Status == 1) {
				amount = amount - bill->data.Amount;
			}
		}
		bill = bill->next;
	}
	while (money) {
		if (money->data.time>= time1 &&money->data.time < time1 + 86400) {
			if (money->data.Status == 1) {
				amount += money->data.amount;
			}
			else {
				amount -= money->data.amount;
			}
		}
		money = money->next;
	}
	printf("%d年%d月%d日的总营业额为：%.1f元\n",year,month,day,amount);
}
int SeeQueue() {
	printf("*************************查看队列***************************\n");
	LinkQueue queue = ReturnQueue();
	CardNode* p = queue.front;
	p = p->next;
	int n = 1;
	if (queue.front == queue.rear) {
		printf("暂无排队等候的客人！\n");
	}
	while (p) {
		printf("%d、%s\n",n,p->data.Name);
		n++;
		p = p->next;
	}
}
int SearchInQueue() {
	printf("*************************待排查询****************************\n");
	printf("请输入想要查询到的卡号：");
	char name[18];
	scanf("%s",&name);
	LinkQueue queue = ReturnQueue();
	CardNode* p = queue.front;
	p = p->next;
	int n = 0;
	while (p) {
		if (strcmp(p->data.Name, name) == 0) {
			break;
		}
		n++;
		p = p->next;
	}
	printf("%s的前面还有%d位客人。\n", name, n);
}
int SearchMoney() {
	printf("***********************查询充值记录****************************\n");
	printf("请输入你想要查询充值记录的卡号:");
	char ch[100];
	scanf("%s", &ch);
	MoneyNode* p = searchMoney(ch);
	p = p->next;
	int n = 0;
	while(p){
		if (strcmp(p->data.Name, ch) == 0 && p->data.Status==1) {
			if (n == 0) {
				printf("卡号\t充值时间\t\t充值金额\n");
			}
			char pEnd[100];
			timeToString(p->data.time, pEnd);
			printf("%s\t%s\t%.1f\n",p->data.Name,pEnd,p->data.amount);
			n++;
		}
		p = p->next;
	}
}