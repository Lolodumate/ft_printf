/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_print_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:00:16 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 17:10:22 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub_print_int(t_tab *init, int args, int len_n)
{
	if (args < 0)
		init->is_negative = 1;
	if (init->width > len_n)
		len_n = init->width;
	if ((init->width != 0 || init->is_negative != 0) && len_n != 0)
		len_n++;
	if ((init->width > ft_intlen(args)) && init->precision == 0
		&& len_n != 0 && (init->sign != 0 || init->is_negative != 0))
		len_n--;
	return (len_n);
}
