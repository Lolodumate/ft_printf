/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:05:52 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 13:17:48 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
