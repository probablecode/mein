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
