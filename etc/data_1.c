/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:50:40 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/17 21:50:44 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void	list(char **names)
{
	for (int i = 0; i < 10; i += 2)
		printf("{%s, %s} ", names[i], names[i + 1]);
}

void	swap(char **a, char **b)
{
	char	*tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char *argv[])
{
	char*	names[10] = {"dongchoi", "doyokim", "ean", "hejang"
	, "hyejung", "jaebae", "jaemjung", "jaewchoi", "jchoi", "jislim"};
	char*	shuffled[10];
	int		random, index, c;
	int		r1[5];
	int		r2[10];
	int	table[10][10] = {
		{0,1,2,3,4,5,6,7,8,9},
		{1,0,3,4,5,6,7,8,9,2},
		{2,3,0,5,6,7,8,9,1,4},
		{3,4,5,0,7,8,9,1,2,6},
		{4,5,6,7,0,9,1,2,3,8},
		{5,6,7,8,9,0,2,3,4,1},
		{6,7,8,9,1,2,0,4,5,3},
		{7,8,9,1,2,3,4,0,6,5},
		{8,9,1,2,3,4,5,6,0,7},
		{9,2,4,6,8,1,3,5,7,0}
	};

	if (argc == 2)
	{
		printf("=======================================================================\n\t\t\t unique mate-maker \n=======================================================================\n\n");	srand(time(NULL));
	printf("<< shuffle between mate >>\nrandom number : %d\n", random = rand() % 32);
	for (int i = 0; i < 5; i++)
	{
		c = random % 2;
		printf("%c\t\t", 'T' * c + 'F' * (!c));
		fflush(stdout);
		usleep(500000);
		r1[i] = c;
		random /= 2;
	}
	printf("\n"); list(names); index = 0;
	for (int i = 0; i < 10; i += 2)
	{
		if (r1[index++])
		{	
			swap(names + i, names + i + 1);
			fflush(stdout);usleep(500000);system("printf \r");
			list(names);
		}
	}	fflush(stdout);usleep(250000);
	srand(time(NULL));
	printf("\n\n<< shuffle among each pairs >>\nrandom number : %d\n", random = rand() % 1024);
	for (int i = 0; i < 10; i++)
	{
		c = random % 2;
		printf("%c\t", 'T' * c + 'F' * (!c));
		fflush(stdout);
		usleep(250000);
		r2[i] = c;
		random /= 2;
		
	}printf("\n");list(names); index = 0;
	for (int n = 8; 0 < n; n -= 2)
	{
		for (int i = 0; i < n; i += 2)
		{
			if (r2[index++])
			{
				fflush(stdout);usleep(500000);system("printf \r");
				swap(names + i, names + n);
				swap(names + i + 1, names + n + 1);
				list(names);
			}
		}
	}


		printf("\n\n================================================================================");
		printf("\n\t\t자료구조 공부반 1 반 주차별 짝 배정");
		printf("\n================================================================================\n");
		fflush(stdout);usleep(250000);
		printf("\n1 주차\n");list(names);
		for (int i = 0; i < 5; i++)
		{
			shuffled[i] = names[i * 2];
			shuffled[9 - i] = names[i * 2 + 1];
		}
		for (int i = 2; i <= 8; i++)
		{
			c = argv[1][i - 2] - '0';
			printf("\n\n%d 주차 (case : %c)\n", i, c + 'a' - 1);
			fflush(stdout);usleep(250000);
			for (int l = 0; l < 9; l++)
			{
				for (int m = l + 1; m < 10; m++)
				{
					if (table[l][m] == c)
					{
						fflush(stdout);usleep(100000);
						printf("{%s, %s} ", shuffled[l], shuffled[m]);
					}
				}
			};fflush(stdout);usleep(250000);
		}
	}
	return (0);
}
