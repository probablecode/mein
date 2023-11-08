static int	partition(void *pArray[], size_t count, int (*cmp)(void *, void *))
{
	void	*pivot;
	int	Left, Right = -1;
	if (pArray && 0 < count)
	{
		Left = 1;
		Right = count - 1;
		pivot = pArray[0];
		while (Left < Right)
		{
			while (cmp(pivot, pArray[Left]))
				Left++;
			while (cmp(pArray[Right], pivot))
				Right--;
			if (Left < Right)
				swap(pArray + Left, pArray + Right);
			else
			{
				swap(pArray, pArray + Right);
				break;
			}
		}
	}
	return (Right);
}

static void	subQuickSort(void *pArray[], size_t count, int (*cmp)(void *, void *))
{
	int	pivot;

	if (1 < count)
	{
		pivot = partition(pArray, count, cmp);
		if (0 <= pivot)
		{
			subQuickSort(pArray, pivot);
			subQuickSort(pArray + pivot + 1, count - pivot - 1);
		}
	}
}


void	*quickSort(void *array, size_t size, size_t count, int (*cmp)(void *, void *))
{
	void	**pArray = makePArray(array, size, count);
	subQuickSort(pArray, count, cmp);
	return (complete(array, pArray, size, count));
}
