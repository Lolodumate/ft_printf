/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:28:29 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:34:13 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_browse_format(t_tab *init, const char *format, int i)
{
	int	len_args;

	len_args = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len_args += ft_flags(init, format, i);
			i = init->index - 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (len_args);
}
