/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:15:55 by laroges           #+#    #+#             */
/*   Updated: 2023/05/18 05:10:58 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t	ft_intlen(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_fill_char_to_int(char *str, long long n, size_t len, size_t i)
{
	while (len > i)
	{
		str[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	long_n;

	long_n = n;
	len = ft_intlen(long_n) + ft_sign(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		long_n *= -1;
		ft_fill_char_to_int(str, long_n, len, 1);
	}
	else
		ft_fill_char_to_int(str, long_n, len, 0);
	return (str);
}
/*
int	main(void)
{
	int	test;

	//test = -2147483648;
	//test = -123456789;
	test = 1;
	printf("Entier = %d\n", test);
	printf("Chaine de caracteres = %s\n", ft_itoa(test));
	//printf("Test ft_intlen :\n");
	//printf("int = %d\nCalcul de ft_intlen = %ld\n", test, ft_intlen(test));
	return (0);
}*/
