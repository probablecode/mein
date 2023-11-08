#include "sorting.h"
#include <stdio.h>
void countingSort(int *array, size_t count);
int main(void)
{
	int	*arr = calloc(100, sizeof(int));
	for (int i = 0; i < 100; i ++)
		arr[i] = (i * 3) % 20; // 0, 3, 6, 9, 2, 5, 8, 1, 4, 7 의 배열 생성

	countingSort(arr, 100);
	for (int i = 0; i < 100; i++)
		printf("[%d] : %d\n", i, arr[i]);
	free(arr);
	return (0);
}
