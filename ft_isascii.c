/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:59:08 by laroges           #+#    #+#             */
/*   Updated: 2023/05/08 11:25:04 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	res;
	int	c;

	res = 0;
	c = 0;
	while (c <= 999)
	{
		res = ft_isascii(c);
		printf("c = %d - <%c> - %d\n", c, c, res);
		c++;
	}
	return (0);
}*/
