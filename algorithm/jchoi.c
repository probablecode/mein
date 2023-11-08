#include <stdio.h>
void	cptr_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	T, len, slen, order, i;
	char ch;
	char	*head, *tail;
	char command[100001];
	char input[200002];


	scanf("%d", &T);
	for (int k = 0; k < T; k++)
	{
		scanf("%s", command);
		scanf("%d", &len);
		scanf("%s", input);
		
		head = input + 1;
		if (len)
			tail = head + (len - 1) * 2;
		else
			tail = head;
		i = 0;
		ch = command[i];
		while (ch)
		{
			if (ch == 'R')
				cptr_swap(&head, &tail);
			else if (ch == 'D')
			{
				len--;
				if (len < 0)
					break;

				if (tail < head)
					head -= 2;
				else if (head < tail)
					head += 2;
			}
			ch = command[++i];
		}
		if (0 <= len)
		{
			putchar('[');
			order = (head < tail) - (tail < head);
			slen = len * 2 - 1;
			for (int k = 0; k < slen; k++)
			{
				putchar(*head); 
				head += order;
			}
			putchar(']');
		}
		else
			printf("error");
		printf("\n");
	}
	return (0);
}
