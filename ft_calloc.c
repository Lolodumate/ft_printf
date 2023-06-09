/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:13:23 by laroges           #+#    #+#             */
/*   Updated: 2023/05/20 11:53:04 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (nmemb != 0 && size != 0 && ((nmemb * size) / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset((unsigned char *)ptr, 0, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*tab;
	size_t	nmemb;
	size_t	size;
	size_t	i;

	nmemb = 20;
	size = 1;
	i = 0;
	tab = calloc(nmemb, size);
	while (i < 20)
	{
		printf("<%d> ", tab[i]);
		i++;
	}
	return (0);
}*/
