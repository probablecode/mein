#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList* createDoublyList()
{
	DoublyList	*newDList = NULL;

	newDList = (DoublyList *)malloc(sizeof(DoublyList));
	if (newDList)
	{
		newDList -> currentElementCount = 0;
		(newDList -> headerNode).pLLink = NULL;
		(newDList -> headerNode).pRLink = NULL;
	}
	return (newDList);
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList)
	{
		clearDoublyList(pList);
		free(pList);
	}
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	int				idx = 0;
	int				ret = ERROR;
	DoublyListNode	*pre = NULL;
	DoublyListNode	*next;
	DoublyListNode	*new;

	if (pList)
	{
		if (0 <= position && position <= pList -> currentElementCount)
		{
			new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
			if (new)
			{
				*new = element;
				new -> pRLink = NULL;			
				next = (pList -> headerNode).pRLink;
				while (idx < position)
				{
					pre = next;
					next = next -> pRLink;
					idx++;
				}
				if (pre)
				{
					pre -> pRLink = new;
					new -> pLLink = pre;
				}
				else
				{
					(pList -> headerNode).pRLink = new;
					new -> pLLink = &(pList -> headerNode);
				} 
				if (next)
					next -> pLLink = new;
				new -> pRLink = next;
				(pList -> currentElementCount)++;
				ret = position;
			}
		}
	}
	return (ret);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*pre = NULL;
	DoublyListNode	*next;
	DoublyListNode	*tmp;
	int	idx = 0;
	int	ret = ERROR;
	
	if (pList)
	{
		if (0 <= position && position < pList -> currentElementCount)
		{
			tmp = (pList -> headerNode).pRLink;
			while (idx++ < position)
				tmp = tmp -> pRLink;
			next = tmp -> pRLink;
			pre = tmp -> pLLink;
			pre -> pRLink = next;
			if (next)
				next -> pLLink = pre;
			tmp -> data = 0;
			tmp -> pRLink = NULL;
			tmp -> pLLink = NULL;
			free(tmp);
			(pList -> currentElementCount)--;
			ret = position;
		}
	}
	return (ret);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode	*tmp;
	DoublyListNode	*next;
	
	if (pList)
	{
		next = (pList -> headerNode).pRLink;
		while (next)
		{
			tmp = next -> pRLink;
			next -> data = 0;
			next -> pLLink = NULL;
			next -> pRLink = NULL;
			free(next);
			next = tmp;
		} 
		pList -> currentElementCount = 0;
		(pList -> headerNode).pRLink = NULL;
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList)
		return (pList -> currentElementCount);
	else
		return (ERROR);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode	*ret = NULL;
	int				idx = 0;
	if (pList)
	{
		if (0 <= position && position < pList -> currentElementCount)
		{
			ret = (pList -> headerNode).pRLink;
			while (idx++ < position)
				ret = ret -> pRLink;
		}
	}
	return (ret);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*next = NULL;	
	int				idx = 0;
	
	if (pList)
	{
		next = (pList -> headerNode).pRLink;
		if (!next)
			printf("[Empty DoublyList]");
		while (next)
		{
			printf("| [%d] : %d | ", idx++, next -> data);
			next = next -> pRLink;
		}
		printf("\n");
	}
}
