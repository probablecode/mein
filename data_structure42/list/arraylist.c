/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:50:37 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/18 18:10:48 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>
ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*newArrayList = NULL;

	if (0 < maxElementCount)
	{
		newArrayList = (ArrayList *)malloc(sizeof(ArrayList));
		if (newArrayList)
		{
			newArrayList -> pElement = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));
			if (newArrayList -> pElement)
			{
				newArrayList -> maxElementCount = maxElementCount;
				newArrayList -> currentElementCount = 0;
			}
			else
			{
				free(newArrayList);
				newArrayList = NULL;
			}
		}
	}
	return (newArrayList);
}

void	deleteArrayList(ArrayList	*pList)
{
	if (pList)
	{	
		clearArrayList(pList);
		free(pList -> pElement);	
		pList -> pElement = NULL;	
		pList -> maxElementCount = 0;
		free(pList);
		pList = NULL;
	}
}

int	isArrayListFull(ArrayList *pList)
{
	if (pList)
		return (pList -> maxElementCount <= pList -> currentElementCount);
	else
		return (ERROR);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	max, cur, i, ret = ERROR;
	ArrayListNode	*arrayList;

	if (pList)
	{
		cur = pList -> currentElementCount;
		max = pList -> maxElementCount;
		if(cur < max && 0 <= position && position <= cur)
		{
			arrayList = pList -> pElement;
			i = cur;
			while (position < i--)
				arrayList[i + 1] = arrayList[i];
			arrayList[position] = element;
			pList -> currentElementCount++;
			ret = position;
		}
	}
	return (ret);
}

int	removeALElement(ArrayList *pList, int position)
{
	int cur, ret = ERROR;
	ArrayListNode	*pE;
	
	if (pList)
	{
		cur = pList -> currentElementCount;
		pE = pList -> pElement;
		if (0 <= position && position < cur)
		{
			ret = position;
			while (position < cur)
			{
				pE[position] = pE[position + 1];
				position++;
			}
			pE[cur].data = 0;
			pList -> currentElementCount--;
		}
	}
	return (ret);
}

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (pList)
	{ 
		if (0 <= position && position < pList -> currentElementCount)
			return (pList -> pElement + position);
	}
	return (NULL);
}

void	displayArrayList(ArrayList *pList)
{
	int	idx, cur;
	if (pList)
	{
		cur = pList -> currentElementCount;
		idx = 0; 
		while (idx < cur)
		{
			printf("%10d | ", pList->pElement[idx].data);
			idx++;
			if (idx % 5 == 0)
				printf("\n");
		}
	}
}
void	clearArrayList(ArrayList *pList)
{
	unsigned char	*ptr;
	size_t			i = 0;
	size_t			size;

	if (pList)
	{
		ptr = (unsigned char *)pList -> pElement;
		size = pList -> maxElementCount * sizeof(ArrayListNode);
		while (i < size)
		{
			ptr[i] = (unsigned char)0;
			i++;
		}
		pList -> currentElementCount = 0;
	}
}

int	getArrayListLength(ArrayList *pList)
{
	if (pList)
		return (pList -> currentElementCount);
	return (ERROR);
}
