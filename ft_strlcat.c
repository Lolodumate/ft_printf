/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:52:58 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 15:53:44 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	ft_strlcpy(dst + dst_len, src, size - dst_len);
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

int	main(void)
{
	char	dst_strlcat[50] = "12345";
	char	dst_ft_strlcat[50] = "12345";
	char	src[20] = "TEST";
	size_t	size;
	size_t	res_strlcat;
	size_t	res_ft_strlcat;

	size = 15;
	res_strlcat = 0;
	res_ft_strlcat = 0;
	printf("Valeur de size : %ld\n\n", size);
	printf("Valeur de dst_strlcat AVANT : %s\n", dst_strlcat);
	printf("Valeur de dst_ft_strlcat AVANT : %s\n", dst_ft_strlcat);
	printf("\n**********************************\n\n");
	res_strlcat = strlcat(dst_strlcat, src, size);
	res_ft_strlcat = ft_strlcat(dst_ft_strlcat, src, size);
	printf("Valeur de dst_strlcat APRES : %s\n", dst_strlcat);
	printf("Valeur de dst_ft_strlcat APRES : %s\n", dst_ft_strlcat);
	printf("Valeur de retour de strlcat : %ld\n", res_strlcat);
	printf("Valeur de retour de strlcat : %ld\n", res_ft_strlcat);
	return (0);
}*/
