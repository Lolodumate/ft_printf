/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:34:31 by laroges           #+#    #+#             */
/*   Updated: 2023/05/08 12:05:43 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[100] = "Salut ! Ceci est une chaine de caracteres !";
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	i;
	size_t	n; // Taille en bytes

	i = 0;
	n = 32;
	printf("\nValeur de n : %ld\n\n", n);
	while (i <= 10)
	{
		printf("<%d> ", tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_bzero(&tab[3], n);
	while (i <= 10)
	{
		printf("<%d> ", tab[i]);
		i++;
	}
	printf("\n\n*************************************\n\n");
	i = 0;
	printf("Avant ft_bzero : %s\n", str);
	ft_bzero(str, n);
	printf("Apres ft_bzero : %s\n", str);
	while (i < 100)
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
