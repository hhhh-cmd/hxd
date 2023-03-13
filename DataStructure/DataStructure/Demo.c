#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define SQLMAXSIZE 100
typedef int Status;
typedef char ElemType;

/*************************************************˳���Ĳ�������*****************************************************/
typedef struct _SqLIist {
	ElemType* Base;
	int Length;
}SqList;

//˳���ĳ�ʼ��
Status InitList(SqList L)
{
	L.Base = (ElemType*)malloc(sizeof(ElemType) * SQLMAXSIZE);		//Ϊ�������һ���ڴ�
	if (!L.Base) exit(OVERFLOW);
	L.Length = 0;

	return OK;
}

//�������Ա�
void DestroyList(SqList L)
{
	if (L.Base) free(L.Base);
}

//������Ա�
void ClearList(SqList L)
{
	L.Length = 0;
}

//�����Ա�ĳ���
int ListLength(SqList L)
{
	return L.Length;
}

//�ж����Ա��Ƿ�Ϊ�գ�Ϊ�շ���1���ǿշ���0
int ListIsEmpty(SqList L)
{
	if (L.Length == 0) return 1;
	else return 0;
}

//��ȡ���Ա��i��λ�õ�Ԫ��
Status GetElem(SqList L, int i, ElemType e)
{
	if ((i < 1) || (i > L.Length)) return ERROR;

	e = L.Base[i - 1];
	return OK;
}

//�������Ա��Ƿ����Ԫ��e
int LocalElme(SqList L, ElemType e)
{
	int i;
	for (i = 0; i < L.Length; i++)
	{
		if (e == L.Base[i]) return i + 1;
	}
	return 0;
}

//���Ա��i��λ���в���Ԫ��e
Status ListInsertElem(SqList L, ElemType e, int i)
{

	if (i < 1 || i > L.Length + 1) return ERROR;
	if (i == SQLMAXSIZE) return ERROR;
	for (int j = L.Length - 1; j >= i - 1; j--)
	{
		L.Base[j + 1] = L.Base[j];
	}
	L.Base[i - 1] = e;
	L.Length++;
	return OK;
}

//���Ա�ɾ����i��λ���е�Ԫ��e
Status ListDeletElem(SqList L, int i)
{
	if (i < 1 || i > L.Length) return ERROR;
	for (int j = i; j < L.Length; j++)
	{
		L.Base[j - 1] = L.Base[j];
	}
	L.Length--;
	return OK;
}

/*********************************����Ĳ�������,���������Ǵ�ͷ���ĵ�����*********************************************/
typedef struct Stu {
	char name[10];	//����
	int ID;			//ѧ��
	float score;	//�ɼ�
}Elemtype;

typedef struct Lnode{
	Elemtype Data;			//������
	struct Lnode *Next;		//ָ����
}LNode, *LinkList;			//LinkList Ϊָ��ṹ�� LNode ��ָ������

/****�����ʼ��*****/
Status InitLinkList(LinkList L)
{
	L = (LinkList)malloc(sizeof(LNode));		//Ϊ�����ٿռ�
	L->Next = NULL;								//ָ����Ϊ��
	return OK;
}

/****�ж������Ƿ�Ϊ��**��ͷָ���ͷ������***/
Status LinkListEmpty(LinkList L)
{
	if (L->Next == NULL) return OK;
	else return ERROR;
}

//��������ͷָ���ͷ��㲻����
Status DestroyLinkList(LinkList L)
{
	LNode* p;			//������ָ��
	while (L != NULL)
	{
		p = L;			//��ͷָ�븳ֵ��p
		L = L->Next;	//����һ������ָ����ֵ��L,����������һ�����
		free(p);
	}
	return OK;
}

//�������ͷָ���ͷ������
Status ClearLinkList(LinkList L)
{
	LNode *p, *q;
	p = L->Next;
	while(p != NULL)
	{	
		q = p->Next;
		free(p);
		p = q;
	}
	return OK;
}

//������ı���������ͷ���
int LengthLinkList(LinkList L)
{
	int i = 0;
	LNode* p;
	p = L->Next;			//��Ԫ���ָ��,����ͷ���Ŷ
	while (p != NULL)
	{
		p = p->Next;
		i++;
	}
	return i;
}

//���������е�i��Ԫ�ص�����
Status GetElemLinkList(LinkList L, int i, Elemtype e)
{
	LNode* p;
	p = L->Next;			//��Ԫ���ָ��
	int j = 1;	
	while (i > j && p != NULL)						//1 < i < length
	{
		p = p->Next;
		j++;
	}
	if ((i < j) || (p == NULL)) return ERROR;	    //i < 1 ���� LΪ������
	e = p->Data;
	return OK;
}

/*������
//��ȡ������Ԫ��Ϊe��λ��,����ָ��
LNode* GetLocatinkList(LinkList L, Elemtype e)
{
	LNode* p;
	p = L->Next;			//��Ԫ���ָ��
	while (p && p->Data != e)
	{
		p = p->Next;
	}
	return p;	
}


//��ȡ������Ԫ��Ϊe��λ��,����λ��
int GetLocatinkList(LinkList L, Elemtype e)
{
	LNode* p;
	p = L->Next;			//��Ԫ���ָ��
	int i;
	while (p && p->Data != e)
	{
		p = p->Next;
		i++;
	}
	if(p) return i;
	else return 0;
}*/

