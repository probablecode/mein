#include "libft.h"
#include "ft_printf.h"
int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, form);
	ret = 0;
	while (*form)
	{
		if (*form == '%')
			ret += ft_pf_converse(&form, ap);
		else
		{	
			ft_putchar_fd(*form, 1);
			ret++;
		}
		form++;
	}
	va_end(ap);
	return (ret);
}

int	ft_pf_converse(const char **dptr, va_list ap)
{
	const char	*decimal = "0123456789";
	const char	*l_hex = "0123456789abcdef";
	const char	*u_hex = "0123456789ABCDEF";
	char		c;

	(*dptr)++;
	c = **dptr;
	if (c == 'c')
		return (ft_pf_char(va_arg(ap, int)));
	else if (c == 's')
		return (ft_pf_string(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_pf_pointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_pf_putnbr_base(va_arg(ap, int), decimal));
	else if (c == 'u')
		return (ft_pf_putnbr_ubase(va_arg(ap, unsigned int), decimal, c));
	else if (c == 'x')
		return (ft_pf_putnbr_ubase(va_arg(ap, unsigned int), l_hex, c));
	else if (c == 'X')
		return (ft_pf_putnbr_ubase(va_arg(ap, unsigned int), u_hex, c));
	else if (c == '%')
		return (ft_pf_char('%'));
	return (0);
}
#include <stdio.h>
int	main(void)
{
	int num;
	int	*ptr = &num;
	printf("number : %d\n",printf("%p\n%p\n", ptr, NULL));
	ft_printf("number : %d\n",ft_printf("%p\n%p\n", ptr, NULL));
	return (0);
}
