#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)// 예외처리 전혀 없는 버전
{
	ArrayGraph	*new = NULL;

	if (0 < maxVertexCount)
	{
		new = (ArrayGraph *)malloc(sizeof(ArrayGraph));
		new -> ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
		for (int i = 0; i < maxVertexCount; i++)
			(new -> ppAdjEdge)[i] = (int *)calloc(maxVertexCount, sizeof(int));
		new -> pVertex = (int *)calloc(maxVertexCount, sizeof(int));
		new -> maxVertexCount = maxVertexCount;
		new -> currentVertexCount = 0;
		new -> graphType = GRAPH_UNDIRECTED;
	}
	return (new);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*new;	

	new = createArrayGraph(maxVertexCount);
	if (new)
		new -> graphType = GRAPH_DIRECTED;
	return (new);
}
void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph)
	{
		if (pGraph -> pVertex)
		{
			memset(pGraph -> pVertex, 0, (pGraph -> maxVertexCount) * sizeof(int));	
			free(pGraph -> pVertex);
		}
		if (pGraph -> ppAdjEdge)
		{
			for (int i = 0; i < pGraph -> maxVertexCount; i++)
			{
				memset((pGraph -> ppAdjEdge)[i], 0, (pGraph -> maxVertexCount) * sizeof(int));
				free((pGraph -> ppAdjEdge)[i]);
			}
			memset((pGraph -> ppAdjEdge), 0, (pGraph -> maxVertexCount) * sizeof(int *));
			free((pGraph -> ppAdjEdge));
		}
		memset(pGraph, 0, sizeof(ArrayGraph));
		free(pGraph);
	}
}

int isEmptyAG(ArrayGraph* pGraph);
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int ret = FALSE;

	if (checkVertexValid(pGraph, vertexID))
	{
		(pGraph -> pVertex)[vertexID] = USED;
		ret = TRUE;
	}
	return (ret);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);
{
	int ret = FALSE;

	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		if (pGraph -> pVertex [fromVertexID] == USED && pGraph -> pVertex [fromVertexID] == USED )
		{	
			pGraph -> ppAdjEdge[fromVertex][toVertexID] = weight;
			if (pGraph -> graphType == GRAPH_UNDIRECTED)
				pGraph -> ppAdjEdge[toVertexID][fromVertex] = weight;
			ret = TRUE;
		}
	}
	return (ret);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED));
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	int	ret = FALSE;

	if (pGraph)
	{
		if (0 <= vertexID && vertexID < pGraph -> maxVertexCount)
			ret = TRUE;
	}
	return (ret);
}


int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int	ret = FAIL;

	if (checkVertexValid(pGraph, vertexID))
	{
		if (pGraph -> pVertex [vertexID] == USED)
		{
			for (int i = 0; i < pGraph -> maxVertexCount; i++)
			{ // removeEdgeAG를 호출하는게 계층적이겠지만, 오버헤드가 너무 크다
				(pGraph -> ppAdjEdge)[i][vertexID] = NOT_USED;
				(pGraph -> ppAdjEdge)[vertexID][i] = NOT_USED;
			}
			pGraph -> pVertex [vertexID] == NOT_USED;
			ret = SUCCESS;		
		}
	}
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	int ret = FAIL;

	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph -> ppAdjEdge[fromVertex][toVertexID] = NOT_USED;
		if (pGraph -> graphType == GRAPH_UNDIRECTED)
			pGraph -> ppAdjEdge[toVertexID][fromVertex] = NOT_USED;
		ret = SUCCESS;
	}
	return (ret);
}

void displayArrayGraph(ArrayGraph* pGraph);




#define USED				1
#define NOT_USED			0
#define SUCCESS				1
#define FAIL				0
#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
