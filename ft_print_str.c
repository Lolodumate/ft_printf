/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:30:54 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 14:35:05 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(tab *init, char *str)
{
	int	i;
	int	width;

	width = 0;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		if (init->width != 0)
			width = init->width;
		else if (init->width_arg != 0)
			width = va_arg(init->args, int);
		else
			width = ft_strlen(str);
		while (str[i] && width > 0)
		{
			ft_putchar(str[i]);
			i++;
			width--;
		}
	}
	return (i);
}
