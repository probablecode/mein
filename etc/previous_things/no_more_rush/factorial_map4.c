#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define END 1
#define NO_SOLUTION 0

#define COL_UP 0
#define COL_DOWN 1
#define ROW_LEFT 2
#define ROW_RIGHT 3

#define VALID_INPUT 1
#define INVALID_INPUT 0

#define TRUE 1
#define FALSE 0
int	input_margin(char *input, int ***inputs, int *n)
{
	int		number;
	char	*ptr;
	int		i;
	int		j;

	number = 0;
	ptr = input;
	while (*ptr)
	{
		if ('0' <= (*ptr) && (*ptr) <= '9')
			number++;
		ptr++;
	}
	if (number % 4 != 0)
		return INVALID_INPUT;
	(*n) = number / 4;
	(*inputs) = (int **)malloc(4 * sizeof(int *));
	ptr = input;
	i = 0;
	while (i < 4)
	{
		(*inputs)[i] = (int *)malloc((*n) * sizeof(int));
		j = 0;
		while (j < (*n) && *ptr)
		{
			if('0' <= (*ptr) && (*ptr) <= '9')
			{
				(*inputs)[i][j] = (*ptr) - '0';
				j++;
			}
			ptr++;
		}
		i++;
	}
	return VALID_INPUT;
}

void	print_matrix(int **matrix, const int n)
{
	int	i;
	int	j;
	char	number;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			number = '0' + matrix[i][j];
			write(1, &number, 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
		write(1, "\n", 1);
		write(1, "\n", 1);
}

int	one_row_check(int **matrix, int **inputs, int i, const int n)
{
	int	j;
	int	cnt[2];
	int	max[2];

	j = 0;
	max[0] = matrix[i][0];
	max[1] = matrix[i][n - 1];
	cnt[0] = 1;
	cnt[1] = 1;
	while (++j < n)
	{
		if (max[0] < matrix[i][j])
		{
			cnt[0]++;
			max[0] = matrix[i][j];
		}
		if (max[1] < matrix[i][n - j - 1])
		{
			cnt[1]++;
			max[1] = matrix[i][n - j - 1];
		}
	}
	if (inputs[ROW_LEFT][i] != cnt[0] || inputs[ROW_RIGHT][i] != cnt[1])
		return (FALSE);
	return (TRUE);
}

int	row_check(int **matrix, int **inputs, const int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!one_row_check(matrix, inputs, i, n))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	one_col_check(int **matrix, int **inputs, int i, const int n)
{
	int	j;
	int	cnt[2];
	int	max[2];

	j = 0;
	max[0] = matrix[0][i];
	max[1] = matrix[n - 1][i];
	cnt[0] = 1;
	cnt[1] = 1;
	while (++j < n)
	{
		if (max[0] < matrix[j][i])
		{
			cnt[0]++;
			max[0] = matrix[j][i];
		}
		if (max[1] < matrix[n - j - 1][i])
		{
			cnt[1]++;
			max[1] = matrix[n - j - 1][i];
		}
	}
	if (inputs[COL_UP][i] != cnt[0] || inputs[COL_DOWN][i] != cnt[1])
		return (FALSE);
	return (TRUE);
}

int	col_check(int **matrix, int **inputs, const int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!one_col_check(matrix, inputs, i, n))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
int	answer_check(int **matrix, int **inputs, const int n)
{
	int i;
	int ret;

	print_matrix(matrix, n);
	write(1, "\n\n",2);
	ret = (row_check(matrix, inputs, n) && col_check(matrix, inputs, n));
	if (ret==TRUE)
	{	
		write(1,"\n\n축하드립니다! 이겁니다!\n",36);
		print_matrix(matrix,n);
	}
	i = 0;
	while(i < n)
	{	
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ret;
}
void	copy_matrix(int **dest_Mtx, int **src_Mtx, const int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			dest_Mtx[i][j] = src_Mtx[i][j];
			j++;
		}
		i++;
	}
}
int	factorial (int n)
{
	int ret;

	ret = 1;
	while(0 < n)
	{
		ret *= n;
		n--;
	}
	return ret;
}
void	numbers_init(int *numbers, const int n)
{
	int i;
	
	i=0;
	while(i < n)
	{
		numbers[i] = i;
		i++;
	}
}
int	pick_pulling_array(int *array, int index, const int len)
{
	int ret;

	ret = array[index];
	while (index < len - 1)
	{
		array[index] = array[index + 1];
		index++;
	}
	return ret;
}
int	*factorial_map(int i, const int n)
{
	int	*numbers;
	int *array;
	int index;
	int dividor;

	array = (int*)malloc(n * sizeof(int));
	numbers = (int*)malloc(n * sizeof(int));
	numbers_init(numbers, n);
	dividor = n;

	while (0 < dividor)
	{
		index = i % dividor;
		array[dividor-1] = pick_pulling_array(numbers,index,n);
		i /= dividor;
		dividor--;
	}
	free(numbers);
	return array;
}
int **per_mtx_maker(int *array, const int n)
{
	int **per_Mtx;
	int i;
	int j;

	per_Mtx = (int **)malloc(n * sizeof(int *));
	i = 0;
	while (i < n)
	{
		per_Mtx[i] = (int *)malloc(n * sizeof(int));
		j = 0;
		while (j < n)
		{
			if( j == array[i])
				per_Mtx[i][j] = 1;
			else
				per_Mtx[i][j] = 0;
			j++;
		}
		i++;
	}
	free (array);
	return per_Mtx;
}

