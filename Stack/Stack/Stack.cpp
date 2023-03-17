#include <stdio.h>
#include <stdlib.h>


#define OK			1
#define ERROR		0
#define MAXSIZE		100
typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

/*ջ��ʼ��*/
Status InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base) return ERROR;
	S.base = S.top;
	S.stacksize = MAXSIZE;
	return OK;
}

/*�ж�ջ�Ƿ�Ϊ��  OK:��   ERROR���ǿ�*/
Status EmptyStack(SqStack S)
{
	if (S.base == S.top) return OK;
	else return ERROR;
}

/*��ջ����*/
int LengthStack(SqStack S)
{
	return S.top - S.base;
}

/*���ջ*/
Status ClearStack(SqStack S)
{
	if(S.base) S.top = S.base;
	return OK;
}

/*����ջ*/
Status DestroyStack(SqStack &S) 
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.top = S.base = NULL;
	}
	return OK;
}

/*��ջ*/
Status PushStack(SqStack &S, SElemType e)
{
	if (S.top - S.base == S.stacksize) return ERROR;	//����
	*S.top++ = e;
	return OK;
}

/*��ջ*/
Status PopStack(SqStack &S, SElemType &e)
{
	if (S.top == S.base) return ERROR;	//����
	e = *--S.top;
	return OK;
}

/***************��ջ�ı�ʾ��ʵ��*******************/

typedef struct StackNode{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;
LinkStack S;

/*��ջ�ĳ�ʼ��*/
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}

/*�ж���ջ�Ƿ�Ϊ��*/
int EmptyStack(LinkStack S)
{
	if (S == NULL) return 1;
	else return 0;
}

/*��ջ��ջ*/      
Status PushStack(LinkStack &S, SElemType e)
{
	StackNode *p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;	
}

/*��ջ��ջ*/
Status PopStack(LinkStack& S, SElemType &e)
{
	StackNode* p = new StackNode;
	if (S == NULL) return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

/*ȡջ��Ԫ��*/
SElemType GetTopStack(LinkStack S)
{
	if (S != NULL)
		return S->data;
}
     
 






int main(void)
{   
	printf("fsfsfs");
	return 0;
}  