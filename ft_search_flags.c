/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:19:38 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:33:36 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search_flags(t_tab *init, const char *format, int i)
{
	if (format[i] == '-')
	{
		ft_dash(init, format, i);
		i++;
	}
	while (ft_strchr("+ #0*", format[i]))
	{
		if (format[i] == '+')
			init->sign = 1;
		if (format[i] == ' ')
			init->space = 1;
		if (format[i] == '#')
			init->hashtag = 1;
		if (format[i] == '0')
			init->zero = 1;
		i++;
	}
}
