#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
void displayAQ(ArrayQueue *pQueue)
{
	if (pQueue)
	{
		printf("\n<displayAQ>\n");
		if (!pQueue -> currentElementCount)
			printf("No Element in ArrayQueue");
		else
			{
				for (int i = (pQueue -> front + 1) % (pQueue -> maxElementCount); i != pQueue -> rear; i = (i + 1) % (pQueue -> maxElementCount))
					printf(" | [%d] : %c | ", i, (pQueue -> pElement)[i].data);
				printf(" | [%d] : %c | ", pQueue -> rear, (pQueue -> pElement)[pQueue -> rear].data);
			}
		printf("\n");
	}
	else
		printf("[No ArrayQueue]\n");
}
int	main(void)
{
	ArrayQueue	*aq;
	ArrayQueueNode element;
	ArrayQueueNode *ptr;

	
	printf("\n<createArrayQueue>\n");
	aq = createArrayQueue(-4);
	aq = createArrayQueue(5);
	
	printf("\n<enqueueAQ>\n");
	for (int i = 0; i < 4; i++)
	{
		displayAQ(aq);
		element.data = 'a' + i;
		enqueueAQ(aq, element);
	}
	displayAQ(aq);
	printf("\n<dequeueAQ>\n");
	for (int i = 0; i < 3; i++)
	{
		ptr = dequeueAQ(aq);
		printf("ptr -> data : %c \n", ptr -> data);
		free(ptr);
		displayAQ(aq);
	}
	printf("\n<peekAQ>\n");
	ptr = peekAQ(aq);
	printf("ptr -> data : %c \n", ptr -> data);
	displayAQ(aq);

	printf("\n<re enqueueAQ>\n");
	for (int i = 0; i < 4; i++)
	{
		displayAQ(aq);
		element.data = 'a' + i;
		enqueueAQ(aq, element);
	}
	displayAQ(aq);
	deleteArrayQueue(aq);

	return (0);
}
