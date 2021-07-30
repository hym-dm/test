#define  _CRT_SECURE_NO_WARNINGS 1
#include"Sysutil.h"
#define ElemType int
#define SEQLIST_DEFAULT_SIZE 8
typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;

bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
void SeqListInit(SeqList *pst);
void SeqListPushBack(SeqList *pst, ElemType x);
void SeqListShow(SeqList* pst);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
ElemType SeqListCapacity(SeqList* pst);
ElemType SeqListLength(SeqList* pst);
void SeqListDeleteByVal(SeqList* pst, ElemType pos);
int SeqListFind(SeqList* pst, ElemType key);
void SeqListSort(SeqList* pst);
void SeqListDeleteByPos(SeqList* pst, ElemType pos);
void SeqListDestory(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListDestory(SeqList* pst);
void SeqListInsertByPos(SeqList* pst, int pos, ElemType key);

////////////////////////////////////////
bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;// ע��
}
void SeqListInit(SeqList* pst)
{
	assert(pst);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst);
    //�ж��Ƿ���
	if (IsFull(pst))
	{
		printf("˳�������,%d����ͷ������.\n", x);
		return ;
	}
	pst->base[pst->size++] = x;
}
void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("˳�������,%d����β������.\n", x);
		return;
	}
	//�ƶ�����
	for (int i = pst->size; i > 0; i--)
		pst->base[i] = pst->base[i - 1];
	// ͷ������
	pst->base[0] = x;
	//Ԫ��++
	pst->size++;
}
void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; ++i)  //0 1 2 3 4 5
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿ�, ����β��ɾ��.\n");
		return;
	}
	pst->size--;
}
void SeqListPopFront(SeqList *pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����Կգ�����ͷ��ɾ����\n");
		return;
	}
	for (int i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	    pst->size--;
		return;
}
ElemType SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}
ElemType SeqListLength(SeqList* pst)
{
	return pst->size;
}
int  SeqListFind(SeqList* pst, ElemType key)
{
	for (int i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}
	return -1;
}
void SeqListSort(SeqList* pst)
{
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - 1 - i; j++)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				pst->base[j] ^= pst->base[j + 1];
				pst->base[j + 1] ^= pst->base[j];
				pst->base[j] ^= pst->base[j + 1];
			}
		}
	}
}
void SeqListDeleteByVal(SeqList* pst, ElemType key)
{
	assert(pst);
	int index = SeqListFind( pst, key);
	if (index == -1)
	{
		printf("Ҫɾ����Ԫ��%d������\n", key);
		return;
	}
	SeqListDeleteByPos(pst, index);
}
void SeqListDeleteByPos(SeqList* pst, ElemType pos)
{
	assert(pst && (pos>=0 && pos <= pst->size));
	for (int i = pos; i < pst->size; i++)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}
void SeqListClear(SeqList* pst)
{
	assert(pst);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
void SeqListDestory(SeqList* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;//pst =NULL???
	pst->size = pst->capacity = 0;
}
void SeqListInsertByPos(SeqList* pst, int pos, ElemType key)
{
	assert(!IsFull(pst));
	assert(pst && (pos >= 0 && pos <= pst->size));
	pst->size++;
	for (int i = pst->size-1; i >= pos; i--)
	{
		pst->base[i + 1] = pst->base[i];
	}
	pst->base[pos] = key;
}