/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:10 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 17:11:49 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_padding(t_tab *init, char *str, int args)
{
	int		i;
	char	c;

	i = 0;
	if (init->zero != 0 || init->precision != 0 || args == 0)
		c = '0';
	else
		c = ' ';
	while (str[i])
	{
		str[i] = c;
		i++;
	}
}

static void	ft_fillstr(t_tab *init, char *str, int args, int len_n)
{
	long long	nb;

	nb = args;
	if (args == INT_MIN)
		nb = 2147483648;
	else if (nb < 0)
		nb *= -1;
	if (init->dash == 0 || args == 0)
		ft_padding(init, str, args);
	if (args >= 0 && init->sign != 0
		&& (init->zero != 0 && init->precision != 0))
			str[0] = '+';
	else if (args < 0 && (init->zero != 0 || init->precision != 0))
		str[0] = '-';
	ft_justify(init, str, nb, len_n);
}

int	ft_print_int(t_tab *init, int args)
{
	int		i;
	int		len_n;
	char	*str;

	i = 0;
	len_n = ft_intlen(args);
	if (args < 0)
		init->is_negative = 1;
	len_n = ft_sub_print_int(init, args, len_n);
	if (init->width == 0 && init->precision != 0 && (args == 0 || !args))
		str = NULL;
	else
	{
		str = ft_itoa(args);
		while (++i < len_n)
			str[i] = ' ';
		ft_fillstr(init, str, args, len_n);
		ft_putstr(str);
		free(str);
	}
	init->is_negative = 0;
	init->precision = 0;
	return (len_n);
}
