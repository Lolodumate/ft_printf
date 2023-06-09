/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:15:36 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 15:55:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str_little;
	char	*str_big;
	size_t	i;
	size_t	j;

	str_little = (char *)little;
	str_big = (char *)big;
	i = 0;
	j = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (str_little[0] == '\0')
		return (str_big);
	while (str_big[i] && i < len)
	{
		while (str_big[i + j] && str_little[j]
			&& (str_little[j] == str_big[i + j]) && (i + j) < len)
			j++;
		if (str_little[j] == '\0')
			return (&str_big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

int	main(void)
{
	char	big[50] = "";
	char	little[50] = "";
	size_t	len;

	len = -1;
	//char *res = ft_strnstr(big, little, len);
	printf("ft_strnstr :	%p\n", ft_strnstr(big, little, len));
	printf("strnstr :	%p\n", strnstr(big, little, len));
	return (0);
}*/
