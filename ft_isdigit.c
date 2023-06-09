/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:22 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 12:42:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	c = '+';
	res = ft_isdigit(c);
	printf("%c - %d\n", c, res);
	return (0);
}*/
