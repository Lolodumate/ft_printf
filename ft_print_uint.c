#include "ft_printf.h"

static void	ft_fill_ui(unsigned int res)
{
	if (res > 9)
	{
		ft_fill_ui(res / 10);
		ft_fill_ui(res % 10);
	}
	else
		ft_putchar(res + '0');
}

int	ft_print_uint(tab *init)
{
	char	*str;
	int	n;
	int	len;
	unsigned int	res;


	n = va_arg(init->args, unsigned int);
	len = ft_intlen(n);
	res = 0;
	if (n == 0)
		ft_putchar('0');
	else
	{
		str = malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (-1);
		if (n > 0)
			res = n;	
		else
			res = UINT_MAX + n + 1;
	}
	ft_fill_ui(res);
	free(str);
	return (len);
}
