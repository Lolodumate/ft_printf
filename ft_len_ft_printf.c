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

	tmp = 0;
	i = 0;
//	printf("Valeur de ft_strlen(format) dans ft_len_ft_printf : %ld\n", ft_strlen(format));
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp++;
			while (format[i + tmp])
			{
				if (ft_strchr("-+ #0123456789.*", format[i + tmp]))
					tmp++;
				if (ft_strchr("cspdiuxX%", format[i + tmp]))
				{
					tmp++;
					break ;
				}
			}
			i += tmp;
		}
		else
			i++;
	}
//	printf("Valeur de tmp dans ft_len_ft_printf : %d\n", tmp);
	return (ft_strlen(format) - tmp);
}
