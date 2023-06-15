#include "ft_printf.h"

int	ft_print_char(tab *init)
{
	char	c;

	c = va_arg(init->args, int);
	write(1, &c, 1);
	return (1);
}
