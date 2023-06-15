/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:19:54 by laroges           #+#    #+#             */
/*   Updated: 2023/06/15 19:42:40 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, fd);
		ft_putptr(ptr % 16, fd);
	}
	else 
	{
		if (ptr < 10)
			ft_putchar_fd(ptr + '0', fd);
		else
			ft_putchar_fd(ptr - 10 + 'a', fd);
	}
}

int	ft_print_ptr(tab *init)
{
	int	len;
	int	fd;
	int	ret;
	unsigned long	ptr;
	char buf[21];

	len = 0;
	fd = open("ptr", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (1);
	ptr = va_arg(init->args, unsigned long);
	if (ptr != 0)
	{
		ft_putchar_fd('0', fd);
		ft_putchar_fd('x', fd);
		ft_putptr(ptr, fd);	
	}
	if (close(fd) == -1)
		return (1);
	fd = open("ptr", O_RDONLY);
	if (fd == -1)
		return (1);
	ret = read(fd, buf, 20);
	buf[ret] = 0;
	ft_putstr(buf);
	len = ft_strlen(buf);
	if (close(fd) == -1)
		return (1);
	return (len);
}
