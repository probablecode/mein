#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

void	displayLD(LinkedDeque *pDeque)
{
	if (pDeque)
	{
		printf("\n<displayLD>\n");
		if (!pDeque -> currentElementCount)
			printf("No Element in LinkedDeque");
		else
			{
				for (DequeNode *node = pDeque -> pFrontNode; node; node = node -> pRLink)
					printf(" | [%c] | ", node -> data);
			}
		printf("\n");
	}
	else
		printf("[No LinkedDeque]\n");
}

int	main(void)
{
	LinkedDeque	*ld;
	DequeNode	element;
	DequeNode	*ptr;

	
	printf("\n<createLinkedDeque>\n");
	ld = createLinkedDeque();
	
	printf("\n<insertFrontLD>\n");
	for (int i = 0; i < 4; i++)
	{
		displayLD(ld);
		element.data = 'a' + i;
		insertFrontLD(ld, element);
	}
	
	displayLD(ld);
	printf("\n<insertRearLD>\n");
	for (int i = 0; i < 4; i++)
	{
		displayLD(ld);
		element.data = 'a' + i;
		insertRearLD(ld, element);
	}

	printf("\n<peekLD>\n");
	ptr = peekFrontLD(ld);
	printf("peekFrontLD -> data : %c \n", ptr -> data);
	displayLD(ld);

	ptr = peekRearLD(ld);
	printf("peekRearLD -> data : %c \n", ptr -> data);
	displayLD(ld);
		
	printf("\n<deleteFrontLD>\n");
	ptr = deleteFrontLD(ld);
	printf("deleteFrontLD -> data : %c \n", ptr -> data);
	free(ptr);
	displayLD(ld);

	printf("\n<deleteFrontLD>\n");
	ptr = deleteFrontLD(ld);
	printf("deleteFrontLD -> data : %c \n", ptr -> data);
	free(ptr);
	displayLD(ld);

	printf("\n<deleteRearLD>\n");
	ptr = deleteRearLD(ld);
	printf("deleteRearLd -> data : %c \n", ptr -> data);
	free(ptr);
	displayLD(ld);

	printf("\n<insertRearLD>\n");
	for (int i = 0; i < 4; i++)
	{
		displayLD(ld);
		element.data = 'a' + i;
		insertRearLD(ld, element);
	}
	displayLD(ld);
	deleteLinkedDeque(ld);
	return (0);
}
