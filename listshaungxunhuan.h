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
void SListInsertAfter(SList *plist,SListNode* pos, ElemType x);
void SListEraseAfter(SList *plist,SListNode* pos);


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
void SListInsertAfter(SList* plist, SListNode* pos, ElemType x)
{
	
	assert(pos);
	SListNode* s = _Buynode();
	s->data = x;
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	if (plist->head == NULL);
	return NULL;
	while (p != NULL && p != pos)
	{
		pre = p;
		p = p->next;	
	}
	if (p == NULL)
		p = s;
	else
	{
		if (pre = NULL)
			plist->head = s;
		else
		s->next = pre->next;
		pre->next = s;
	}
}
void SListEraseAfter(SList* plist, SListNode* pos)
{
	assert(pos);
	SListNode* p = plist->head;
	if (plist->head == NULL)
		return NULL;
	while (p != NULL && p != pos)
	{
		p = p->next;
	}
	if (p = NULL)
		return plist->head;
	else
		p->next = NULL;

}
//////////////////////////////////////////////////////////////////
//带头结点双向循环列表
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode* prev;
	struct DCListNode* next;
}DCListNode;
typedef struct DCList
{
	DCListNode* first;
	DCListNode* last;
	size_t size;
}DCList;
DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->next = s->prev = NULL;
	s->data = x;
	return s;
}
void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist, ElemType x);
void DCListShow(DCList* plist);
void DCListPushFront(DCList* plist, ElemType x);
void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);
void DCListClear(DCList* plist);
void DCListDestroy(DCList* plist);
DCListNode* DCListFind(DCList* plist, ElemType key);
void DCListDeleteByVal(DCList* plist);
void DCListReverse(DCList* plist);
void DCListInsertByval(DCList* plist, ElemType x);



void DCListInit(DCList* plist)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size = 0;
}
void DCListPushBack(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	s->prev = plist->last;
	plist->last->next = s;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	plist->size++;
}
void DCListShow(DCList* plist)
{
	DCListNode* p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over\n");
}
void DCListPushFront(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	s->next = plist->first->next;
	plist->first->next->prev = s;
	plist ->first ->next = s;
	s->prev = plist->first;
    if (plist->last == plist->first)//注意 ???
	plist->last = s;//
	
	plist->size++;
}
void DCListPopBack(DCList* plist)
{
	assert(plist);
	DCListNode* p = plist->last;
	if (p != plist->first)
	{
		plist->last = p->prev;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		free(p);
		plist->size--;
	}
}
void DCListPopFront(DCList* plist)
{
	assert(plist);
	DCListNode* p;
	if (plist->size == 0)
		return;
	p = plist->first->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->last = plist->first;
}
void DCListClear(DCList* plist)
{
	assert(plist);
	DCListNode* p = plist->first->next;
	if (plist->size == 0)
		return;
	while (p != plist->first)
	{
		p->prev -> next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
	plist->last = plist->first;
}
void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}
DCListNode* DCListFind(DCList* plist, ElemType key)
{
	assert(plist);
	DCListNode* p = plist->first->next;
	while (p != plist->first && p->data != key)
	{
		p = p->next;
		if (p == plist->first)
			return NULL;
	}
	return p;
}
void DCListDeleteByVal(DCList* plist,ElemType key)
{

	assert(plist);
	DCListNode* p = DCListFind(plist, key);
	if (p != NULL)
	{
		if (p == plist->last)
			plist->last = p->prev;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		plist->size--;
	}
}
void DCListReverse(DCList* plist)
{
	assert(plist);
	DCListNode *p, *q;
	if (plist->size <= 1)
		return;

	p = plist->first->next;
	q = p->next;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	while (q != plist->first)
	{
		p = q;
		q = q->next;

		p->next = plist->first->next;
		p->next->prev = p;
		p->prev = plist->first;
		p->prev->next = p;
	}

}
void DCListInsertByval(DCList* plist, ElemType x)
{
	assert(plist);
	DCListNode* s = _BuyDCListNode(x);
	DCListNode* p = plist->first->next;
	while (p != plist->first && x > p->data)
		p = p->next;
	if (p == plist->first)
		plist->last = s;

	s->next = p;
	s->next = p;
	s->prev = p->prev;
	s->next->prev = s;
	s->prev->next = s;
	plist->size++;
}


