/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:05 by laroges           #+#    #+#             */
/*   Updated: 2023/05/09 14:04:55 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[50] = "Test de ma fonction ft_strdup !";

	printf("String AVANT : %s\n", str);
	printf("Adresse de l'originale : %p\n", str);
	printf("\n*************************\n");
	printf("String APRES (copie) : %s\n", ft_strdup(str));
	printf("Adresse de la copie : %p\n", ft_strdup(str));
	return (0);
}*/
