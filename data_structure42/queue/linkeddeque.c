#include "linkeddeque.h"
#include <stdlib.h>
#include <string.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*new = NULL;
	new = malloc(sizeof(LinkedDeque));
	if (new)
	{
		new -> currentElementCount = 0;
		new -> pFrontNode = NULL;
		new -> pRearNode = NULL;
	}
	return (new);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;	
	int	ret = FALSE;
	
	if (pDeque)
	{
		new = (DequeNode *)malloc(sizeof(DequeNode));
		if (new)
		{
			*new = element;
			new -> pLLink = NULL;
			if (pDeque -> pFrontNode)
			{
				(pDeque -> pFrontNode) -> pLLink = new;
				new -> pRLink = pDeque -> pFrontNode;
				pDeque -> pFrontNode = new;
			}
			else
			{
				new -> pRLink = NULL;
				pDeque -> pFrontNode = new;
				pDeque -> pRearNode = new;
			}
			(pDeque -> currentElementCount)++;
			ret = TRUE;
		}
	}
	return (ret);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;	
	int	ret = FALSE;
	
	if (pDeque)
	{
		new = (DequeNode *)malloc(sizeof(DequeNode));
		if (new)
		{
			*new = element;
			new -> pRLink = NULL;
			if (pDeque -> pRearNode)
			{
				(pDeque -> pRearNode) -> pRLink = new;
				new -> pLLink = pDeque -> pRearNode;
				pDeque -> pRearNode = new;
			}
			else
			{
				new -> pLLink = NULL;
				pDeque -> pFrontNode = new;
				pDeque -> pRearNode = new;
			}
			(pDeque -> currentElementCount)++;
			ret = TRUE;
		}
	}
	return (ret);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*node;

	node = peekFrontLD(pDeque);
	if (node)
	{
		pDeque -> pFrontNode = node -> pRLink;
		if (pDeque -> pFrontNode)
			(pDeque -> pFrontNode) -> pLLink = NULL;
		else
			pDeque -> pRearNode = NULL;
		node -> pRLink = NULL;
		(pDeque -> currentElementCount)--;
	}
	return (node);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*node;

	node = peekRearLD(pDeque);
	if (node)
	{
		pDeque -> pRearNode = node -> pLLink;
		if (pDeque -> pRearNode)
			(pDeque -> pRearNode) -> pRLink = NULL;
		else
			pDeque -> pFrontNode = NULL;
		node -> pLLink = NULL;
		(pDeque -> currentElementCount)--;
	}
	return (node);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*node = NULL;

	if (!isLinkedDequeEmpty(pDeque))
		node = pDeque -> pFrontNode;
	return (node);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	DequeNode	*node = NULL;

	if (!isLinkedDequeEmpty(pDeque))
		node = pDeque -> pRearNode;
	return (node);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*node;

	while (!isLinkedDequeEmpty(pDeque))
	{
		node = deleteFrontLD(pDeque);
		memset(node, 0, sizeof(DequeNode));
		free (node);
	}
	if (pDeque)
	{
		memset(pDeque, 0, sizeof(LinkedDeque));
		free(pDeque);
	}
}

/*
int isLinkedDequeFull(LinkedDeque* pDeque)
{
}
*/
int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	int	ret = ERROR;
	
	if (pDeque)
		ret = (pDeque -> currentElementCount <= 0);
	return (ret);
}
