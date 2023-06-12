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
	int	nb;

	nb = n;
	if (nb < 0)
		nb *= -1;
	if (init->dash == 0)
		ft_padding(init, str);
	if (n >= 0 && init->sign != 0 && init->zero != 0)
		str[0] = '+';
	else if (n < 0 && init->zero != 0)
		str[0] = '-';
	ft_justify(init, str, nb, len_n);
}

int	ft_print_int(tab *init)
{
	int	i;
	int	n;
	int	len_n;
	char	*str;

	i = 0;
	n = va_arg(init->args, int);
	len_n = ft_intlen(n);
	if (n < 0)
		init->is_negative = 1;
	if (init->width > len_n)
		len_n = init->width;
	str = malloc(sizeof(char) * len_n);
	if (str == NULL)
		return (-1);
	str = ft_itoa(n);
	while (++i < len_n)
		str[i] = ' ';
	ft_fillstr(init, str, n, len_n);
	ft_putstr(str);
	free(str);
	return (len_n);
}
