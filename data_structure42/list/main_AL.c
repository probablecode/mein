#include "arraylist.h"
int	main(void)
{
	ArrayListNode	new;
	
	ArrayList	*arr1 = createArrayList(5);
	for (int i = 5; 0 < i; i--)
	{
		new.data = i;
		addALElement(arr1, getArrayListLength(arr1), new);
	}
	displayArrayList(arr1);
	removeALElement(arr1, getArrayListLength(arr1) - 3);
	displayArrayList(arr1);
	clearArrayList(arr1);
	displayArrayList(arr1);
	deleteArrayList(arr1);
	return (0);
}
/*
#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct	ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int	maxElementCount;
	int	currentElementCount;
	ArrayListNode	*pElement;
} ArrayList;

ArrayList	*createArrayList(int maxElementCount);
void	deleteArrayList(ArrayList	*pList);
int	isArrayListFull(ArrayList *pList);
int	addALElement(ArrayList *pList, int position, ArrayListNode element);
int	removeALElement(ArrayList *pList, int position);
ArrayListNode	*getALElement(ArrayList *pList, int position);
void	displayArrayList(ArrayList *pList);
void	clearArrayList(ArrayList *pList);
int	getArrayListLength(ArrayList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
*/
