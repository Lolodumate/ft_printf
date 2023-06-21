/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_print_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:26:10 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:30:48 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub_print_str(t_tab *init, char *str, int width, int i)
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
	return (i);
}
