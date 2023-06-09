/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:06:33 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 13:10:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (c);
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
	while (c <= 127)
	{
		res = ft_isprint(c);
		printf("%c - %d\n", c, res);
		c++;
	}
	return (0);
}*/
