#include "arrayheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ArrayHeapType	*createArrayHeap(int maxCount);
int insertMaxHeapAH(ArrayMaxHeap *pHeap, int value);
int removeMaxHeapAH(ArrayMaxHeap *pHeap, int value);
void deleteArrayHeap(struct ArrayHeapType *pHeap);
void displayArrayHeap(struct ArrayHeapType* pHeap);
