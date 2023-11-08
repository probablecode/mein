#ifndef _SORTING_
#define _SORTING_
#include <stdlib.h>

void	*bubbleSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*selectionSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*insertionSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*shellSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*mergeSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*quickSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));
void	*radixSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*));

#endif

#ifndef _COMMON_SORTING_DEF_
#define _COMMON_SORTING_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif




// 1. bubble n^2
// 2. selection n^2
// 3. insertion n^2 
// 4. shell n^2 n^1.5 n*log n
// 5. heap
// 6. quick
// 7. merge
// 8. coefficient

