#include "ft_printf.h"

static void	ft_add_sign(tab *init, char *str, int len_n)
{
	if (init->zero == 0 && init->is_negative == 0 && init->sign != 0)
		str[len_n] = '+';
	else if (init->is_negative != 0 && init->zero == 0)
		str[len_n] = '-';
	else if (init->is_negative == 0 && init->space != 0)
		str[len_n] = ' ';
}

static void	ft_justify_right(tab *init, char *str, int n, int len)
{
	while (len-- > 0 && n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	ft_add_sign(init, str, len);
}

static void	ft_justify_left(tab *init, char *str, int n, int len)
{
	if (init->is_negative != 0 || init->sign != 0 || init->space != 0)
		len++;
	while (len-- > 0 && n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	ft_add_sign(init, str, len);
}

int	ft_justify(tab *init, char *str, int n, int len_n)
{
	int	len;
	int	i;

	len = ft_intlen(n);;
	i = 0;
	if (init->dash == 0)
		ft_justify_right(init, str, n, len_n);
	else
	{
		if (str[0] == '+' || str[0] == '-')
			i++;
		ft_justify_left(init, str, n, len);
	}
	return (len);
}