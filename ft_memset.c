/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:17:37 by laroges           #+#    #+#             */
/*   Updated: 2023/05/08 09:45:37 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *)s + n - 1) = (unsigned char)c;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[10] = "Salut !";
	int	c;
	size_t	n;

	c = 'O';
	n = 3;
	printf("AVANT : %s\n", str);
	ft_memset(str, c, n);
	printf("APRES : %s\n", str);
	return (0);
}*/
