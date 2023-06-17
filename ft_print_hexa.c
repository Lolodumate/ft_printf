/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:58:39 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 16:07:08 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalen(unsigned int x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	else
	{
		while (x > 0)
		{
			x /= 16;
			len++;
		}
	}
	return (len);
}

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
			ft_putchar(x + '0');
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
	int				len;
	unsigned int	x;

	len = 0;
	x = va_arg(init->args, unsigned int);
	if (init->hashtag != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		len = 2;
	}
	ft_puthexa(x, format[i]);
	len += ft_hexalen(x);
	return (len);
}
