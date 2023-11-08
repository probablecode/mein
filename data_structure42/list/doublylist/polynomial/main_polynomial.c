#include "polynomial.h"
#include <stdio.h>
int	main(void)
{
	Polynomial		*list;
	Term			*ptr;
	Term			element;

	list = createDoublyList();
	for (int i = 7 ; 0 < i; i--)
	{
		element.mData.degree = i * 3;
		element.mData.coefficient = i + 1;
		printf("[%d] stored\n", addDLElement(list, 0, element));	
	}
/*
	displayPolynomial(list);
	for (int i = 5 ; i < 8; i++)
	{
		element.mData = 42 + i ;
		printf("[%d] stored\n", addDLElement(list, i, element));
		displayPolynomial(list);
	}
	puts("\ngettest=====\n");
	ptr = getDLElement(list, 5);printf("result of : ptr = getDLElement(list, 5)\n");
	printf("\n pre : %d, ptr : %d, next : %d\n", (ptr -> pLLink) -> mData, ptr -> mData, (ptr -> pRLink) -> mData);

*/
	puts("\nremovetest=====\n");
	

	printf("[%d] removed\n", removeDLElement(list, 6));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 2));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 1));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 3));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 3));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 4));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 1));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 2));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 0));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);
	
	printf("[%d] removed\n", removeDLElement(list, 0));
	printf("currentcount : %d\n", getDoublyListLength(list));
	displayPolynomial(list);	
	deleteDoublyList(list);
	return (0);
}
