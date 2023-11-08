#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;		// \C3ִ\EB \BF\F8\BC\D2 \B0\B3\BC\F6
	int currentElementCount;	// \C7\F6\C0\E7 \BF\F8\BC\D2\C0\C7 \B0\B3\BC\F6
	int front;					// front \C0\A7ġ
	int rear;					// rear \C0\A7ġ
	ArrayQueueNode *pElement;	// \B3\EB\B5\E5 \C0\FA\C0\E5\C0\BB \C0\A7\C7\D1 1\C2\F7\BF\F8 \B9迭 \C6\F7\C0\CE\C5\CD
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif
