/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:05:34 by laroges           #+#    #+#             */
/*   Updated: 2023/05/05 15:32:18 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dst[30] = "";
	char	src[30] = "12345678901234567890";
	size_t	size;
	size_t	res;

	size = 10;
	printf("Valeur de size : %ld\n\n", size);
	printf("Valeur de dst AVANT : %s\n", dst);
	printf("Valeur de src AVANT : %s\n", src);
	res = ft_strlcpy(dst, src, size);
	printf("Valeur de retour de la fonction : %ld\n", res);
	printf("***************************************************\n");
	printf("Valeur de dst APRES : %s\n", dst);
	printf("Valeur de src APRES : %s\n", src);
	return (0);
}*/
