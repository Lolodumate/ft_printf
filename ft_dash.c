/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:43:24 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:35:35 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dash(t_tab *init, const char *format, int i)
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
