/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:35:10 by laroges           #+#    #+#             */
/*   Updated: 2023/05/16 13:20:08 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("42", O_WRONLY | O_CREAT, O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	ft_putnbr_fd(42, fd);
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}*/
