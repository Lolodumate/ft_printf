/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:15 by laroges           #+#    #+#             */
/*   Updated: 2023/05/12 10:52:08 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		*str_dest = *str_src;
		str_dest++;
		str_src++;
		n--;
	}
	return (dest);
}
