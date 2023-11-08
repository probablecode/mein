#include "arrayheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ArrayHeapType	*createAH(int maxCount)
{
	struct ArrayHeapType	*new = NULL;

	if (0 < maxCount)
		new = (struct ArrayHeapType *)malloc(sizeof(struct ArrayHeapType));
	if (new)
	{
		new -> pData = (HeapNode *)calloc(maxCount + 1, sizeof(HeapNode));
		if (new -> pData)
		{
			(new -> pData)[0].data = 0;
			new -> maxCount = maxCount;
			new -> currentCount = 0;
		}
		else
		{
			free(new);
			new = NULL;
		}
	}
	return (new);
}

static void	swapAHNode(HeapNode *nodeA, HeapNode *nodeB)
{
	HeapNode tmp;

	if (nodeA && nodeB)
	{
		tmp = *nodeA;
		*nodeA = *nodeB;
		*nodeB = tmp;
	}
}

int insertMaxAH(ArrayMaxHeap *pHeap, int value)
{
	HeapNode	new;
	int	index;
	int	ret = FALSE;

	if (pHeap)
	{
		if (pHeap -> currentCount < pHeap -> maxCount)
		{
			new.data = value;
			index = ++(pHeap -> currentCount);
			(pHeap -> pData)[index] = new;
			while (1 < index && (pHeap -> pData)[index / 2].data < (pHeap -> pData)[index].data)
			{
				swapAHNode(pHeap -> pData + (index / 2), pHeap -> pData + index);
				index /= 2;
			}
			ret = TRUE;
		}
	}
	return (ret);
}

HeapNode	*removeMaxAH(ArrayMaxHeap *pHeap)
{
	HeapNode	*node = NULL;
	int	pIndex, cIndex;

	if (pHeap)
	{
		if (0 < pHeap -> currentCount)
		{
			swapAHNode((pHeap -> pData) + (pHeap -> currentCount), (pHeap -> pData) + 1);
			node = (HeapNode *)malloc(sizeof(HeapNode));
			if (node)
			{
				*node = (pHeap -> pData)[(pHeap -> currentCount)--];
				pIndex = 1;
				while (pIndex < pHeap -> currentCount)
				{
					cIndex = pIndex * 2;
					if ((pHeap -> pData)[cIndex].data < (pHeap -> pData)[cIndex + 1].data)
						cIndex++;
					if ((pHeap -> pData) + pIndex < (pHeap -> pData) + cIndex)
						swapAHNode((pHeap -> pData) + pIndex, (pHeap -> pData) + cIndex);
					else
						break;
					pIndex = cIndex;
				}
			}
			else
				swapAHNode((pHeap -> pData) + (pHeap -> currentCount), (pHeap -> pData) + 1);
		}
	}
	return (node);
}

void deleteAH(struct ArrayHeapType *pHeap)
{
	if (pHeap)
	{
		if (pHeap -> pData)
		{
			memset(pHeap -> pData, 0, ((pHeap -> maxCount) + 1) * sizeof(HeapNode));
			free(pHeap -> pData);
		}
		memset (pHeap, 0, sizeof(struct ArrayHeapType));
		free(pHeap);
	}
}
static void nBlank(int n)
{
	for (int i = 0; i < n; i++)
		printf("   ");
}

void displayAH(struct ArrayHeapType* pHeap)
{
	int	tmp, index, pInterval, cInterval, level = 0;

	if (pHeap && pHeap -> pData)
	{
		index = 1;
		tmp = pHeap -> currentCount;
		while (0 < tmp)
		{
			level++;
			tmp /= 2;
		}
		printf("\n[Displaying ArrayHeap]\n");
		for (int i = level; 0 < i; i--)
		{
			pInterval = 1 << (i - 1);
			nBlank(pInterval - 1);
			printf("%3d", (pHeap -> pData)[index++].data);
			while (i < level && index <= pHeap -> currentCount)
			{
				nBlank(cInterval);
				printf("%3d", (pHeap -> pData)[index++].data);
			}
			printf("\n");
			cInterval = pInterval;
		}
		printf("\n----------------DONE----------------\n");
	}
	else
		printf("\n[There's no valid data]\n");
}

