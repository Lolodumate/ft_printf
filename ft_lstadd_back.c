/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:05:34 by laroges           #+#    #+#             */
/*   Updated: 2023/05/23 16:41:17 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elt;

	if (*lst != NULL && *lst != NULL)
	{
		elt = ft_lstlast(*lst);
		elt->next = new;
	}
	else
		*lst = new;
}
