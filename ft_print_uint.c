/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:39:35 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 18:04:45 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_count(unsigned int res)
{
	int	len;

	len = 0;
	while (res > 0)
	{
		len++;
		res /= 10;
	}
	return (len);
}

int	ft_print_uint(unsigned int args)
{
	char				*str;
	int					len;
	unsigned int		res;

	len = ft_intlen(args);
	res = 0;
	if (args == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		str = malloc(sizeof(char) * len + 1);
		if (str == NULL)
			return (-1);
		if (args > 0)
			res = args;
		else
			res = UINT_MAX + args + 1;
	}
	ft_fill_ui(res);
	free(str);
	return (ft_count(res));
}
