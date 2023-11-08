#include"linkedqueue.h"
#include<stdio.h>

void	displayLQ(LinkedQueue *pQueue);

int main()
{
	LinkedQueue			*pQueue;
	LinkedQueueNode		node;
	LinkedQueueNode		*tmp;
	
	pQueue = createLinkedQueue();
	displayLQ(pQueue);
	node.pLink = NULL;
	displayLQ(pQueue);
	for(int i = 0; i < 7; i++)
	{
		node.data = i + '0';
		enqueueLQ(pQueue,node);
		displayLQ(pQueue);
	}
	displayLQ(pQueue);
	tmp = peekLQ(pQueue);
	if(tmp)
		printf("peeked data : %c\n", tmp->data);
		
	for(int i = 0; i < 7; i++)
	{
		displayLQ(pQueue);
		dequeueLQ(pQueue);
	}
	tmp = peekLQ(pQueue);
	if(!tmp)
		printf("no node!\n");
	deleteLinkedQueue(pQueue);
}

void	displayLQ(LinkedQueue *pQueue)
{
	int	i;
	LinkedQueueNode	*tmp;

	if(!pQueue)
		printf("no linked queue!\n");
	else if(isLinkedQueueEmpty(pQueue))
		printf("no node in linked queue!\n");
	else
	{
		i = 0;
		tmp = pQueue->pFrontNode;
		while(tmp)
		{
			printf(" | [%d] : %c| ", i++, tmp -> data );
			tmp = tmp->pLink;
		}
		printf("\n");
	}
}
