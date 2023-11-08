#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
int ft_pf_putnbr_base(int n, const char *base);
int ft_pf_putnbr_ubase(unsigned int n, const char *base, char c);
int ft_pf_char(int c);
int ft_pf_string(char *str);
int	ft_pf_pointer(void *ptr);
int ft_pf_converse(const char **dptr, va_list ap);
int ft_printf(const char *form, ...);
#endif
