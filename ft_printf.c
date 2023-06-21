/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:44:38 by laroges           #+#    #+#             */
/*   Updated: 2023/06/21 18:04:12 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_conversion(t_tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	if (ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == 'c')
			len += ft_print_char(init);
		else if (format[i] == 's')
			len += ft_print_str(init, va_arg(init->args, char *));
		else if (format[i] == 'p')
			len += ft_print_ptr(init, va_arg(init->args, unsigned long long));
		else if (format[i] == 'd' || format[i] == 'i')
			len += ft_print_int(init, va_arg(init->args, int));
		else if (format[i] == 'u')
			len += ft_print_uint(va_arg(init->args, unsigned int));
		else if (format[i] == 'x' || format[i] == 'X')
			len += ft_printx(init, format, i, va_arg(init->args, unsigned int));
		else if (format[i] == '%' && format[i - 1] == '%')
			len += ft_print_percent();
		i++;
		init->index = i;
	}
	return (len);
}

int	ft_flags(t_tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	if (!ft_strchr("cspdiuxX%", format[i]))
	{
		ft_search_flags(init, format, i);
		if (format[i] == '.')
			i = ft_precision(init, format, i);
		if (ft_isdigit(format[i]))
			ft_width(init, format, i);
		while (ft_isdigit(format[i]))
			i++;
		init->index = i;
	}
	len = ft_conversion(init, format, i);
	init->width = 0;
	init->width_arg = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_args;
	t_tab	*init;

	init = malloc(sizeof(t_tab));
	if (init == NULL)
		return (-1);
	ft_init(init);
	va_start(init->args, format);
	i = 0;
	len_args = ft_browse_format(init, format, i);
	va_end(init->args);
	free(init);
	return (ft_len_ft_printf(format) + len_args);
}
