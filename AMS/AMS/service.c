#include<stdlib.h>
#include"model.h"
LinkQueue cardQueue;

LinkQueue ReturnQueue() {
	return cardQueue;
}
int InitQueue() {  //��ʼ������
	cardQueue.rear = (CardNode*)malloc(sizeof(CardNode));  //����ͷ�ڵ�
	(cardQueue.rear)->next = NULL;
	cardQueue.front = cardQueue.rear;
	return 1;
}
int EnQueue(Card e) { //���Ӷ�β��������Ŷ�
	CardNode* p = (CardNode*)malloc(sizeof(CardNode));
	p->data = e;
	p->next = NULL;      //���½ڵ��ָ������Ϊ��
	cardQueue.rear->next = p;   //�Ӷ�β���  
	cardQueue.rear = p;
	return 1;
}
int DeQueue(Card* e) {  //���Ӷ��ײ��˾���
	if (cardQueue.front == cardQueue.rear)  //������Ϊ��ʱ�����˾���
		return 0;
	CardNode* p = cardQueue.front->next;
	*e = p->data;    //������ײ�������
	cardQueue.front->next = p->next;  //���Ķ���ͷָ��
	if (cardQueue.rear == p)
		cardQueue.rear = cardQueue.front;   //�����һ��Ԫ�س���ʱ������ͷָ���βָ�����
	return 1;
}
CardNode* GetHead() {  //ȡ���ӵĶ�ͷ���˲�����
	if (cardQueue.front != cardQueue.rear) {
		CardNode* p = cardQueue.front->next;
		return p;
	}
	else {
		return NULL;
	}
}