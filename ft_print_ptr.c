/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:19:54 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 16:04:54 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len = 1;
	else
		while (ptr > 0)
		{
			ptr /= 16;
			len++;
		}
	return (len);
}

static void	ft_putptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else 
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_print_ptr(tab *init, unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else if (ptr != 0)
	{
		init->pointer = 1;
		ft_putchar('0');
		ft_putchar('x');
		len = 2;
	}
	if (ptr == 0)
	{
		ft_putchar('0');
		len++;
	}
	else
	{
		ft_putptr(ptr);
		len += ft_ptrlen(ptr);
	}
	init->pointer = 0;
	return (len);
}
