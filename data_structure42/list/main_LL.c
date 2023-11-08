#include "linkedlist.h"
#include <stdio.h>
int	main(void)
{
	LinkedList	*list1;
	ListNode	new;
	int 		len;

	list1 = createLinkedList();
	for (int i = 0; i < 10; i++)
	{
		new.data = 42 * i;
		addLLElement(list1, getLinkedListLength(list1), new);
	}
	len = getLinkedListLength(list1);
	for (int i = 0; i < len; i++)
	{
		new = *getLLElement(list1, i);
		printf("[%d]%d	|", i, new.data);
	}
	
	printf("\n");
	removeLLElement(list1, 4);
	removeLLElement(list1, 4);
	len = getLinkedListLength(list1);
	
	for (int i = 0; i < len; i++)
	{
		new = *getLLElement(list1, i);
		printf("%d	|", new.data);	
	}
	printf("\n");
	clearLinkedList(list1);
	printf ("[%d] \n", getLinkedListLength(list1));

	deleteLinkedList(list1);
	
	return (0);
}