//�ڵ�i��Ԫ��֮ǰ����Ԫ��e
Status InsertLinkList(LinkList L, Elemtype e, int i)
{
	LNode* p;
	LNode* s;

	/*���ҵ�i-1����㣬pָ��ý��*/
	p = L;			//ͷ���ָ��
	int j = 0;
	while (i - 1 > j && p != NULL)						//1 < i < length
	{
		p = p->Next;
		j++;
	}
	if ((i - 1 < j) || (p == NULL)) return ERROR;	    //i < 1 ���� LΪ������

	/*�ı�ָ����ָ��*/
	s = (LNode*)malloc(sizeof(LNode));    //Ϊ�½�㿪�ٿռ�
	s->Data = e;
	s->Next = p->Next;
	p->Next = s;
	return OK;
}

//ɾ����i�����
Status DeleteLinkList(LinkList L, int i, Elemtype e)
{
	LNode* p;
	LNode* q;

	/*���ҵ�i-1����㣬pָ��ý��*/
	p = L;			//ͷ���ָ��
	int j = 0;
	while (i - 1 > j && (p->Next) != NULL)						//1 < i < length
	{
		p = p->Next;
		j++;
	}
	if ((i - 1 < j) || ((p->Next) == NULL)) return ERROR;	    //i < 1 ���� LΪ������

	q = (LNode*)malloc(sizeof(LNode));    //Ϊ�½�㿪�ٿռ�
	q = p->Next; 
	p->Next = q->Next;
	e = q->Data;		//���汻ɾ���q������
	free(q);			//�ͷ�q���
	return OK;
}

//����������   ͷ�巨
void HCreatlinkList(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));	//����һ����ͷ��������
	L->Next = NULL;
	int i = 1;
	
	for (i = 1; i <= n; i++)
	{
		LNode* p;
		p = (LNode*)malloc(sizeof(LNode));
		/*cin >> p->data;*/					//scanf(&(p->Data));  �˾�c++�﷨ ������ ����c����������
		p->Next = L->Next;
		L->Next = p;
	}
}

//����������   β�巨
void ECreatlinkList(LinkList L, int n)
{
	LNode *r;		//βָ��
	L = (LinkList)malloc(sizeof(LNode));	//����һ����ͷ��������
	L->Next = NULL;
	r = L;
	int i = 1;

	for (i = 1; i <= n; i++)
	{
		LNode* p;
		p = (LNode*)malloc(sizeof(LNode));
		/*cin >> p->data;*/					//�˾�c++�﷨ ������ ����c����������
		p->Next = NULL;
		r->Next = p;
		r = p;
	}
}

/*************************************************����Ĳ�������,ѭ������***********************************************/

//��ѭ������Tb���ӵ�ѭ������Ta����
LinkList Connect(LinkList Ta, LinkList Tb)
{
	LinkList p;
	p = Ta->Next;
	Ta->Next = Tb->Next->Next;
	Tb->Next = p;
	return Tb;
}

/**************************************����Ĳ�������,����������˫������***********************************************/
typedef struct DLNode {
	Elemtype Data;
	struct DLNode* prior, * next;
}DLNode, * DLinkList;

//�����е�i��Ԫ�ص�ָ��
DLinkList GetP_DLinkList(DLinkList L, int i)
{
	DLNode* p;
	p = L->next;			//��Ԫ���ָ��
	int j = 1;
	while (i > j && p != NULL)						//1 < i < length
	{
		p = p->next;
		j++;
	}
	if ((i < j) || (p == NULL)) return ERROR;	    //i < 1 ���� LΪ������
	return p;
}

//��˫������ĵ�i��λ�ò���Ԫ��e
Status InsertDLinkList(DLinkList L, int i, Elemtype e)
{
	DLNode* p;
	DLNode* s;
	if (!(p = GetP_DLinkList(L, i))) return ERROR;		//p����ָ��iλ�õ�ָ��, GetP_DLinkList��ȷ���ǶԵ�
	
	s = (LNode*)malloc(sizeof(LNode));				//Ϊ�������㿪�ٿռ�
	s->Data = e;
	s->next = p;
	p->prior = s;
	s->prior = p->prior;
	p->prior->next = s;

	return OK;
}

//ɾ��˫������ĵ�i��λ�õ�ָ�룬����������e
Status DeletDLinkList(DLinkList L, int i, Elemtype e)
{
	DLNode* p;
	if (!(p = GetP_DLinkList(L, i))) return ERROR;		//p����ָ��iλ�õ�ָ��, GetP_DLinkList��ȷ���ǶԵ�

	e = p->Data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	return OK;
}

//���Ա�ĺϲ�
void unite(SqList La, SqList Lb)
{
	int La_length, Lb_length;
	int i = 1;
	ElemType e;
	La_length = ListLength(La);
	Lb_length = ListLength(Lb);

	for (i = 1; i <= Lb_length; i++)
	{
		GetElem(Lb, i, e);
		if (!LocalElme(Lb, e)) ListInsertElem(La, e, La_length++);
	}
}










int  main()
{
	printf("����");
	return 0;
}