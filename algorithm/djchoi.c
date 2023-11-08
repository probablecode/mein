#include <stdio.h>
#include <stdlib.h>
#define INF 16384

void	path(int **map, int **mtx, int i, int j, int pre, const int M, const int N)
{
	pre++;
	if (pre < map[i][j])
	{
		map[i][j] = pre;
		if (0 < i && mtx[i - 1][j])
			path(map, mtx, i - 1, j, pre, M, N); 
		if (0 < j && mtx[i][j - 1])
			path(map, mtx, i, j - 1, pre, M, N); 
		if (i + 1 < M && mtx[i + 1][j])
			path(map, mtx, i + 1, j, pre, M, N); 
		if (j + 1 < N && mtx[i][j + 1])
			path(map, mtx, i, j + 1, pre, M, N); 
	}
}

int	main(void)
{
	int	M, N;
//	int	mtx[100][100];
//	int	map[100][100];
	int	**map, **mtx;
	scanf("%d %d", &M, &N);
	map = (int **)calloc(M, sizeof(int *));
	mtx = (int **)calloc(M, sizeof(int *));

	for (int i = 0; i < M; i++)
	{
		map[i] = (int *)calloc(N, sizeof(int));
		mtx[i] = (int *)calloc(N, sizeof(int));
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", mtx[i] + j);
			map[i][j] = INF;
		}
	}
	path(map, mtx, 0, 0, 0, M, N);
	printf("%d", map[M - 1][N - 1]);
	return (0);
}
