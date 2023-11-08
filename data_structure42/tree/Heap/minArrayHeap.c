#include "arrayheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ArrayHeapType	*createArrayHeap(int maxCount);
int insertMinHeapAH(ArrayMinHeap *pHeap, int value);
int removeMinHeapAH(ArrayMinHeap *pHeap, int value);
void deleteArrayHeap(struct ArrayHeapType *pHeap);
void displayArrayHeap(struct ArrayHeapType* pHeap);
