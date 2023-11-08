#include "linkedlist.h"
#include <stdlib.h>
//
#include <stdio.h>
//

LinkedList	*createLinkedList(void)
{
	LinkedList	*newLList = NULL;

	newLList = (LinkedList *)malloc(sizeof(LinkedList));
	if (newLList)
	{
		newLList -> currentElementCount = 0;
		(newLList -> headerNode).pLink = NULL;
	}	
	return (newLList);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	int			idx, ret = ERROR;
	ListNode	*new;
	ListNode	*next;
	ListNode	*pre = NULL;

	if (pList)
	{
		if (0 <= position && position <= pList -> currentElementCount)
		{
			new = malloc(sizeof(ListNode));
			if (!new)
				return (ret);
			*new = element;
			next = (pList -> headerNode).pLink;
			idx = 0;
			while (idx < position)
			{
				pre = next;
				next = next -> pLink;
				idx++;
			}
			new -> pLink = next;
			if (pre)
				pre -> pLink = new;
			else
				(pList -> headerNode).pLink = new;
			pList -> currentElementCount++;
			ret = position;
		}
	}
	return (ret);
}

int	removeLLElement(LinkedList *pList, int position)
{
	int			idx = 0, ret = ERROR;
	ListNode	*next;
	ListNode	*pre = NULL;

	if (pList)
	{
		if (0 <= position && position < pList -> currentElementCount)
		{
			next = (pList -> headerNode).pLink;
			while (idx++ < position)
			{
				pre = next;
				next = next -> pLink;
			}
			if (position == 0)
				(pList -> headerNode).pLink = next -> pLink;	
			else if (pre)
				pre -> pLink = next -> pLink;
			next -> data = 0;
			next -> pLink = NULL;
			free(next);
			pList -> currentElementCount--;
			ret = position;
		}
	}
	return (ret);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{
	int			idx;
	ListNode	*ret = NULL;
	
	if (pList)
	{
		if (0 <= position && position < pList -> currentElementCount)
		{
			ret = (pList -> headerNode).pLink;
			idx = 0;
			while (idx++ < position)	
				ret = ret -> pLink;
		}
	}
	return (ret);
}

void clearLinkedList(LinkedList *pList)
{
	ListNode	*tmp;
	ListNode	*next;

	if (pList)
	{
		next = (pList -> headerNode).pLink;
		while (next)
		{
			tmp = next -> pLink;
			next -> data = 0;
			next -> pLink = NULL;
			free(next);
			next = tmp;
		}
		(pList -> headerNode).pLink = NULL;
		pList -> currentElementCount = 0; 
	}
}

int	getLinkedListLength(LinkedList* pList)
{
	int ret = ERROR;
	if (pList)
		ret  = pList -> currentElementCount;
	return (ret);
}

void deleteLinkedList(LinkedList *pList)
{
	if (pList)
	{
		clearLinkedList(pList);
		free(pList);
	}
}
//
//
//
//
//
void	display_linked_list(LinkedList *pList)
{
	int			i_value;
	int			i_index;
	int			count;
	const int	NUMBERS_PER_LINE = 5;
	ListNode	*curr;
	curr = pList->headerNode.pLink;
	i_value = 0;
	i_index = 0;
	while (i_value < pList -> currentElementCount)
	{
		printf(" %9d |", curr->data);
		if(i_value % NUMBERS_PER_LINE == NUMBERS_PER_LINE - 1
			|| i_value + 1 == pList->currentElementCount)
		{
			count = i_value - i_index + 1;
			printf("\n");
			while (i_value >= i_index)
			{
				printf(" %9d |", i_index);
				i_index++;
			}
			printf("\n");
			while (count > 0)
			{
				printf("------------");
				count--;
			}
			printf("\n");
		}
		curr = curr -> pLink;
		i_value++;
	}
}
