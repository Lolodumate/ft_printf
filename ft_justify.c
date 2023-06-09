/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:28:27 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:36:23 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_sign(t_tab *init, char *str, int len_n)
{
	if (init->precision == 0)
	{
		if (init->zero == 0 && init->is_negative == 0 && init->sign != 0)
			str[len_n] = '+';
		else if (init->is_negative != 0 && init->zero == 0)
			str[len_n] = '-';
		else if (init->is_negative == 0 && init->space != 0)
			str[len_n] = ' ';
	}
}

static void	ft_justify_right(t_tab *init, char *str, long long n, int len)
{
	if (init->width > len)
		len++;
	if (n == 0)
		str[ft_intlen(n)] = '0';
	else
	{
		while (len-- > 0 && n > 0)
		{
			str[len] = (n % 10) + '0';
			n /= 10;
		}
	}
	ft_add_sign(init, str, len);
}

static void	ft_justify_left(t_tab *init, char *str, long long n, int len)
{
	if (init->is_negative != 0 || init->sign != 0 || init->space != 0)
		len++;
	if (n == 0)
		len -= (init->sign + 1);
	else
	{
		while (len-- > 0 && n > 0)
		{
			str[len] = (n % 10) + '0';
			n /= 10;
		}
	}
	ft_add_sign(init, str, len);
}

int	ft_justify(t_tab *init, char *str, long long n, int len_n)
{
	int	len;
	int	i;

	len = ft_intlen(n);
	i = 0;
	if (init->dash == 0 && init->width > len)
		ft_justify_right(init, str, n, len_n);
	else
	{
		if (str[0] == '+' || str[0] == '-')
			i++;
		ft_justify_left(init, str, n, len);
	}
	return (len);
}
