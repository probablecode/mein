#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList* createDoublyList()
{
	DoublyList	*newDList = NULL;

	newDList = (DoublyList *)malloc(sizeof(DoublyList));
	if (newDList)
	{
		newDList -> currentElementCount = 0;
		(newDList -> headerTerm).pLLink = NULL;
		(newDList -> headerTerm).pRLink = NULL;
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
				next = (pList -> headerTerm).pRLink;
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
					(pList -> headerTerm).pRLink = new;
					new -> pLLink = &(pList -> headerTerm);
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
			tmp = (pList -> headerTerm).pRLink;
			while (idx++ < position)
				tmp = tmp -> pRLink;
			next = tmp -> pRLink;
			pre = tmp -> pLLink;
			pre -> pRLink = next;
			if (next)
				next -> pLLink = pre;
			(tmp -> mData).degree = 0;
			(tmp -> mData).coefficient = 0;
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
		next = (pList -> headerTerm).pRLink;
		while (next)
		{
			tmp = next -> pRLink;
			next -> pLLink = next;
			(tmp -> mData).degree = 0;
			(tmp -> mData).coefficient = 0;
			next -> pLLink = NULL;
			next -> pRLink = NULL;
			free(next);
			next = tmp;
		} 
		pList -> currentElementCount = 0;
		(pList -> headerTerm).pRLink = NULL;
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList)
		return (pList -> currentElementCount);
	else
		return (ERROR);
}

DoublyListNode* getDLElement(DoublyList* pPoly, int position)
{
	DoublyListNode	*ret = NULL;
	int				idx = 0;
	if (pPoly)
	{
		if (0 <= position && position < pPoly -> currentElementCount)
		{
			ret = (pPoly -> headerTerm).pRLink;
			while (idx++ < position)
				ret = ret -> pRLink;
		}
	}
	return (ret);
}

void displayPolynomial(Polynomial* pPoly)
{
	DoublyListNode	*next = NULL;	
	int				idx = 0;
	
	if (pPoly)
	{
		next = (pPoly -> headerTerm).pRLink;
		if (!next)
			printf("[Empty Polynomial]");
		while (next)
		{
			printf("+  (%d * [x^%d]) ", (next -> mData).coefficient, (next -> mData).degree);
			next = next -> pRLink;
		}
		printf("\n");
	}
}
