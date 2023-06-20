/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:33:42 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 19:51:37 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ft_printf(const char *format)
{
	int	tmp;
	int	i;
	int	j;

	tmp = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp++;
			j = 1;
			while (format[i + j])
			{
				if (ft_strchr("-+ #0123456789.*", format[i + j]))
				{
					tmp++;
					j++;
				}
				if (ft_strchr("cspdiuxX%", format[i + j]))
				{
					tmp++;
					j++;
					break ;
				}
			}
			i += j;
		}
		else
			i++;
	}
	return (ft_strlen(format) - tmp);
}
