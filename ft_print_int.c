#include "ft_printf.h"

static void	ft_padding(tab *init, char *str)
{
	int	i;
	char	c; 

	i = 0;
	if (init->zero != 0)
		c = '0';
	else
		c = ' ';
	while (str[i])
	{
		str[i] = c;
		i++;
	}
}

static void	ft_fillstr(tab *init, char *str, int n, int len_n)
{
	int	i;
	int	intlen;

	i = 0;
	intlen = 0;
	ft_padding(init, str);
	if (n >= 0 && init->sign != 0 && init->zero != 0)
		str[0] = '+';
	else if (n < 0 && init->zero != 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (len_n-- > intlen && n > 0)
	{
		str[len_n] = (n % 10) + '0';
		n /= 10;
	}
	if (init->zero == 0 && n >= 0 && init->sign != 0)
		str[len_n] = '+';
	else if (n < 0)
		str[len_n] = '-';
}

int	ft_print_int(tab *init)
{
	int	n;
	int	len;
	char	*str;

	n = va_arg(init->args, int);
	len = ft_intlen(n);
	if (init->width > len)
		len = init->width;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (-1);
	str = ft_itoa(n);
	ft_fillstr(init, str, n, len);
	ft_putstr_fd(str, 0);
	free(str);
	return (len);
}
