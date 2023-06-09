/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:25:32 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 17:23:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (n-- > 0)
			str_dest[n] = str_src[n];
	}
	else
	{
		while (n-- > 0)
		{
			*str_dest = *str_src;
			str_dest++;
			str_src++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("<%d> ", tab[i]);
		i++;
	}
	printf("\n");
	void *dest = (void *)(tab + 1);
	void *src = (void *)tab;
	size_t	n;

	n = 10 * sizeof(int);
	memmove(dest, src, n);
	i = 0;
	while (i < 10)
	{
		printf("<%d> ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
