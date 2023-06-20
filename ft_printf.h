/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:46:39 by laroges           #+#    #+#             */
/*   Updated: 2023/06/17 18:52:05 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct tab_ft_printf
{
	va_list	args;
	int	index;
	int	width;
	int	width_arg;
	int	precision;
	int	lenght;
	int	zero;
	int	pointer;
	int	dash;
	int	hashtag;
	int	sign;
	int	is_zero;
	int	percent;
	int	space;
	int	is_negative;
} tab;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_conversion(tab *init, const char *format, int i);
int	ft_dash(tab *init, const char *format, int i);
int	ft_flags(tab *init, const char *format, int i);
int	ft_intlen(int n);
int	ft_justify(tab *init, char *str, long long n, int len_n);
int	ft_len_ft_printf(const char *format);
int	ft_precision(tab *init, const char *format, int i);
int	ft_printf(const char *format, ...);
int	ft_print_char(tab *init);
int	ft_print_hexa(tab *init, const char *format, int i);
int	ft_print_int(tab *init, int args);
int	ft_print_percent(void);
int	ft_print_ptr(tab *init);
int	ft_print_str(tab *init, char *str);
int	ft_print_uint(tab *init);
int	ft_width(tab *init, const char *format, int i);
tab	*ft_init(tab *init);

# endif
