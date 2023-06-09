/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:15:20 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 14:40:48 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'A';
	while (c <= 'Z')
	{
		printf("%c ", ft_tolower(c));
		c++;
	}
	return (0);
}*/
