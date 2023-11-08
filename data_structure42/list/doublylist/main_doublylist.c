#include "doublylist.h"
#include <stdio.h>
int	main(void)
{
	DoublyList		*list;
	DoublyListNode	*ptr;
	DoublyListNode	element;

	list = createDoublyList();
	for (int i = 0 ; i < 7; i++)
	{
		element.data = i * 3;
		printf("[%d] stored\n", addDLElement(list, i, element));	
	}
	displayDoublyList(list);
	for (int i = 5 ; i < 8; i++)
	{
		element.data = 42 + i ;
		printf("[%d] stored\n", addDLElement(list, i, element));
		displayDoublyList(list);
	}
	puts("\ngettest=====\n");
	ptr = getDLElement(list, 5);printf("result of : ptr = getDLElement(list, 5)\n");
	printf("\n pre : %d, ptr : %d, next : %d\n", (ptr -> pLLink) -> data, ptr -> data, (ptr -> pRLink) -> data);

	puts("\nremovetest=====\n");
	

	printf("[%d] removed\n", removeDLElement(list, 9));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 0));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 6));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 6));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 3));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 4));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 1));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 2));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 0));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	
	printf("[%d] removed\n", removeDLElement(list, 0));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayDoublyList(list);	
	deleteDoublyList(list);
	return (0);
}
