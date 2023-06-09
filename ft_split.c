/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 07:52:51 by laroges           #+#    #+#             */
/*   Updated: 2023/05/22 12:22:15 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(char const *s, char c, size_t index)
{
	size_t	size;

	size = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		size += sizeof(char);
	}
	return (size);
}

static size_t	ft_counter(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	ft_free(char **str)
{
	while (*str)
	{
		free(*str);
		str = NULL;
		str++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	str = (char **)ft_calloc(ft_counter(s, c) + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++j < ft_counter(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, ft_getsize(s, c, i));
		if (str[j] == NULL)
		{
			ft_free(str);
			return (NULL);
		}
		i += ft_getsize(s, c, i);
	}
	return (str);
}
