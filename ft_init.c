/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:22:13 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:42:12 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*ft_init(t_tab *init)
{
	init->index = 0;
	init->width = 0;
	init->width_arg = 0;
	init->precision = 0;
	init->lenght = 0;
	init->zero = 0;
	init->pointer = 0;
	init->dash = 0;
	init->hashtag = 0;
	init->sign = 0;
	init->is_zero = 0;
	init->percent = 0;
	init->space = 0;
	init->is_negative = 0;
	return (init);
}
