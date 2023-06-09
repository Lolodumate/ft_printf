/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:57:15 by laroges           #+#    #+#             */
/*   Updated: 2023/05/09 13:03:44 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 == '\0' || *str2 == '\0')
			return (*str1 - *str2);
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[50] = "Coucou ";
	char	s2[50] = "Coucou !";
	size_t	n;
	int	res;

	n = 8;
	res = ft_strncmp(s1, s2, n);
	printf("%d\n", res);
	return (0);
}*/
