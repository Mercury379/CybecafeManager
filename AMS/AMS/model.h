#include<time.h>
#ifndef MODEL_H
#define MODEL_H
typedef struct {
	char Name[18];   //卡号
	char Pwd[8];     //密码
	int Status;      //卡状态
	double TotalUse;   //累计金额
	int UseCount;    //使用
	double Balance;  //余额
	int Del;         //删除标记

	time_t Start;    //开卡时间
	time_t End;      //截止时间
	time_t LastUse;  //最后使用时间
}Card;

typedef struct {
	char Name[18];	//卡号
	time_t Start;	//上机时间
	time_t End;		//下机时间
	double Amount;  //消费金额
	int Status;		//消费状态，0—未结算，1-已结算
	int Del;		//删除标识，0-未删除，1-已删除
}Billing;

typedef struct {
	time_t change;	//最后修改标准的时间
	int way;		//标准建立方式(0-初始化；1-新增；2-修改)
	int unit;	    //最小收费单元
	double charge;	//每单元收费
	int Status;		//标准状态，0-未使用，1-正在使用
}Rate;

typedef struct {
	time_t time;    //费用变动时间
	char Name[18];	//卡号
	int Status;		//费用性质,0-退费，1-充值
	double amount;	//金额
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
	Rate data;		      //标准内容
	struct RateNode* next;//指针
}RateNode;				  //标准链表节点

typedef struct MoneyNode {
	Money data;
	struct MoneyNode* next;
}MoneyNode;

typedef struct {
	CardNode* front;  //链队头指针
	CardNode* rear;   //链队尾指针
}LinkQueue;

#endif 
