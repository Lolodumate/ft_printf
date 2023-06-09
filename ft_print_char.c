#include "ft_printf.h"

int	ft_print_char(tab *init)
{
	char	c;
	int	len;

	len = 1;
	c = va_arg(init->args, int);
	write(1, &c, 1);
	return (len);
}
