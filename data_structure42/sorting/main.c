#include "sorting.h"
#include <stdio.h>
#define COUNT 97
typedef struct s_element
{
	int data;
} t_element;


int	ascendingElementInt(void *a, void *b)
{
	t_element *A = a;
	t_element *B = b;
	if (A -> data > B -> data)
		return (1);
	else
		return (0);
}

int main(void)
{
	t_element	*arr = calloc(COUNT, sizeof(t_element));
	for (int i = 0; i < COUNT; i ++)
		arr[i].data = (19 * i) % COUNT; // 0, 3, 6, 9, 2, 5, 8, 1, 4, 7 의 배열 생성
	for (int i = 0; i < 10; i++)
		printf("[%d] : %4d", i, arr[i].data);
	printf("\n=============================\n");
//	arr = (t_element *)shellSort(arr, sizeof(t_element), 10, ascendingElementInt);
//	arr = (t_element *)mergeSort(arr, sizeof(t_element), 10, ascendingElementInt);
	arr = (t_element *)quickSort(arr, sizeof(t_element), COUNT, ascendingElementInt);
	for (int i = 0; i < COUNT; i++)
		printf("[%d] : %4d", i, arr[i].data);
	free(arr);
	return (0);
}
