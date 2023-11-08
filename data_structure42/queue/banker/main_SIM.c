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
