#include <stdio.h>
#include <stdlib.h>


#define OK			1
#define ERROR		0
#define MAXSIZE		100
typedef int Status;
typedef int QElemType;

/*******************˳�����**********************/
typedef struct {
	QElemType* base;		//��ʼ���Ķ�̬����洢�ռ�
	int front; 
	int rear;
}SqQueue;
 
/*��ʼ��ѭ������*/
Status InitSqQueue(SqQueue &Q)
{
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if (!Q.base) return ERROR;
	Q.front = Q.rear;
	return OK;
}

/*��ѭ�����г���*/
int LengthSqQueue(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/*ѭ���������*/
Status EnSqueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;   //����
	Q.base[Q.rear] = e;				   //����Ԫ��
	Q.rear = (Q.rear + 1) % MAXSIZE;   //βָ������ƶ�һλ
	return OK;
}

/*ѭ�����г���*/
Status DeSqueue(SqQueue& Q, QElemType &e)
{
	if (Q.rear == Q.front) return ERROR;   //�ӿ�
	e = Q.base[Q.front];				   //����Ԫ��
	Q.front = (Q.front + 1) % MAXSIZE;   //βָ������ƶ�һλ
	return OK;
}

/*ѭ������ȡͷԪ��*/
QElemType Gethead(SqQueue Q)
{
	if (Q.rear == Q.front) return ERROR;   //�ӿ�
	return Q.base[Q.front];
}

/*******************��ʽ����**********************/
typedef struct Qnode {
	QElemType data;
	struct Qnode* next; 
}Qnode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*��ʼ������*/ 
Status InitLinkQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Qnode));
	if (!Q.front) return ERROR;
	Q.front = Q.rear = NULL;
	return OK;
}

/*��������*/
Status DestroyLinkQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
	return OK;
}

/*�������*/
Status EnLinkQueue(LinkQueue& Q, QElemType e)
{
	Qnode* p;
	p = (QueuePtr)malloc(sizeof(Qnode));
	if (!p) return ERROR;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

/*���ӳ���*/
Status DeLinkQueue(LinkQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear) return ERROR;		//�ӿ�
	e = Q.front->next->data;
	Q.front->next = Q.front->next->next;
	if (Q.rear == Q.front->next) Q.rear = Q.front;
	delete Q.front->next;
	return OK;
}
