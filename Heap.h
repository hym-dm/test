#include "Sysutil.h"

#define HeapElemType int
typedef struct Heap
{
	HeapElemType* heap;//堆空间
	size_t capacity;
	size_t size;
}Heap;
void HeapInit(Heap* php, int sz);
void HeapInitByArray(Heap* php, HeapElemType* ar, int n);
void HeapInsert(Heap* php, HeapElemType x);
void HeapRemove(Heap* php);
HeapElemType HeapTop(Heap* php);
void HeapShow(Heap* php);
void HeapClear(Heap* php);
void HeapDestroy(Heap* php);
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);

bool HeapFull(Heap* php)
{
	return php->size >= php->capacity;
}
bool HeapEmpty(Heap* php)
{
	return php->size == 0;
}


void HeapInitByArray(Heap* php, HeapElemType* ar, int n)
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * n);
	assert(php->heap != NULL);
	php->capacity = n;
	php->size = n;
	for (int i = 0; i < n; i++)
		php->heap[i] = ar[i];

	int curpos = n / 2 - 1;
	while (curpos >= 0)
		_AdjustDown(php, curpos);
	curpos--;
}
HeapElemType HeapTop(Heap* php)
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能取堆顶元素.\n");
		return;
	}
	return php->heap[0];
}
void HeapShow(Heap* php)
{
	for (int i = 0; i < php->size; ++i)
		printf("%d ", php->heap[i]);
	printf("\n");
}

void HeapInsert(Heap* php, HeapElemType x)
{
	if (HeapFull(php))
	{
		printf("对空间已满，%d不能插入.\n", x);
		return;
	}
	php->heap[php->size] = x;
	_AdjustUp(php, php->size);
	php->size++;
}

void HeapRemove(Heap* php)
{
	if (HeapEmpty(php))
	{
		printf("堆空间已空，不能删除堆顶元素.\n");
		return;
	}
	php->size--;
	php->heap[0] = php->heap[php->size];
	_AdjustDown(php, 0);
}
void HeapInit(Heap* php, int sz)
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * sz);
	assert(php->heap != NULL);
	memset(php->heap, 0, sizeof(HeapElemType) * sz);

	php->capacity = sz;
	php->size = 0;
}
void HeapClear(Heap* php)
{
	php->size = 0;
}
void HeapDestroy(Heap* php)
{
	free(php->heap);
	php->heap = NULL;
}
void _AdjustUp(Heap* php, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapElemType tmp = php->heap[j];

	while (j > 0)
	{
		if (tmp < php->heap[i])
		{
			php->heap[j] = php->heap[i];

			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->heap[j] = tmp;
}
void _AdjustDown(Heap* php, int start)
{
	int i = start;
	int j = 2 * i + 1;
	HeapElemType tmp = php->heap[i];

	while (j < php->size)
	{
		if (j + 1 < php->size && php->heap[j] > php->heap[j + 1])
			j = j + 1;

		if (tmp > php->heap[j])
		{
			php->heap[i] = php->heap[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	php->heap[i]= tmp;
}