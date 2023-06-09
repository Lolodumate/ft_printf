/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:56:21 by laroges           #+#    #+#             */
/*   Updated: 2023/05/25 11:32:02 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
			i++;
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;

	i = 0;
	len_s1 = ft_strlen(s1);
	while (s1[len_s1 - 1] && ft_strchr(set, s1[len_s1 - 1]) != NULL)
	{
		len_s1--;
		i++;
	}
	return (i);
}

static size_t	ft_len(char const *s1, char const *set)
{
	size_t	len;
	size_t	i_start;
	size_t	i_end;

	len = ft_strlen(s1);
	i_start = ft_start(s1, set);
	i_end = ft_end(s1, set);
	if (i_start >= len)
		return (0);
	len = len - i_start - i_end;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		*str = '\0';
	}
	str = malloc(sizeof(char) * ft_len(s1, set) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + ft_start(s1, set), ft_len(s1, set) + 1);
	return (str);
}
/*
int	main(void)
{
	char const	*s1 = "xxxbonjourxxx";
	char const	*set = "xx";

	printf("\nchar const *str = %s\n", s1);
	printf("char const set = %s\n", set);
	printf("Valeur de ft_check_start = 	%ld\n", ft_check_start(s1, set));
	printf("Valeur de ft_check_end = 	%ld\n", ft_check_end(s1, set));
	printf("*******************************************************\n");
	printf(">>>>>> Resultat : %s\n", ft_strtrim(s1, set));
	printf("*******************************************************\n");
	printf("\n");
	return (0);
}*/
