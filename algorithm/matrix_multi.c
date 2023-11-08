#include <stdio.h>
#include <stdlib.h>
int	**matrix_init(const int m, const int n)
{

	int	**mtx;

	mtx = (int **)calloc(m, sizeof(int *));
	for (int i = 0; i < m; i++)
		mtx[i] = (int *)calloc(n, sizeof(int));
	return (mtx);
}

void	matrix_input(int **mtx, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", mtx[i] + j);
	}
}

void	matrix_copy(int **dst_mtx, int **src_mtx, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			dst_mtx[i][j] = src_mtx[i][j];
	}
}

void	matrix_free(int **mtx, const int m)
{
	for (int i = 0; i < m; i++)
		free(mtx[i]);
	free(mtx);
}

void matrix_power(int **mtx, const int m, int power)
{
	int	**matrix, **result;
	int element;
	matrix = matrix_init(m, m);
	result = matrix_init(m, m);
	matrix_copy(matrix, mtx, m, m);
	for (int p = 1; p < power; p++)
	{
		printf("\n\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				element = 0;
				for (int k = 0; k < m; k++)
					element += matrix[i][k] * mtx[k][j];
				result[i][j] = element;
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}
		matrix_copy(matrix, result, m, m);
	}
	matrix_free(matrix, m);
	matrix_free(result, m);
}
int	main(void)
{
	int	M, power;
	int	**matrix;

	scanf("%d", &M);
	matrix = matrix_init(M, M);
	matrix_input(matrix, M, M);
	scanf("%d", &power);
	matrix_power(matrix, M, power);
	matrix_free(matrix, M);
	return (0);
}
