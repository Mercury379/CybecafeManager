#include<stdlib.h>
#include"model.h"
LinkQueue cardQueue;

LinkQueue ReturnQueue() {
	return cardQueue;
}
int InitQueue() {  //初始化链队
	cardQueue.rear = (CardNode*)malloc(sizeof(CardNode));  //生成头节点
	(cardQueue.rear)->next = NULL;
	cardQueue.front = cardQueue.rear;
	return 1;
}
int EnQueue(Card e) { //链队队尾病人入队排队
	CardNode* p = (CardNode*)malloc(sizeof(CardNode));
	p->data = e;
	p->next = NULL;      //将新节点的指针域置为空
	cardQueue.rear->next = p;   //从队尾入队  
	cardQueue.rear = p;
	return 1;
}
int DeQueue(Card* e) {  //链队队首病人就诊
	if (cardQueue.front == cardQueue.rear)  //当队列为空时则无人就诊
		return 0;
	CardNode* p = cardQueue.front->next;
	*e = p->data;    //保存队首病人数据
	cardQueue.front->next = p->next;  //更改队列头指针
	if (cardQueue.rear == p)
		cardQueue.rear = cardQueue.front;   //当最后一个元素出队时，队列头指针和尾指针相等
	return 1;
}
CardNode* GetHead() {  //取链队的队头病人病历号
	if (cardQueue.front != cardQueue.rear) {
		CardNode* p = cardQueue.front->next;
		return p;
	}
	else {
		return NULL;
	}
}