#include "ft_printf.h"

int	ft_print_uint(tab *init)
{
	int	len;
	unsigned int	n;

	len = 0;
	n = va_arg(init->args, unsigned int);
	if (n == 0)
		write(1, "0", 1);
	else
	{	
		ft_itoa(n);
		while (n > 0)
		{
			ft_putchar(n % 10 + '0');
			n /= 10;
			len++;
		}
	}
	return (len);
}
