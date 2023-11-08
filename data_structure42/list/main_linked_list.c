#include <stdio.h>
#include "linkedlist.h"

int	main(void)
{
	LinkedList	*list;
	ListNode	temp;

	list = createLinkedList();
	for (int i = 0; i <17; i++)
	{
		temp.data = i * 2;
		temp.pLink = NULL;
		printf("add : %d\n", addLLElement(list, i, temp));
		display_linked_list(list);
	}
	for (int i = 16; i >= 0; i--)
	{
		printf("remove : %d\n", removeLLElement(list, i));
		display_linked_list(list);
	}
	deleteLinkedList(list);
	return (0);
}
