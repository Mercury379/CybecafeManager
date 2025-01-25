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
	printf("********************���ɼƷѹ���ϵͳ���˵�********************\n");
	printf("\t\t\t1.�û�������\n");
	printf("\t\t\t2.�Ʒѱ�׼����\n");
	printf("\t\t\t3.�Ʒѹ���\n");
	printf("\t\t\t4.���ù���\n");
	printf("\t\t\t5.��ѯͳ��\n");
	printf("\t\t\t6.�ŶӲ�ѯ\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ�����˵����(0~5):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳����ɼƷѹ���ϵͳ����\n");
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
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int UserCardMenu() {
	int command;
	printf("************************�û�������˵�************************\n");
	printf("\t\t\t1.��ӿ�\n");
	printf("\t\t\t2.��ѯ��\n");
	printf("\t\t\t3.ע����\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ�����˵����(0~3):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳��û�������˵�����\n");
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
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int CountStandardMenu() {
	int command;
	printf("***********************�Ʒѱ�׼����˵�***********************\n");
	printf("\t\t\t1.������׼\n");
	printf("\t\t\t2.��ѯ��׼\n");
	printf("\t\t\t3.�޸ı�׼\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ��Ʒѱ�׼����˵����(0~3):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳��Ʒѱ�׼����˵�����\n");
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
		printf("ѡ��˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int CountMoneyMenu() {
	int command;
	printf("*************************�Ʒѹ���˵�*************************\n");
	printf("\t\t\t1.�ϻ�\n");
	printf("\t\t\t2.�»�\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ��Ʒѹ���˵����(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳��Ʒѹ���˵�����\n");
		return 0;
	case 1:
		Logon();
		break;
	case 2:
		Settle();
		break;
	default:
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int MoneyMenu() {
	int command;
	printf("*************************���ù���˵�*************************\n");
	printf("\t\t\t1.��ֵ\n");
	printf("\t\t\t2.�˷�\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ����ù���˵����(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳����ù���˵�����\n");
		return 0;
	case 1:
		AddMoney();
		break;
	case 2:
		RefundMoney();
		break;
	default:
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int SearchMenu() {
	int command;
	printf("*************************��ѯͳ�Ʋ˵�*************************\n");
	printf("\t\t\t1.��ѯ���Ѽ�¼\n");
	printf("\t\t\t2.ͳ��Ӫҵ��\n");
	printf("\t\t\t3.��ѯ��ֵ��¼\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ���ѯͳ�Ʋ˵����(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳���ѯͳ�Ʋ˵�����\n");
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
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
int SearchQueue() {
	int command;
	printf("*************************�ŶӲ�ѯ�˵�*************************\n");
	printf("\t\t\t1.�鿴����\n");
	printf("\t\t\t2.���Ų�ѯ\n");
	printf("\t\t\t0.�˳�\n");
	printf("**************************************************************\n");
	printf("��ѡ���ŶӲ�ѯ�˵����(0~2):");
	scanf("%d", &command);
	switch (command)
	{
	case 0:
		printf("�˳��ŶӲ�ѯ�˵�����\n");
		return 0;
	case 1:
		SeeQueue();
		break;
	case 2:
		SearchInQueue();
		break;
	default:
		printf("ѡ�����˵���Ų��ڷ�Χ�ڣ����������룡\n");
	}
	return 1;
}
void Add() {
	printf("***************************��ӿ�***************************\n");
	Card card;
	char tempName[100];
	char tempPwd[100];
	printf("�����뿨��<����Ϊ1~18>:");
	scanf("%s",&tempName);
	printf("����������<����Ϊ1~8>:");
	scanf("%s",&tempPwd);
	if (strlen(tempName) > 18 || strlen(tempPwd) > 8) {
		printf("����Ŀ��Ż����볬���涨���ȣ�\n");
		return;
	}
	strcpy(card.Name,tempName);
	strcpy(card.Pwd, tempPwd);
	printf("�����뿪�����:");
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
	printf("**********************��ӵĿ���Ϣ����**********************\n");
	printf("����\t����\t��״̬\t���\n");
	printf("%s\t%s\t%d\t%0.1f\n",card.Name,card.Pwd,card.Status,card.Balance);
	addCard(card);
}
void Search() {
	printf("***************************��ѯ��***************************\n");
	printf("����������Ҫ��ѯ�Ŀ���:");
	char ch[100];
	scanf("%s",&ch);
	CardNode* temp = searchCard(ch);
	if (temp) {
		char pBuf[10000];
		timeToString(temp->data.LastUse, pBuf);
		printf("**********************��ѯ������Ϣ����**********************\n");
		printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
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
		printf("δ��ѯ���ÿ���\n");
	}
}
void Delete() {
	printf("***************************ע����***************************\n");
	printf("����������Ҫע���Ŀ���:");
	char ch[100];
	scanf("%s", &ch);
	int flag = deleteCard(ch);
	if (flag) {
		printf("ע�����ɹ���\n");
	}
	else {
		printf("δ�ҵ���ע����!\n");
	}
}
void Logon() {
	printf("***************************�ϻ�****************************\n");
	printf("�������ϻ����ţ�");
	char ch[100];
	char pwd[100];
	scanf("%s",&ch);
	printf("�������ϻ����룺");
	scanf("%s", &pwd);
	CardNode* p = doLogon(ch, pwd);
	if (p != NULL) {
		printf("�ϻ��ɹ���\n");
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
		printf("�ϻ�ʧ�ܣ�\n");
	}
}
void SearchBillings() {
	printf("*************************��ѯ���Ѽ�¼**************************\n");
	printf("����������Ҫ��ѯ���Ѽ�¼�Ŀ���:");
	char ch[100];
	scanf("%s", &ch);
	BillingNode* temp = searchBilling(ch);
	if (temp) {
		char pStart[10000];
		char pEnd[10000];
		timeToString(temp->data.Start, pStart);
		timeToString(temp->data.End, pEnd);
		printf("********************��ѯ���ÿ������Ѽ�¼����********************\n");
		printf("����\t�ϻ�ʱ��\t\t�»�ʱ��\t\t���ѽ��\n");
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
		printf("δ��ѯ���ÿ������Ѽ�¼��\n");
	}
}
void Settle() {
	printf("***************************�»�****************************\n");
	printf("�������»����ţ�");
	char ch[100];
	char pwd[100];
	scanf("%s", &ch);
	printf("�������»����룺");
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
					printf("���㣬���ֵ��\n");
				}
				bill->data.Status = 1;
				break;
			}
			bill = bill->next;
		}
		if (bill == NULL) {
			printf("�»�ʧ�ܣ�\n");
		}
		printf("�»��ɹ���\n");
		Card card;
		if (DeQueue(&card)) {
			printf("��һλ�ϻ��Ŀ���Ϊ��%s\n",card.Name);
		}
	}
	else {
		printf("�»�ʧ�ܣ�\n");
	}
}
void NewRate() {
	printf("**************************������׼***************************\n");
	int minus;
	double pay;
	printf("������׼�ļƷѵ�ԪΪ��");
	scanf("%d",&minus);
	printf("������׼��ÿ��Ԫ�շ�Ϊ��");
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
	printf("������׼�ɹ���\n");
}
void SearchRate() {
	printf("**************************��ѯ��׼***************************\n");
	RateNode* rate = ReturnRateList();
	printf("�޸�ʱ��\t\t�޸ķ�ʽ\t��С�շѵ�Ԫ\t��Ԫ�շ�\n");
	while (rate) {
		char pEnd[100],change[100];
		timeToString(rate->data.change, pEnd);
		if (rate->data.way == 0) {
			strcpy(change,"��ʼ��");
		}
		else if (rate->data.way == 1) {
			strcpy(change, "�½�");
		}
		else {
			strcpy(change, "�޸�");
		}
		printf("%s\t%s\t\t%d\t\t%.1f\n",pEnd,change,rate->data.unit,rate->data.charge);
		rate = rate->next;
	}
	printf("����ʹ�õļƷѱ�׼Ϊ��\n");
	printf("�޸�ʱ��\t\t�޸ķ�ʽ\t��С�շѵ�Ԫ\t��Ԫ�շ�\n");
	RateNode* new = searchRateNow();
	char pEnd[100], change[100];
	timeToString(new->data.change, pEnd);
	if (new->data.way == 0) {
		strcpy(change, "��ʼ��");
	}
	else if (new->data.way == 1) {
		strcpy(change, "�½�");
	}
	else {
		strcpy(change, "�޸�");
	}
	printf("%s\t%s\t\t%d\t\t%.1f\n", pEnd, change, new->data.unit, new->data.charge);
}
void UpdateRate() {
	printf("**************************�޸ı�׼***************************\n");
	printf("����ʹ�õļƷѱ�׼Ϊ��\n");
	printf("�޸�ʱ��\t\t�޸ķ�ʽ\t��С�շѵ�Ԫ\t��Ԫ�շ�\n");
	RateNode* new = searchRateNow();
	char pEnd[100], change[100];
	timeToString(new->data.change, pEnd);
	if (new->data.way == 0) {
		strcpy(change, "��ʼ��");
	}
	else if (new->data.way == 1) {
		strcpy(change, "�½�");
	}
	else {
		strcpy(change, "�޸�");
	}
	printf("%s\t%s\t\t%d\t\t%.1f\n", pEnd, change, new->data.unit, new->data.charge);
	int unit;
	double charge;
	printf("����������Ҫ�޸ĵ���С�Ʒѵ�Ԫ��");
	scanf("%d",&unit);
	printf("����������Ҫ�޸ĵ�ÿ��Ԫ�շѣ�");
	scanf("%lf",&charge);
	Rate rate = new->data;
	rate.unit = unit;
	rate.way = 2;
	rate.charge = charge;
	addRate(rate);
	new->data.Status = 0;
	printf("�޸ļƷѱ�׼�ɹ���\n");
}

void AddMoney() {
	printf("***************************��ֵ****************************\n");
	char name[18];
	char pwd[20];
	printf("�������ֵ���ţ�");
	scanf("%s",&name);
	printf("�������ֵ���룺");
	scanf("%s",&pwd);
	CardNode* card=searchCard(name);
	if (card) {
		if (strcmp(card->data.Pwd, pwd) == 0) {
			int amount;
			printf("����������Ҫ��ֵ�Ľ�");
			scanf("%d",&amount);
			Money money;
			money.time = time(NULL);
			money.amount = amount;
			money.Status = 1;
			strcpy(money.Name, name);
			addMoney(money);
			CardNode* card = searchCard(name);
			card->data.Balance += amount;
			printf("��ֵ�ɹ���\n");
		}
		else {
			printf("����������󣬳�ֵʧ�ܣ�\n");
		}
	}
	else {
		printf("��ֵʧ�ܣ�\n");
	}
}
void RefundMoney(){
	printf("***************************�˷�****************************\n");
	char name[18];
	char pwd[20];
	printf("�������˷ѿ��ţ�");
	scanf("%s", &name);
	printf("�������˷����룺");
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
				printf("�˷ѳɹ���\n");
			}
			else {
				printf("�ÿ���ʹ�ã��޷��˷ѣ�\n");
			}
		}
		else {
			printf("������������˷�ʧ�ܣ�\n");
		}
	}
	else {
		printf("�˷�ʧ�ܣ�\n");
	}
}
int CountAllMoney() {
	printf("*************************ͳ��Ӫҵ��***************************\n");
	int year,month,day;
	double amount = 0;
	printf("����������Ҫͳ��Ӫҵ�������(��.��.��)��");
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
	printf("%d��%d��%d�յ���Ӫҵ��Ϊ��%.1fԪ\n",year,month,day,amount);
}
int SeeQueue() {
	printf("*************************�鿴����***************************\n");
	LinkQueue queue = ReturnQueue();
	CardNode* p = queue.front;
	p = p->next;
	int n = 1;
	if (queue.front == queue.rear) {
		printf("�����ŶӵȺ�Ŀ��ˣ�\n");
	}
	while (p) {
		printf("%d��%s\n",n,p->data.Name);
		n++;
		p = p->next;
	}
}
int SearchInQueue() {
	printf("*************************���Ų�ѯ****************************\n");
	printf("��������Ҫ��ѯ���Ŀ��ţ�");
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
	printf("%s��ǰ�滹��%dλ���ˡ�\n", name, n);
}
int SearchMoney() {
	printf("***********************��ѯ��ֵ��¼****************************\n");
	printf("����������Ҫ��ѯ��ֵ��¼�Ŀ���:");
	char ch[100];
	scanf("%s", &ch);
	MoneyNode* p = searchMoney(ch);
	p = p->next;
	int n = 0;
	while(p){
		if (strcmp(p->data.Name, ch) == 0 && p->data.Status==1) {
			if (n == 0) {
				printf("����\t��ֵʱ��\t\t��ֵ���\n");
			}
			char pEnd[100];
			timeToString(p->data.time, pEnd);
			printf("%s\t%s\t%.1f\n",p->data.Name,pEnd,p->data.amount);
			n++;
		}
		p = p->next;
	}
}