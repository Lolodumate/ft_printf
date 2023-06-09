/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:34:54 by laroges           #+#    #+#             */
/*   Updated: 2023/05/04 12:37:03 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	
	(void)argc;
	(void)argv;

	int	res;
	int	c;
	
	res = 999;
	c = ']';
       	res = ft_isalpha(c);
	printf("%c - %d\n", c, res);
	return (0);
}*/
