#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graphlinkedlist.h"

LinkedList* createLinkedList(int gType)
{
	LinkedList	*newLList = (LinkedList *)malloc(sizeof(LinkedList));
	if (newLList)
	{
		newLList -> currentElementCount = 0;
		newLList -> graphType = gType;
		newLList -> headerNode = NULL;
	}
	return (newLList);
}

int addLGVertex(LinkedList* pList, int VID)
{
	int	result 	= FAIL;
	int flag	= SUCCESS;
	ListNode	*node;
	ListNode	*ptr;

	if (pList)
	{
		ptr = pList -> headerNode;
		if (ptr)
		{
			while (ptr -> pLink)
			{
				if (ptr -> data.vertexID == VID)
				{
					flag = FAIL;
					break;
				}
				ptr = ptr -> pLink;
			}
		}
		if (flag == SUCCESS)
		{
			node = (ListNode *)malloc(sizeof(ListNode));
			if (node)
			{
				node -> data.vertexID = VID;
				node -> data.weight = 0;
				node -> data.pVLink = NULL;
				if (!ptr)
					pList -> headerNode = node;
				else
					ptr -> pLink = node;
				(pList -> currentElementCount)++;
				result = SUCCESS;
			}
		}
	}
	return (result);
}
int	addLGEdge(LinkedList* pList, int fromVID, int toVID, int weight)
{
	
	int flag = FALSE;
	int	result = FAIL;
	GraphVertex	*new = NULL;
	ListNode	*ptr;
	ListNode	*pos = NULL;

	if (pList)
	{
		ptr = pList -> headerNode;
		while (ptr)
		{
			if (ptr -> data.vertexID == fromVID)
				pos = ptr;
			flag = (ptr -> data.vertexID == toVID);	
			if (pos && flag)
				break;
			ptr = ptr -> pLink;
		}
		if (pos && flag)
			new = (GraphVertex *)malloc(sizeof(GraphVertex));
		if (new)
		{
			new -> vertexID = toVID;
			new -> weight = weight;
			new -> pVLink = pos -> pLink;
			pos -> pLink = new;
			result = SUCCESS;
		}
	}
	return (result);
}

int removeLLElement(LinkedList* pList, int position)
{
	if (pList && position < pList -> currentElementCount)
}

ListNode* getLLElement(LinkedList* pList, int position)
{

}

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
