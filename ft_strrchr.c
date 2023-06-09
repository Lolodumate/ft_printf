/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:49:02 by laroges           #+#    #+#             */
/*   Updated: 2023/05/08 15:14:05 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	str = (char *)s;
	len = ft_strlen(str);
	if (c == '\0')
		return (str + len);
	while (len > 0)
	{
		if (str[len - 1] == (char)c)
			return (str + len - 1);
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[6] = "iiiio";
	int	c;
	
	c = 'p';
	printf("%p\n", ft_strrchr(str, c));
	return (0);
}*/
