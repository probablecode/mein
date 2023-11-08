#include "arrayheap.h"
#include <stdio.h>
#include <stdlib.h> 
int	main(void)
{
	int	random[15] = {3, 7, 42, 6, 54, 34, 11, 23, 12, 35, 43, 41, 40, 31, 80};
	ArrayMaxHeap *pMaxHeap = createAH(15);
	HeapNode	*ptr;
	for (int i = 0; i < 15; i++)
	{
		if (insertMaxAH(pMaxHeap, random[i])== FALSE)
		{
			printf("\n[Error Occur!]\n");
			break;
		}
		displayAH(pMaxHeap);
	}
	for (int i = 0; i < 15; i++)
	{
		if (ptr = removeMaxAH(pMaxHeap))
		{
			printf("\n %d is returned \n", ptr -> data);
			free(ptr);
		} 
		else
		{
			printf("\n[Error Occur!]\n");
			break;
		}
		displayAH(pMaxHeap);
	} 
	deleteAH(pMaxHeap);
	displayAH(pMaxHeap);
	return (0);
}
