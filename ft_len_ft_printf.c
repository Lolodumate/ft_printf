/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_ft_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:33:42 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 17:53:04 by laroges          ###   ########.fr       */
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
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp++;
			i++;
			j = ft_sub_len_ft_printf(format, i);
			tmp += j;
			i += j;
		}
		else
			i++;
	}
	return (ft_strlen(format) - tmp);
}
