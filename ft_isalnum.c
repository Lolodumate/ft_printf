/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:42:15 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 12:51:07 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
	while (c <= '~')
	{
		res = ft_isalnum(c);
		printf("%c - %d\n", c, res);
		c++;
	}
	return (0);
}*/
