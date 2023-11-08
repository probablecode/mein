#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	int	N, M, i, j;
	int count;
	int button[10];
	int avail, offset, num, all = 1;
	int *digits;
	unsigned int gap;

	scanf("%d %d",&N, &M);
	i = 0;
	while (i < M)
		scanf("%d", digits + (i++));
	offset = (N - 100) * ((100 < N) - (N < 100));
	if (M == 10)
	{
		printf("%d",offset);
		return (0);
	}
	
	avail = 10 - M;
	digits = (int *)calloc(avail, sizeof(int)); 
	for (int n = 0; n < 10; n++)
	{
		i = 0; j = 0;
		while (j < M && i != button[j])
			j++;
		if (j == M)
			digits[i++] = n;
	}
	
	for (int k = 0; k < avail; k++)
		all *= avail;
	
	count = 0; i = N;
	while (0 < i)
	{
		i /= 10;
		count++;
	}

	gap = 1000000;
	for (int k = 0; k < all; k++)
	{	
		num = 0;
		i = 1; j = k;
		for (int l = 0; l < count ; l++)
		{
			num += i * digits[j % avail];
			j /= avail;
			i * 10;
		}
		if (N < num)
			break;
	}
	if (num < N)
		num;
	if 

	{
		if ()
			avail[i] = digits[j];
		i++;
	}
	return (0);
}
