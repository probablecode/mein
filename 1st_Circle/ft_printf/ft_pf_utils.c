#include "libft.h"
int	ft_pf_putnbr_base(int n, const char *base)
{
	char			nbr[32];
	const int		unit = (int)ft_strlen(base);
	int				sign;
	int				ret;
	unsigned int	i;

	i = 0;
	sign = (0 < n) - (n < 0);
	if (sign <= 0)
		nbr[i++] = (sign < 0) * '-' + (sign == 0) * '0';
	while (n != 0)
	{
		nbr[i++] = base[(n % unit)*sign];
		n /= unit;
	}
	ret = i;
	while (0 < i--)
		write (1, nbr + i, 1);
	return (ret);
}

int	ft_pf_putnbr_ubase(unsigned int n, const char *base, char c)
{
	char				nbr[32];
	const unsigned int	unit = (unsigned int)ft_strlen(base);
	unsigned int		i;
	int					ret;

	if (c == 'x')
		write(1, "0x", 2);
	else if (c == 'X')
		write(1, "0X", 2);
	if (n == 0)
		write (1, "0", 1);
	ret = (c == 'x') * 2 + (c == 'X') * 2 + (n == 0);
	i = 0;
	while (n != 0 )
	{
		nbr[i++] = base[n % unit];
		n /= unit;
	}
	ret += i;
	while (0 < i--)
		write (1, nbr + i, 1);
	return (ret);
}

int	ft_pf_pointer(void *ptr)
{
	const char		*base = "0123456789abcdef";
	char			nbr[64];
	unsigned long	n;
	unsigned int	i;
	int				ret;

	write(1, "0x", 2);
	n = (unsigned long)ptr;
	if (n == 0)
		write (1, "0", 1);
	ret = 2 + (n == 0);
	i = 0;
	while (n != 0 )
	{
		nbr[i++] = base[n % 16];
		n /= 16;
	}
	ret += i;
	while (0 < i--)
		write (1, nbr + i, 1);
	return (ret);
}

int	ft_pf_char(int c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_pf_string(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
