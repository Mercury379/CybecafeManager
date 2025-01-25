#include<time.h>
#ifndef MODEL_H
#define MODEL_H
typedef struct {
	char Name[18];   //����
	char Pwd[8];     //����
	int Status;      //��״̬
	double TotalUse;   //�ۼƽ��
	int UseCount;    //ʹ��
	double Balance;  //���
	int Del;         //ɾ�����

	time_t Start;    //����ʱ��
	time_t End;      //��ֹʱ��
	time_t LastUse;  //���ʹ��ʱ��
}Card;

typedef struct {
	char Name[18];	//����
	time_t Start;	//�ϻ�ʱ��
	time_t End;		//�»�ʱ��
	double Amount;  //���ѽ��
	int Status;		//����״̬��0��δ���㣬1-�ѽ���
	int Del;		//ɾ����ʶ��0-δɾ����1-��ɾ��
}Billing;

typedef struct {
	time_t change;	//����޸ı�׼��ʱ��
	int way;		//��׼������ʽ(0-��ʼ����1-������2-�޸�)
	int unit;	    //��С�շѵ�Ԫ
	double charge;	//ÿ��Ԫ�շ�
	int Status;		//��׼״̬��0-δʹ�ã�1-����ʹ��
}Rate;

typedef struct {
	time_t time;    //���ñ䶯ʱ��
	char Name[18];	//����
	int Status;		//��������,0-�˷ѣ�1-��ֵ
	double amount;	//���
}Money;

typedef struct CardNode {
	Card data;
	struct CardNode* next;
}CardNode;

typedef struct BillingNode {
	Billing data;
	struct BillingNode* next;
}BillingNode;

typedef struct RateNode {
	Rate data;		      //��׼����
	struct RateNode* next;//ָ��
}RateNode;				  //��׼����ڵ�

typedef struct MoneyNode {
	Money data;
	struct MoneyNode* next;
}MoneyNode;

typedef struct {
	CardNode* front;  //����ͷָ��
	CardNode* rear;   //����βָ��
}LinkQueue;

#endif 
