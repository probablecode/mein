#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue	*new = NULL;

	if (0 < maxElementCount)
	{
		new = (ArrayQueue *)malloc(sizeof(ArrayQueue));
		if (new)
		{
			new -> pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
			if (new -> pElement)
			{
				new -> maxElementCount = maxElementCount;
				new -> currentElementCount = 0;
				new -> front = -1;
				new -> rear = -1;
			}
			else
			{
				free (new);
				new = NULL;
			}
		}
	}
	else
		printf("createArrayQueue() : invalid argument\n");
	return (new);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int	ret = FALSE;
	int maxLen;

	if (!isArrayQueueFull(pQueue))
	{
		maxLen = pQueue -> maxElementCount;
		(pQueue -> rear) = ((pQueue -> rear) + 1) % maxLen;
		(pQueue -> pElement)[pQueue -> rear] = element;
		(pQueue -> currentElementCount)++;
		ret = TRUE;
	}
	return (ret);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*dstNode = NULL;
	ArrayQueueNode	*srcNode = peekAQ(pQueue);
	int	maxlen;

	if (srcNode)
	{
		dstNode = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
		if (dstNode)
		{
			memcpy(dstNode, srcNode, sizeof(ArrayQueueNode));
			memset(srcNode, 0, sizeof(ArrayQueueNode));
			maxlen = pQueue -> maxElementCount;
			pQueue -> front = (pQueue -> front + 1) % maxlen;
			(pQueue -> currentElementCount)--;
		}
	}
	return (dstNode);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*node = NULL;
	int	maxlen;

	if (!isArrayQueueEmpty(pQueue))
	{
		maxlen = pQueue -> maxElementCount;
		node = pQueue -> pElement + ((pQueue -> front + 1) % maxlen);
	}
	return (node);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue)
	{
		memset(pQueue->pElement, 0, sizeof(ArrayQueueNode) * pQueue -> maxElementCount);
		free(pQueue->pElement);
		memset(pQueue, 0, sizeof(ArrayQueue));
		free(pQueue);
	}
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue)
		return (pQueue -> currentElementCount == pQueue -> maxElementCount);
	else
		return (ERROR);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue)
		return (pQueue -> currentElementCount == 0);
	else
		return (ERROR);
}
