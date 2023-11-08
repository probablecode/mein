#include "sorting.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 데이터 교환할때 쓰세요
void swap(void **a, void **b)
{
		void *tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
}

// 처음에 포인터 배열 만들때 쓰시고 바깥함수에서 받아줘요
void    **makePArray(void *array, size_t size, size_t count)
{
    void    **pArray = NULL;
    if (count && size)
    {
        pArray = (void **)calloc(count, sizeof(void *));
        for (int i = 0; i < count; i++)
            pArray[i] = (void *)((unsigned char *)array + size * i);
    }
    return (pArray);
}

void    *complete(void *array, void **pArray, size_t size, size_t count)
{
    void    *retArray = NULL;
    if (array && pArray && size && count)
    {
        retArray = calloc(count, size);
        if (retArray)
        {
            for (int i = 0; i < count; i++)
                memcpy((unsigned char *)retArray + i * size, pArray[i], size);
            free(array);
            free(pArray);
        }
    }
    return (retArray);
}

void	*bubbleSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*))
{
	void    **pArray = makePArray(array, size, count);
	for (int i = count; 0 < i; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (cmp(pArray[j], pArray[j + 1]))
				swap(pArray + j, pArray + j + 1);
		}
	}
	return (complete(array, pArray, size, count));
}

void	*selectionSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*))
{
	void    **pArray = makePArray(array, size, count);
	int		min;

	for (int i = 0; i < count - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (cmp(pArray[min], pArray[j]))
				min = j;
		}
		swap(pArray + i, pArray + min);
	}
	return (complete(array, pArray, size, count));
}

void    *insertionSort(void *array, size_t size, size_t count, int (*cmp)(void *, void *))
{
    void    **tempArray = makePArray(array, size, count);

    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (cmp(tempArray[j], tempArray[i]))
            {
                void    *temp = tempArray[i];
                for (size_t z = i; z > j; z--)
                    swap(&tempArray[z], &tempArray[z - 1]);
                tempArray[j] = temp;
            }
        }
    }
    return (complete(array, tempArray, size, count));
}

void static subInsertionSort(void ***subArray, size_t count, int (*cmp)(void *, void *))
{
	int	n;
	void	*insert;
	for (int i = 1; i < count; i++)
	{
		insert = *(subArray[i]);
		n = i;
		while (0 < n && cmp(*(subArray[n - 1]), insert))
		{
			*(subArray[n]) = *(subArray[n - 1]);
			n--;
		}
		*(subArray[n]) = insert;
	}
}

void	*shellSort(void *array, size_t size, size_t count, int (*cmp)(void*, void*))
{
	void    **pArray = makePArray(array, size, count);
	void	***subPArray;
	int		offset = count / 2;
	int		subCount;
	
	while (offset)
	{
		subCount = count / offset;
		for (int i = 0; i + offset * (subCount - 1) < count; i++)
		{
			subPArray = (void ***)calloc(subCount, sizeof(void **));
			for (int j = 0; j < subCount; j++)
				subPArray[j] = pArray + (i + offset * j);
			subInsertionSort(subPArray, subCount, cmp);
			free(subPArray);
		}
		offset /= 2;
	}
	return (complete(array, pArray, size, count));
}

void countingSort(int *array, size_t count)
{
    int *countArray;
    int max, min, n, m;

    if (array && count)
    {
        max = array[0];
        min = array[0];
        for (int i = 0; i < count; i++)
        {
            if (max < array[i])
                max = array[i];
            else if (array[i] < min)
                min = array[i];
        }
        countArray = (int *)calloc(max - min + 1, sizeof(int));
        if (countArray)
        {
            for (int i = 0; i < count; i++)
                countArray[array[i] - min]++;
            n = 0; m = 0;
            while (m <= max - min)
            {
                for (int j = 0; j < countArray[m]; j++)
                    array[n++] = min + m;
                m++;
            }
            free(countArray);
        }
    }
}

static void	**merge(void *pArrayA[], void *pArrayB[], size_t countA, size_t countB, int (*cmp)(void *,void *))
{
	void	**pArray;
	int	i = 0, j = 0, k = 0;

	if (pArrayA && pArrayB && countA && countB)
	{
		pArray = (void **)calloc(countA + countB, sizeof(void *));
		if (pArray)
		{
			while (i < countA && j < countB)
			{
				if (cmp(pArrayA[i], pArrayB[j]))
					pArray[k++] = pArrayB[j++];
				else
					pArray[k++] = pArrayA[i++];
			}
			while (i < countA)
				pArray[k++] = pArrayA[i++];
			while (j < countB)
				pArray[k++] = pArrayB[j++];
			free(pArrayA);
			free(pArrayB);
		}
	}
	return (pArray);
}

static void	**subMergeSort(void *pArray[], size_t count, int (*cmp)(void *, void *))
{
	void	**pArrayA;
	void	**pArrayB;
	void	**retPArray = NULL;
	size_t	mid;

	if (1 < count)
	{
		mid = count / 2;
		pArrayA = (void **)calloc(mid, sizeof(void *));
		pArrayB = (void **)calloc(count - mid, sizeof(void *));
		if (pArrayA && pArrayB)
		{
			memcpy(pArrayA, pArray, mid * sizeof(void *));
			pArrayA = subMergeSort(pArrayA, mid, cmp);
			memcpy(pArrayB, pArray + mid, (count - mid) * sizeof(void *));
			pArrayB = subMergeSort(pArrayB, count - mid, cmp);
			free(pArray);
			retPArray = merge(pArrayA, pArrayB, mid, count - mid, cmp);
		}
		else
		{
			if (pArrayA)
				free(pArrayA);
			if (pArrayB)
				free(pArrayB);
		}
		return (retPArray);
	}
	else
		return (pArray);
}

void	*mergeSort(void *array, size_t size, size_t count, int (*cmp)(void *, void *))
{
	void	**pArray = makePArray(array, size, count);

	pArray = subMergeSort(pArray, count, cmp);
	return (complete(array, pArray, size, count));
}





static int	partition(void *pArray[], size_t count, int (*cmp)(void *, void *))
{
	void *pivot;
	int	left, right;

	left = 1;
	right = count - 1;
	pivot = pArray[0];
	while (1 < count)
	{
		while (left < count - 1 && cmp(pivot , pArray[left]))
			left++;
		while (0 < right && cmp(pArray[right], pivot))
			right--;
		if (left < right)
			swap(pArray + left, pArray + right);
		else
		{
			swap(pArray + 0, pArray + right);
			break;
		}
	}
	return (right);
}


static void	subQuickSort(void *pArray[], size_t count, int (*cmp)(void *, void *))
{
	int	pivot;

	if (1 < count)
	{
		pivot = partition(pArray, count, cmp);
		subQuickSort(pArray, pivot, cmp);
		subQuickSort(pArray + pivot + 1, count - pivot - 1, cmp);
	}
}

void	*quickSort(void *array, size_t size, size_t count, int (*cmp)(void *, void *))
{
	void	**pArray = makePArray(array, size, count);
	subQuickSort(pArray, count, cmp);
	return (complete(array, pArray, size, count));
}
