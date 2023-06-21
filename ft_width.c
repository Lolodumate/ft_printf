/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:58:06 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 16:40:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(t_tab *init, const char *format, int i)
{
	int		len;
	char	*str;

	len = 0;
	while (ft_isdigit(format[i]))
	{
		i++;
		len++;
	}
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);
	while (len > 0)
	{
		str[len - 1] = format[i - 1];
		len--;
		i--;
	}
	init->width = ft_atoi(str);
	free(str);
	return (init->width);
}
