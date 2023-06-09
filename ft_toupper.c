/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:10:49 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 14:37:27 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'a';
	while (c <= 'z')
	{
		printf("%c ", ft_toupper(c));
		c++;
	}
	printf("\n");
	return (0);
}*/
