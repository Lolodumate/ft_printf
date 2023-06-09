/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:05:31 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 17:40:42 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = {0, 1, 2, 3, 4, 5};
	int	c;
	size_t	n;

	c = 0;
	n = 0;
	printf("*****************************************\n");
	printf("*s = %s, c = %d, n = %ld\n", s, c, n);
	printf("*----------------------------------------\n");
	printf("* Retour de la fonction memchr : %p\n", memchr(s, c, n));
	printf("* Retour de la fonction ft_memchr : %p\n", ft_memchr(s, c, n));
	printf("*****************************************\n");
	return (0);
}*/