/*This function exceed 25 line, ignore that generously*/
int **matrix_multiplication(int **front_Mtx, int **rear_Mtx, const int n)
{
	int **ret_Mtx;
	int i;
	int j;
	int k;

	ret_Mtx = (int **)malloc(n * sizeof(int *));
	i = 0;
	while (i < n)
	{
		ret_Mtx[i] = (int *)malloc(n * sizeof(int));
		j = 0;
		while (j < n)
		{
			ret_Mtx[i][j] = 0;
			k = 0;
			while(k < n)
			{
				ret_Mtx[i][j] += front_Mtx[i][k] * rear_Mtx[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	i=0;
	while(i < n)
	{
		free(front_Mtx[i]);
		free(rear_Mtx[i]);
		i++;
	}
	free(front_Mtx);
	free(rear_Mtx);
	return ret_Mtx;
}
int **rush_matrix(int **front_per_Mtx, int **std_Mtx, int **rear_per_Mtx, const int n)
{
	int **ret_Mtx;
	
	print_matrix(front_per_Mtx,n);
	print_matrix(std_Mtx,n);
	print_matrix(rear_per_Mtx,n);

	ret_Mtx = matrix_multiplication(front_per_Mtx, std_Mtx, n);
	ret_Mtx = matrix_multiplication(ret_Mtx, rear_per_Mtx, n);
	return ret_Mtx;
}
int rush_01(int **inputs, const int n)
{
	int** std_matrix;
	int** center_matrix;
	int** check_mtx;
	int fct;
	int i;
	int j;
	int k;
	
	fct = factorial(n);
	std_matrix = (int **)malloc(n * sizeof(int *));
	center_matrix = (int **)malloc(n * sizeof(int *));
	i = 0;
	while(i < n)
	{
		std_matrix[i] = (int *)malloc(n * sizeof(int));
		center_matrix[i] = (int *)malloc(n * sizeof(int));
		i++;
	}
		
		std_matrix[0][0] = 1;
         std_matrix[0][1] = 2;
         std_matrix[0][2] = 3;
         std_matrix[0][3] = 4;
		 std_matrix[1][0] = 2;
         std_matrix[1][1] = 4;   
		 std_matrix[1][2] = 1;
         std_matrix[1][3] = 3;
         std_matrix[2][0] = 3;
         std_matrix[2][1] = 1;
         std_matrix[2][2] = 4;     
		 std_matrix[2][3] = 2;
         std_matrix[3][0] = 4;
         std_matrix[3][1] = 3;
         std_matrix[3][2] = 2;
		 std_matrix[3][3] = 1;
//	copy_matrix(center_matrix,std_matrix,n);
	i = 0;
	while (i < fct)
	{
		j = 0;
		while (j < fct)
		{
			center_matrix = (int **)malloc(n * sizeof(int *));
			k = 0;
			while(k < n)
			{
				center_matrix[k] = (int *)malloc(n * sizeof(int));
				k++;
			}
			copy_matrix(center_matrix,std_matrix,n);
			printf("%d 번째 시도에용\n", fct * i + j + 1);
			check_mtx = rush_matrix(per_mtx_maker(factorial_map(i,n),n),center_matrix,per_mtx_maker(factorial_map(j,n),n), n);
			if(answer_check(check_mtx,inputs, n))
			{
				k = 0;
				while(k < n)
				{
					free(std_matrix[k]);
					k++;
				}
				free(std_matrix);
				return END;
			}
/*			{
				print_matrix(check_mtx,n);
				i = 0;
				while(i < n)
				{
					free(check_mtx[i]);
					free(std_matrix[i]);
					i++;
				}
				free(std_matrix);
				free(check_mtx);
		
			}
*/			j++;
		}
		i++;
	}

/*	i = 0;
	while (i < n)
	{
		free(check_mtx[i]);
		free(std_matrix[i]);
		i++;
	}
	free(std_matrix);
	free(check_mtx);
*/	
	k = 0;
	while(k < n)
	{
		free(std_matrix[k]);
		k++;
	}
	free(std_matrix);
	return NO_SOLUTION;	
}


int	main(int argc, char *argv[])
{
	int **inputs;
	int n;

	if (argc == 2)
	{
		if(input_margin(argv[1],&inputs, &n) == VALID_INPUT)
		{
			if(rush_01(inputs, n) == END)
				write(1,"\n찾았다!\n",13);
			else
			{
				write(1,"\n못찾겠다 꾀꼬리\n",24);
				printf("n은 %d였고 fct는 %d 였다\n인풋은 ",n,factorial(n));
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<n;j++)
						printf("%d ",inputs[i][j]);
				}
			}
		}
		else
			printf("부적절한 입력이다\n");
		free(inputs);
	}
	else
		write(1,"Error\n",6);
	return (0);
}

