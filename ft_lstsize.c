/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:58:45 by laroges           #+#    #+#             */
/*   Updated: 2023/05/23 13:43:58 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	nb_elt;

	nb_elt = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		nb_elt++;
	}
	return (nb_elt);
}
