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
} ArrayMaxHeap, ArrayMinHeap;

struct ArrayHeapType	*createAH(int maxCount);
int insertMaxAH(ArrayMaxHeap *pHeap, int value);
HeapNode	*removeMaxAH(ArrayMaxHeap *pHeap);
int insertMinAH(ArrayMaxHeap *pHeap, int value);
HeapNode	*removeMinAH(ArrayMaxHeap *pHeap);
void deleteAH(struct ArrayHeapType *pHeap);
void displayAH(struct ArrayHeapType* pHeap);

#endif
#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif

