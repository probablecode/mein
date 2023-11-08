#include <stdio.h>
#include <stdlib.h>
typedef struct s_plst
{
	int		prime;
	struct s_plst	*pre;
	struct s_plst	*next;
}
t_plst;

t_plst  *ft_lstnew(int content)
{
        t_plst  *ret;

        ret = (t_plst *)malloc(sizeof (t_plst));
        if (ret)
        {
                ret -> prime = content;
				ret -> pre = ret;
                ret -> next = ret;
        }
        return (ret);
}
void    ft_lstadd(t_plst *lst, t_plst *new)
{
        t_plst  *last;

		last = lst -> pre;
		last -> next = new;
		lst -> pre = new;
		new -> pre = last;
		new -> next = lst;
}

int	nextprime(t_plst *primes, int number)
{
	t_plst	*ptr;
	int	num, last;

	num = 0;
	last = (primes -> pre) -> prime;
	while (num * num < number && num != last)
	{
		number += 2;
		ptr = primes;
		while (num * num < number && num != last)
		{
			num = ptr -> prime;
			if (!(number % (num)))
				break;
			ptr = ptr -> next;
		}
	}
	return (number);
}
void    ft_lstfree(t_plst *lst)
{
	t_plst	*start = lst;
	t_plst	*tmp;

	tmp = lst;
	lst = lst -> next;
	free (tmp);
	while (lst != start)
	{
		tmp = lst;
		lst = lst -> next;
		free (tmp);
	}
}

t_plst	*prime_maker(t_plst *primes, int range)
{
	int number;

	number = nextprime(primes, (primes -> pre) -> prime);
	while (number < range)
	{
		ft_lstadd(primes, ft_lstnew(number));
		number = nextprime(primes, number);
	}
	return (primes -> pre);
}

int	main(void)
{
	int	even;
	int n;
	t_plst	*p1, *p2;
	t_plst	*primes, *last;

	primes = ft_lstnew(3);
	last = ft_lstnew(5);
	primes -> pre = last;	primes -> next = last;
	last -> pre = primes;	last -> next = primes;

	scanf("%d", &even);
	if (even <= 1000000)
		last = prime_maker(primes, even);
	while (even)
	{
		p1 = primes;
		while (p1 != last)
		{
			n = even - p1 -> prime;
			p2 = last;
			while (p2 != p1)
			{
				if (n == p2 -> prime)
				{
					printf("%d = %d + %d\n", even, p1 -> prime, n);
					p1 = last -> pre;
					p2 = p1-> next;
				}
				p2 = p2 -> pre;
			}
			p1 = p1 -> next;
		}
		scanf("%d", &even);
		if (even <= 1000000 && last -> prime < even)
			last = prime_maker(primes, even);
	}
	ft_lstfree(primes);
	return (0);
}
