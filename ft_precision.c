/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:19:58 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:37:05 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision(t_tab *init, const char *format, int i)
{
	init->precision = 1;
	i++;
	if (format[i] == '*')
	{
		init->width_arg = 1;
		i++;
	}
	return (i);
}
