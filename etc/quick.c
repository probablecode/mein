#include <stdio.h>
int asc(int a, int b)
{
	return (a > b);
}

void swap(int *a, int *b)
{
	int tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int	partition(int *arr, int count, int (*cmp)(int , int))
{
	int	*pivot = arr + 0;
	int	left = 1;
	int right = count - 1;

	while (1 < count)
	{
		while (cmp(*pivot, arr[left]))
			left++;
		while (cmp(arr[right], *pivot))
			right--;
		if (left < right)
			swap(arr + left, arr + right);
		else
		{
			swap(pivot, arr + right);
			break;
		}
	}
	return (right);
}

void quicksort(int *arr, int count, int (*cmp)(int , int ))
{
	int pivot;
	if (arr && 1 < count)
	{
		pivot = partition(arr, count, cmp);
		quicksort(arr, pivot, cmp);
		quicksort(arr + pivot + 1, count - pivot - 1, cmp);
	}
}

int	main(void)
{
	int arr[19];
	for (int i = 0 ; i < 19; i++)
		arr[i] = (31 * i) % 19;
	for (int i = 0 ; i < 19; i++)
		printf("[%d] : %d\n", i, arr[i]);
/*	quicksort(arr, 17, asc);
	for (int i = 0 ; i < 17; i++)
		printf("[%d] : %d\n", i, arr[i]);
*/	return (0);
}
