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
