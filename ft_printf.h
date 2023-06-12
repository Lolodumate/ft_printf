#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct tab_ft_printf
{
	va_list	args;
	int	index;
	int	width;
	int	precision;
	int	lenght;
	int	zero;
	int	pointer;
	int	dash;
	int	sign;
	int	is_zero;
	int	percent;
	int	space;
	int	is_negative;
} tab;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_intlen(int n);
int	ft_justify(tab *init, char *str, int n, int len_n);
int	ft_print_char(tab *init);
int	ft_print_hexa(tab *init, char format);
int	ft_print_int(tab *init);
int	ft_print_str(tab *init);
int	ft_print_uint(tab *init);
int	ft_width(tab *init, const char *format, int i);
tab	*ft_init(tab *init);

# endif
