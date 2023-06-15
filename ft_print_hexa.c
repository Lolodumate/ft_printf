#include "ft_printf.h"

static void	ft_puthexa(int x, char format)
{
	if (x >= 16)
	{
		ft_puthexa(x / 16, format);
		ft_puthexa(x % 16, format);
	}
	else
	{
		if (x < 10)
		{
			ft_putchar(x + '0');
		}	
		else
		{
			if (format == 'x')
				ft_putchar(x - 10 + 'a');
			if (format == 'X')
				ft_putchar(x - 10 + 'A');
		}
	}
}

int	ft_print_hexa(tab *init, const char *format, int i)
{
	int	len;
	unsigned int	x;

	len = 0;
	x = va_arg(init->args, unsigned int);
	if (format[i - 1] == '#')
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	ft_puthexa(x, format[i]);
	return (len);
}
