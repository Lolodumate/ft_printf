/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:53:40 by laroges           #+#    #+#             */
/*   Updated: 2023/05/23 16:31:42 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (elt == NULL)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
