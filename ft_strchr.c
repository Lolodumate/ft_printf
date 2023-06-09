/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:17:53 by laroges           #+#    #+#             */
/*   Updated: 2023/05/08 15:16:14 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[5] = "iiii";
	int	c;

	c = 'o';
	printf("%s\n", str);
	printf("%p\n", ft_strchr(str, c));
	return (0);
}*/
