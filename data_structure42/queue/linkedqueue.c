#include "linkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
LinkedQueue* createLinkedQueue()
{
	LinkedQueue	*new = NULL;
	
	new = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (new)
	{
		new -> currentElementCount = 0;
		new -> pFrontNode = NULL;
		new -> pRearNode = NULL;
	}
	return (new);
}

int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element)
{
	LinkedQueueNode	*node = NULL;
	int ret = FALSE;

	if (pQueue)
	{
		node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
		if (node)
		{
			*node = element;
			node -> pLink = NULL;
			if (isLinkedQueueEmpty(pQueue))
				pQueue -> pFrontNode = node;
			else
				(pQueue -> pRearNode) -> pLink = node;
			pQueue -> pRearNode = node;
			(pQueue -> currentElementCount)++;
			ret = TRUE;
		}
	}
	return	(ret);
}

LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*toDelete = peekLQ(pQueue);
	
	if (toDelete)
	{
		pQueue -> pFrontNode = toDelete -> pLink;
		if (!(pQueue -> pFrontNode))
			pQueue -> pRearNode = NULL;
		toDelete -> pLink = NULL;
		(pQueue -> currentElementCount)--;
	}
	return (toDelete);
}

LinkedQueueNode *peekLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*peek = NULL;

	if (!isLinkedQueueEmpty(pQueue))
		peek = pQueue -> pFrontNode;
	return (peek);
}
int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	int	ret = ERROR;

	if (pQueue)
		ret = (pQueue -> currentElementCount <= 0);
	return (ret);
}
void deleteLinkedQueue(LinkedQueue* pQueue)
{
	LinkedQueueNode	*node;

	if (pQueue)
	{
		node = dequeueLQ(pQueue);		
		while (node)
		{
			memset (node, 0, sizeof(LinkedQueueNode));
			free (node);
			node = dequeueLQ(pQueue);
		}
		memset (pQueue, 0, sizeof(LinkedQueue));
		free (pQueue);
	}
}
