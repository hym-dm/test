#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _LIST_H_
#define _LIST_H_
#include "Sysutil.h"
#endif
#define ElemType int

//无头单链表
typedef struct SListNode
{
	ElemType data;//数据域
   struct SListNode *next;// 指针域
}SListNode;

typedef struct SList
{
	SListNode *head;//成员封装 
}SList;

void SListInit(SList *plist);
void SListPushBack(SList* plist, ElemType x);
void SListShow(SList* plist);
void SListPushFront(SList* plist, ElemType x);
void SListPopBack(SList* plist);
void SListPopFront(SList* plist);
int SListLength(SList* plist);
void SListInsertByVal(SList* plist, ElemType x);
int SListFind(SList* plist, ElemType key);
void SListDeleteByVal(SList* plist, ElemType key);
void SListClear(SList* plist);
void SListDestroy(SList* plist);
void SListReverse(SList* plist);
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, ElemType x);
void SLIstInsertAfter(SListNode* pos, ElemType x);


void SListInit(SList* plist)
{
	plist->head = NULL;
}
SListNode* _Buynode()
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}
void SListPushBack(SList* plist, ElemType x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s -> data = x;
	//查找链表尾部
	SListNode* p = plist->head;
	if (p == NULL)
		plist->head = s;
	else
	{
		while (p -> next != NULL)
			p = p->next;
		p->next = s;
	}
}
void SListShow(SList* plist)
{
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
void SListPushFront(SList* plist, ElemType x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	s->next = plist->head;
	plist->head = s;
}
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL)
	{
		if (p->next == NULL);
		else
		{
			SListNode* pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
}
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL)
	{
		plist->head = p->next;
		free(p);
	}
}
int SListLength(SList* plist)
{
	assert(plist);
	int len = 0;
	SListNode* p = plist->head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
int SListFind(SList* plist, ElemType key)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
void SListDeleteByVal(SList* plist, ElemType key)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while (p != NULL && p->data != key)
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL)
	{
		if (pre == NULL)
			plist->head = p->next;
		else
			pre->next = p->next;
		free(p);
	}

}
void SListClear(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}
void SListDestroy(SList* plist)
{
	SListClear(plist);
}
void SListInsertByVal(SList* plist, ElemType x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	if (plist->head == NULL)
		plist->head = s;
	else
	{
		SListNode* p = plist->head;
		SListNode* pre = NULL;
		while (p != NULL && x > p->data)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)
		{
			s->next = p;
			plist->head = s;
		}
		else
		{
			s->next = pre->next;
			pre->next = s;
		}
	}
}
void SListReverse(SList* plist)
{
	assert(plist);
	SListNode *p, *q;
	if (plist->head == NULL)
		return;
	if (plist->head->next == NULL)
		return;
	//切割链表
	p = plist->head->next;
	plist->head->next = NULL;
	//将剩余链表节点一一进行头插
	q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}
void SListSort(SList* plist)
{
	assert(plist);
	SListNode* q, * p;
	if (plist->head == NULL || plist->head->next == NULL)
		return;
	//断开连接
	p = plist->head->next;
	plist->head->next = NULL;
    
	q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)
		{
			pre = t;
			t = t->next;
		}
	if(pre == NULL)
	{
		p->next = plist->head;
		plist->head = p;
	}
	else
	{
		p->next = pre->next;
		pre->next = p;
	}
	p = q;
	}
}
void SListRemoveAll(SList* plist, ElemType x)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while (p != NULL)
	{
		while (p != NULL && p->data != x)
		{
			pre = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (pre == NULL)
				plist->head = p->next;
			else
				pre->next = p -> next;
			free(p);
		}
		if (NULL != pre)
			p = pre->next;
		else
			p = plist->head;

	}
}