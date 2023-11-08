#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapNodeType
{
	int data;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxCount;
	int currentCount;
	HeapNode	*pData;
} ArrayMaxHeap, ArrayMiniHeap;

struct ArrayHeapType	*createArrayHeap(int maxCount);
int insertMaxHeapAH(ArrayMaxHeap *pHeap, int value);
int removeMaxHeapAH(ArrayMaxHeap *pHeap, int value);
int insertMinHeapAH(ArrayMinHeap *pHeap, int value);
int removeMinHeapAH(ArrayMinHeap *pHeap, int value);
void deleteArrayHeap(struct ArrayHeapType *pHeap);
void displayArrayHeap(struct ArrayHeapType* pHeap);

#endif
#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif


