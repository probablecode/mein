#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

typedef struct DequeNodeType
{
    char data;
    struct DequeNodeType* pRLink;
    struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
    int currentElementCount;    // ÇöÀç ¿ø¼ÒÀÇ °³¼ö
    DequeNode* pFrontNode;      // Front ³ëµåÀÇ Æ÷ÀÎÅÍ
    DequeNode* pRearNode;       // Rear ³ëµåÀÇ Æ÷ÀÎÅÍ
} LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
//int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE        1
#define FALSE       0
#define ERROR		-1

#endif
