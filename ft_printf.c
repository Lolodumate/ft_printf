/* https://github.com/mcombeau/ft_printf/blob/main/README.md
 *
 *
 */

#include "ft_printf.h"
#include "libft.h"

int	ft_conversion(tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	if (ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == 'c') // int
		       len += ft_print_char(init);
		if (format[i] == 's') // char *
			len += ft_print_str(init);
		if (format[i] == 'p') // unsigned long
			len += ft_print_hexa(init, format[i]);
		if (format[i] == 'd' || format[i] == 'i') // int
			len += ft_print_int(init);
		if (format[i] == 'u') // unsigned int
			len += ft_print_uint(init);
		if (format[i] == 'x' || format[i] == 'X') // unsigned int
			len += ft_print_hexa(init, format[i]);
		i++;
		init->index = i;
	}
	return (len);
}

int	ft_flags(tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == '-')
	{
		init->dash = 1;
		i++;
	}
	if (format[i] == '.')
	{
		init->precision = 1;
		i++;
	}
	else
		while (ft_strchr("+ #0", format[i]))
		{
			if (format[i] == '+')
				init->sign = 1;
			if (format[i] == ' ')
				init->space = 1;
			if (format[i] == '#')
				init->pointer = 1;
			if (format[i] == '0')
				if (init->zero == 0)
					init->zero = 1;
			i++;
		}
	if (ft_isdigit(format[i]))
		ft_width(init, format, i);
	while (ft_isdigit(format[i]))
		i++;
	init->index = i;
	ft_conversion(init, format, i);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	tab	*init;

	init = malloc(sizeof(tab));
	if (init == NULL)
		return (-1);
	ft_init(init);
	va_start(init->args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_flags(init, format, i);
			i = init->index - 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(init->args);
	free(init);
	return (len);
}

int	main(void)
{
	char	c;
	char	*str = "Coucou ! Comment ça va ??? :o)";
	int	d;
	int	x;
	int	len;

	c = 'L';
	d = -123456789;
	x = 2147000000;
	len = 0;

	printf("***printf c : %c\n", c);
	len = ft_printf("ft_printf c : %c\n", c);
	printf("Valeur de len : %d\n\n", len);
	printf("\n**********************************************************************************\n");
	printf("*    ***printf s : %-.5s\n", str);
	len = ft_printf("*    ft_printf s : %.25s\n", str);
	printf("*    Valeur de len : %d\n", len);
	printf("*\n**********************************************************************************\n");

	printf("\n\n***printf p : %p\n", &c);
	len = ft_printf("ft_printf p : %p\n", &c);
	printf("Valeur de len : %d\n\n", len);
	printf("\n**********************************************************************************\n");
	printf("***printf d : %.17d - ***printf i : %.17i\n", d, d);
	len = ft_printf("ft_printf d : %.17d - ft_printf i : %.17i\n", d, d);
//	printf("Valeur de len : %d\n\n", len);
	printf("\n**********************************************************************************\n");
	printf("\n\n***printf x : %x _ ***printf X : %X\n", x, x);
	len = ft_printf("ft_printf x : %x - ft_printf X : %X\n\n", x, x);
	printf("Valeur de len : %d\n", len);

	return (0);
}
