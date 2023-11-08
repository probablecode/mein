#include "simlinkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int	arrivalTime, processTime, systemTime = 0, pServiceUserCount = 0, pTotalWaitTime = 0;
	LinkedQueueNode	*pServiceNode = NULL;
	LinkedQueue	*pArrivalQueue = createLinkedQueue();
	LinkedQueue	*pWaitQueue = createLinkedQueue();

	printf("도착시간과 작업시간을 작업의 갯수만큼 기입해주세요\n 모든 기입이 끝났으면 0 0을 입력해주세요\n");
	scanf("%d %d", &arrivalTime, &processTime);
	while (arrivalTime || processTime)
	{
		insertCustomer(arrivalTime, processTime, pArrivalQueue);
		scanf("%d %d", &arrivalTime, &processTime);
	}
	
	while (pServiceNode || isLinkedQueueEmpty(pWaitQueue) == FALSE || isLinkedQueueEmpty(pArrivalQueue) == FALSE)
	{
		processArrival(systemTime, pArrivalQueue, pWaitQueue); // 한 순간에 하나씩만 온다고 하자..
		if (!pServiceNode)
		{
			pServiceNode = processServiceNodeStart(systemTime, pWaitQueue);
			if (pServiceNode)
				printSimCustomer(systemTime, pServiceNode -> data);
		}
		processServiceNodeEnd(systemTime, pServiceNode, &pServiceUserCount, &pTotalWaitTime);
		if (pServiceNode -> data.status == end)
		{
			printSimCustomer(systemTime, pServiceNode -> data);
			free(pServiceNode);
			pServiceNode = processServiceNodeStart(systemTime, pWaitQueue);
			if (pServiceNode)
				printSimCustomer(systemTime, pServiceNode -> data);
		}
		printWaitQueueStatus(systemTime, pWaitQueue);
		systemTime++;
	}
	printReport(pWaitQueue, pServiceUserCount, pTotalWaitTime);
	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);
	return (0);
}
#include "simlinkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
LinkedQueue* createLinkedQueue()
{
	LinkedQueue	*new = NULL;
	
	new = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (new)
	{
		new -> currentElementCount = 0;
		new -> pFrontNode = NULL;
		new -> pRearNode = NULL;
	}
	return (new);
}

int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element)
{
	LinkedQueueNode	*node = NULL;
	int ret = FALSE;

	if (pQueue)
	{
		node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
		if (node)
		{
			*node = element;
			node -> pLink = NULL;
			if (isLinkedQueueEmpty(pQueue))
				pQueue -> pFrontNode = node;
			else
				(pQueue -> pRearNode) -> pLink = node;
			pQueue -> pRearNode = node;
			(pQueue -> currentElementCount)++;
			ret = TRUE;
		}
	}
	return	(ret);
}

LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*toDelete = peekLQ(pQueue);
	
	if (toDelete)
	{
		pQueue -> pFrontNode = toDelete -> pLink;
		if (!(pQueue -> pFrontNode))
			pQueue -> pRearNode = NULL;
		toDelete -> pLink = NULL;
		(pQueue -> currentElementCount)--;
	}
	return (toDelete);
}

LinkedQueueNode *peekLQ(LinkedQueue* pQueue)
{
	LinkedQueueNode	*peek = NULL;

	if (!isLinkedQueueEmpty(pQueue))
		peek = pQueue -> pFrontNode;
	return (peek);
}
int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	int	ret = ERROR;

	if (pQueue)
		ret = (pQueue -> currentElementCount <= 0);
	return (ret);
}
void deleteLinkedQueue(LinkedQueue* pQueue)
{
	LinkedQueueNode	*node;

	if (pQueue)
	{
		node = dequeueLQ(pQueue);		
		while (node)
		{
			memset (node, 0, sizeof(LinkedQueueNode));
			free (node);
			node = dequeueLQ(pQueue);
		}
		memset (pQueue, 0, sizeof(LinkedQueue));
		free (pQueue);
	}
}
#ifndef _SIM_LINKED_QUEUE_
#define _SIM_LINKED_QUEUE_

typedef enum SimStatusType	{
	arrival,
	start, // run, stoped(in preempetive policy)
	end
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
}	SimCustomer;

typedef struct LinkedQueueNodeType
{
	SimCustomer	data;
    struct LinkedQueueNodeType* pLink;
} LinkedQueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;
    LinkedQueueNode*	pFrontNode;
	LinkedQueueNode*	pRearNode;
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element);
LinkedQueueNode *dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode *peekLQ(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);



void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);
LinkedQueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
LinkedQueueNode* processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode,int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);




#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE        1
#define FALSE       0
#define ERROR		-1

#endif
#ifndef _SIM_DEF_
#define _SIM_DEF_
#endif
#include "simlinkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
at first, FCFS, non-preempetive

priority queue? / no.. at first, inputs should be sequential
 */

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue) //pArrivalQueue
{
	LinkedQueueNode	element;
	
	(element.data).arrivalTime = arrivalTime;
	(element.data).serviceTime = processTime;
	enqueueLQ(pQueue, element);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*node = peekLQ(pArrivalQueue);
	LinkedQueueNode	element;


	if (node && (node -> data).arrivalTime == currentTime)
	{
		node = dequeueLQ(pArrivalQueue);
		(node -> data).status = arrival;
		element = *node;
		enqueueLQ(pWaitQueue, element);
		memset(node, 0, sizeof(LinkedQueueNode));
		free (node);
	}
}

LinkedQueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*node = dequeueLQ(pWaitQueue);
	
	if (node)
	{
		(node -> data).status = start;
		(node -> data).startTime = currentTime;
	}
	return (node);
}

LinkedQueueNode* processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode,int *pServiceUserCount, int *pTotalWaitTime)
{
	SimCustomer	*custom;

	if (pServiceNode)
	{
		custom = &(pServiceNode -> data);
		if (custom -> startTime + custom -> serviceTime == currentTime)
		{
			custom -> status = end;
			custom -> endTime = currentTime;
			(*pServiceUserCount)++;
			(*pTotalWaitTime) += ((custom -> startTime) - (custom -> arrivalTime));
		}
	}
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("\n------------------------------------\n");
	printf("시스템 시간 : [%d초]\n\n", currentTime);
	printf("도착 시간 : [%d초]\n", customer.arrivalTime);
	printf("작업 시간 : [%d초]\n", customer.serviceTime);
	printf("시작 시간 : [%d초]\n", customer.startTime);
	if (customer.status == end)
	{
		printf("완료 시간 : [%d초]\n", customer.endTime);
		printf(" 이상 작업 완료 보고\n");
	}
	else if (customer.status == start)
		printf(" 이상 작업 시작 보고\n");
	printf("--------------------------------------\n");
}	

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	LinkedQueueNode	*ptr = peekLQ(pWaitQueue);
	printf("\n====================================\n");
	printf("시스템 시간 : [%d초] | 대기 큐 상태 보고\n",currentTime);
	printf("현재 대기 중인 작업 수 : %d\n", pWaitQueue -> currentElementCount);
	if (ptr)
		printf("도착 시간 : ");
	while (ptr)
	{
		printf(" |%d초| ", (ptr -> data).arrivalTime);
		ptr = ptr -> pLink;
	}
	printf("\n====================================\n");
}
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("프린트리포트~ \n serviceUserCount : %d\n totalWaitTime : %d", serviceUserCount, totalWaitTime);
}
