/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:46:39 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 18:04:21 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct tab_ft_printf
{
	va_list	args;
	int		index;
	int		width;
	int		width_arg;
	int		precision;
	int		lenght;
	int		zero;
	int		pointer;
	int		dash;
	int		hashtag;
	int		sign;
	int		is_zero;
	int		percent;
	int		space;
	int		is_negative;
}	t_tab;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_search_flags(t_tab *init, const char *format, int i);
int		ft_browse_format(t_tab *init, const char *format, int i);
int		ft_conversion(t_tab *init, const char *format, int i);
int		ft_dash(t_tab *init, const char *format, int i);
int		ft_flags(t_tab *init, const char *format, int i);
int		ft_intlen(int n);
int		ft_justify(t_tab *init, char *str, long long n, int len_n);
int		ft_len_ft_printf(const char *format);
int		ft_precision(t_tab *init, const char *format, int i);
int		ft_printf(const char *format, ...);
int		ft_print_char(t_tab *init);
int		ft_printx(t_tab *init, const char *format, int i, unsigned int args);
int		ft_print_int(t_tab *init, int args);
int		ft_print_percent(void);
int		ft_print_ptr(t_tab *init, unsigned long long ptr);
int		ft_print_str(t_tab *init, char *str);
int		ft_print_uint(unsigned int args);
int		ft_sub_len_ft_printf(const char *format, int i);
int		ft_sub_print_int(t_tab *init, int args, int len_n);
int		ft_sub_print_str(t_tab *init, char *str, int width, int i);
int		ft_width(t_tab *init, const char *format, int i);
t_tab	*ft_init(t_tab *init);

#endif
