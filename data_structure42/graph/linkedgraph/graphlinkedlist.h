#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

typedef struct GraphVertexType
{
	int vertexID;		// ��� ID
	int weight;			// ����ġ.
	struct	GraphVertexType* pVLink;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	int graphType;
	ListNode *headerNode;		// ��� ���(Header Node)
} LinkedList;

LinkedList* createLinkedList(int gType);
int addLGVertex(LinkedList* pList, int VID);
int addLGEdge(LinkedList* pList, int fromVID, int toVID, int weight);
int removeLGVertex(LinkedList* pList, int VID);
int	removeLGEdge(LinkedList* pList, int fromVID, int toVID);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
