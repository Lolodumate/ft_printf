/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_len_ft_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:21:14 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 17:43:37 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub_len_ft_printf(const char *format, int i)
{
	int	j;

	j = 0;
	while (format[i + j])
	{
		if (ft_strchr("-+ #0123456789.*", format[i + j]))
			j++;
		if (ft_strchr("cspdiuxX%", format[i + j]))
		{
			j++;
			break ;
		}
	}
	return (j);
}
