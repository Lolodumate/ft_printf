/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:43:24 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 16:13:23 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dash(tab *init, const char *format, int i)
{
	if (format[i] == '-')
	{
		if (format[i + 1] != '.')
			init->dash = 1;
	}
	else
		init->dash = 0;
	return (init->dash);
}
