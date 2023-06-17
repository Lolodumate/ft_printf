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
		else if (format[i] == 's') // char *
			len += ft_print_str(init);
		else if (format[i] == 'p') // unsigned long
			len += ft_print_ptr(init);
		else if (format[i] == 'd' || format[i] == 'i') // int
			len += ft_print_int(init);
		else if (format[i] == 'u') // unsigned int
			len += ft_print_uint(init);
		else if (format[i] == 'x' || format[i] == 'X') // unsigned int
			len += ft_print_hexa(init, format, i);
		else if (format[i] == '%' && format[i - 1] == '%')
			len += ft_print_percent();
		i++;
		init->index = i;
	}
	return (len);
}

int	ft_flags(tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	// %[flags][width][.precision]specifier
	if (!ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == '-')
		{
			ft_dash(init, format, i);
			i++;
		}
		while (ft_strchr("+ #0*", format[i]))
		{
			if (format[i] == '+')
				init->sign = 1;
			if (format[i] == ' ')
				init->space = 1;
			if (format[i] == '#')
				init->hashtag = 1;
			if (format[i] == '0')
				init->zero = 1;
			i++;
		}
		if (format[i] == '.')
			i = ft_precision(init, format, i);
		if (ft_isdigit(format[i]))
			ft_width(init, format, i);
		while (ft_isdigit(format[i]))
			i++;
		init->index = i;
	}
	len = ft_conversion(init, format, i);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len_args;
	tab	*init;

	init = malloc(sizeof(tab));
	if (init == NULL)
		return (-1);
	ft_init(init);
	va_start(init->args, format);
	i = 0;
	len_args = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len_args += ft_flags(init, format, i);
			i = init->index - 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(init->args);
	free(init);
//	printf("Valeur de ft_len_ft_printf(format) : %d\n", ft_len_ft_printf(format));
	return (ft_len_ft_printf(format) + len_args);
}
/*
int	main(void)
{

	printf("Valeur de ***printf c : %d\n", printf("%c", '0'));
	ft_printf("Valeur de ft_printf c : %d\n", ft_printf("%c", '0'));
	ft_putchar('\n');
	printf(" %c ", '0');
	ft_printf(" %c ", '0');
	ft_putchar('\n');
	printf("Valeur de ***printf c : %d\n", printf(" %cEND", '0' - 256));
	printf("Valeur de ft_printf c : %d\n", ft_printf(" %cEND", '0' - 256));
	ft_putchar('\n');
	printf("Valeur de ***printf c : %d\n", printf("%c ", '0' + 256));
	printf("Valeur de ft_printf c : %d\n", ft_printf("%c ", '0' + 256));
	ft_putchar('\n');
	printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", '0', '0', '1');
	ft_putchar('\n');
	printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	ft_putchar('\n');
	printf(" %c %c %c ", '1', '2', '3');
	ft_printf(" %c %c %c ", '1', '2', '3');
	ft_putchar('\n');
	printf(" %c %c %c ", '2', '1', 0);
	ft_printf(" %c %c %c ", '2', '1', '0');
	ft_putchar('\n');
	printf(" %c %c %c ", 0, '1', '2');
	ft_printf(" %c %c %c ", '0', '1', '2');
*/

/*	char	c;
	char	*str = "Coucou ! Comment ça va ??? :o) XXXXXXXXXXXXXXXXXXXX";
	int	d;
	int	x;
	int	len_ft_printf;
	int	len_printf;
//	int	total_len_ft_printf;
//	int	total_len_printf;
	int	u_int;

	c = 'L';
	d = 12345;
	x = 2147000000;
	len_ft_printf = 0;
	len_printf = 0;
//	total_len_ft_printf = 0;
//	total_len_printf = 0;
	u_int = -10;
	printf("\n*********************************************************************************\n");
	printf("*    ***printf c : %c\n", c);
	ft_printf("*    ft_printf c : %c\n", c);
	ft_putchar('>');	
	len_printf = printf("%c", c);
	len_ft_printf = ft_printf("%c", c);
	printf("\n");
	printf("*    Valeur de ***len_printf : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf : %d\n*\n", len_ft_printf);
	printf("**********************************************************************************\n");
	printf("\n**********************************************************************************\n");
	printf("*    ***printf s : %.5s\n", str);
	ft_printf("*    ft_printf s : %.5s\n", str);
	ft_putchar('>');
	len_printf = printf("%s", str);
	len_ft_printf = ft_printf("%s", str);
	printf("\n");
	printf("*    Valeur de ***len_printf : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf : %d\n*\n", len_ft_printf);
	printf("**********************************************************************************\n");
	printf("\n**********************************************************************************\n");
	len_printf = printf("*    ***printf percent : %%\n");
	len_ft_printf = ft_printf("*    ft_printf percent : %%\n");
	printf("*    Valeur de ***len_printf : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf : %d\n", len_ft_printf);
	printf("*\n**********************************************************************************\n");
	printf("\n**********************************************************************************\n");
	len_printf = printf("*    ***printf p : %p\n", &c);
	len_ft_printf = ft_printf("*     ft_printf p : %p\n", &c);
	ft_putchar('>');
	len_printf = printf("%p", &c);
	len_ft_printf = ft_printf("%p", &c);
	printf("\n");
	printf("*    Valeur de ***len_printf : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf : %d\n*\n", len_ft_printf);
	printf("**********************************************************************************\n");
	printf("\n**********************************************************************************\n");
	printf("*    ***printf d .17d : %.17d - ***printf i : %.00000017i\n", d, d);
	ft_printf("*    ft_printf d .17d : %.17d - ft_printf i : %.00000017i\n", d, d);
	printf("\n");
	printf("*    ***printf d -17d : %-17d - ***printf i -17i : %-17i\n", d, d);	
	ft_printf("*    ft_printf d -17d : %-17d - ft_printf i -17i : %-17i\n", d, d);
	printf("\n");
	printf("*    ***printf d .5d : %.5d - ***printf i : %017i\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i : %017i\n", d, d);
	printf("\n");
	printf("*    ***printf d -5d : %-5d - ***printf i -5i : %-5i\n", d, d);
	ft_printf("*    ft_printf d -5d : %-5d - ***printf i -5i : %-5i\n", d, d);
	printf("\n");
	printf("*    ***printf d 17d : %17d - ***printf i .0i : %.0i\n", d, d);
	ft_printf("*    ft_printf d 17d : %17d - ft_printf i .0i : %.0i\n", d, d);
	printf("\n");
	printf("*    ***printf d 5d : %5d - ***printf i : %0i\n", d, d);
	ft_printf("*    ft_printf d 5d : %5d - ft_printf i : %0i\n", d, d);
	printf("\n");
	printf("*    ***printf d +17d : %+17d - ***printf i +17i : %+17i\n", d, d);
	ft_printf("*    ft_printf d +17d : %+17d - ft_printf i +17i : %+17i\n", d, d);
	printf("\n");
	printf("*    ***printf d .5d : %.5d - ***printf i 17i : %17i\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i 17i : %17i\n", d, d);
	ft_printf("*                              ft_printf i 17i : %17i\n", d);
	printf("*    ***printf d .5d : %.5d - ***printf i 017i : %017i\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i 017i : %017i\n", d, d);
	ft_printf("*                              ft_printf i 017i : %017i\n", d);
	printf("*    ***printf d .5d : %.5d - ***printf i .17d : %.17d\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i .17i : %.17i\n", d, d);
	printf("\n");
	printf("*    ***printf d .5d : %.5d - ***printf i .17i : %.17i\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i .17i : %.17i\n", d, d);	
	printf("\n");
	printf("*    ***printf d 017d : %017d - ***printf i .5i : %.5i\n", d, d);
	ft_printf("*    ft_printf d 017d : %017d - ft_printf i .5i : %.5i\n", d, d);
	printf("\n\n");
	printf("*    ***printf d .5d : %.5d - ***printf i 17i : %17i\n", d, d);
	ft_printf("*    ft_printf d .5d : %.5d - ft_printf i 17i : %17i\n", d, d);
	printf("*    ***printf d 17d : %17d - ***printf i .5i : %.5i\n", d, d);
	ft_printf("*    ft_printf d 17d : %17d - ft_printf i .5i : %.5i\n", d, d);
	printf("\n\n");
	printf("*    ***printf d 5d : %5d - ***printf i 017d : %017d\n", d, d);
	ft_printf("*    ft_printf d 5d : %.5d - ft_printf i 017i : %017i\n", d, d);
	printf("*    ***printf d 5d : %5d - ***printf i 5d : %5d\n", d, d);
	ft_printf("*    ft_printf d 5d : %5d - ft_printf i 5d : %5d\n", d, d);
	printf("\n");
	printf("*    ***printf d 017d : %017d - ***printf i 017i : %017i\n", d, d);
	ft_printf("*    ft_printf d 017d : %017d - ft_printf i 017i : %017i\n", d, d);
	printf("\n");
	printf("*    ***printf d 05d : %05d - ***printf i 05i : %05i\n", d, d);
	ft_printf("*    ft_printf d 05d : %05d - ft_printf i 05i : %05i\n", d, d);
	printf("\n");
	printf("*    ***printf d +5d : %+5d - ***printf i +5i : %+5i\n", d, d);
	ft_printf("*    ft_printf d +5d : %+5d - ft_printf i +5i : %+5i\n", d, d);
	printf("\n");
	printf("*    ***printf d .0d : %.d - ***printf i .0i : %.0i\n", d, d);
	ft_printf("*    ft_printf d .0d : %.0d - ft_printf i .0i : %.0i\n", d, d);
	printf("\n");
	printf("*    ***printf space d : % d - ***printf space i : % i\n", d, d);
	ft_printf("*    ft_printf space d : % d - ft_printf space i : % i\n", d, d);
	printf("\n");
	printf("*    ***printf d 5d : %5d - ***printf space 5d : % 5d\n", d, d);
	ft_printf("*    ft_printf d 5d : %5d - ft_printf space 5d : % 5d\n", d, d);
	printf("\n");
	printf("*    ***printf d -5d : %-5d - ***printf i -5i : %-5iEND\n", d, d);
	ft_printf("*    ft_printf d -5d : %-5d - ft_printf i -5i : %-5iEND\n", d, d);
	printf("\n");
	printf("*    ***printf d -17d : %-17d - ***printf i -17i : %-17iEND\n", d, d);
	ft_printf("*    ft_printf d -17d : %-17d - ft_printf i -17i : %-17iEND\n", d, d);
	printf("\n");
	printf("*    ***printf d -5d : %-5d - ***printf i 5i : %5iEND\n", d, d);
	ft_printf("*    ft_printf d -5d : %-5d - ft_printf i 5i : %5iEND\n", d, d);
	printf("\n");
	printf("*    ***printf d 5d : %5d - ***printf i -5i : %-5iEND\n", d, d);
	ft_printf("*    ft_printf d 5d : %5d - ft_printf i -5i : %-5iEND\n", d, d);
	printf("\n");
	printf("*    ***printf d 17d : %17d - ***printf d -17d : %-17dEND\n", d, d);
	ft_printf("*    ft_printf d 17d : %17d - ft_printf d -17d : %-17dEND\n", d, d);
	printf("\n");
	printf("*    ***printf d -.17d : %-.17dEND\n", d);
	ft_printf("*    ft_printf d -.17d : %-.17dEND\n", d);
	printf("\n");
	printf("*    ***printf d -.5d : %-.5dEND\n", d);
	ft_printf("*    ft_printf d -.5d : %-.5dEND\n", d);
	printf("\n");
	printf("*    ***printf d -17d : %-17dEND\n", d);
	ft_printf("*    ft_printf d -17d : %-17dEND\n", d);
	printf("\n");
	printf("*    ***printf d -5d : %-5dEND\n", d);
	ft_printf("*    ft_printf d -5d : %-5dEND\n", d);
	printf("\n");
	printf("*    ***printf d .17d : %.17dEND\n", d);
	ft_printf("*    ft_printf d .17d : %.17dEND\n\n", d);
	printf("\n");
	printf("*    ***printf d : %d - ***printf i : %i\n", d, d);
	ft_printf("*    ft_printf d : %d - ft_printf : %i\n", d, d);
	ft_putchar('>');
	len_printf = printf("%d%i", d, d);
	len_ft_printf = ft_printf("%d%i", d, d);
	printf("\n");
	printf("*    Valeur de ***len_printf : %d\n", len_printf);
	ft_printf("*    Valeur de len_ft_printf : %d\n*\n", len_ft_printf);
	printf("\n**********************************************************************************\n");
	printf("\n*    ***printf #x : %#x - ***printf #X : %#X\n", x, x);
	ft_printf("*    ft_printf #x : %#x - ft_printf #X : %#X\n*\n", x, x);
	ft_putchar('>');
	len_printf = printf("%#x", x);
	len_ft_printf = ft_printf("%#x", x);
	printf("\n");
	printf("*    Valeur de ***len_printf x : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf x : %d\n", len_ft_printf);
	printf("\n");
	ft_putchar('>');
	len_printf = printf("%#X", x);
	len_ft_printf = ft_printf("%#X", x);
	printf("\n");
	printf("*    Valeur de ***len_printf X : %d\n", len_printf);
	printf("*    Valeur de len_ft_printf X : %d\n", len_ft_printf);
	printf("\n**********************************************************************************\n");
	printf("*    ***printf u : %u\n", u_int);
	ft_printf("*    ft_printf u : %u\n", u_int);
	printf("\n");
	printf("*    ***printf u - 1 : %u\n", u_int - 1);
	ft_printf("*    ft_printf u - 1 : %u\n", u_int - 1);
	while (u_int < 10)
	{
		printf("\n-------------------------------------------------------\n");
		ft_putchar('>');
		len_printf = printf("%u", u_int);
		len_ft_printf = ft_printf("%u", u_int);
		printf("\n");
		printf("*    Valeur de ***len_printf : %d\n", len_printf);
		ft_printf("*    Valeur de len_ft_printf : %d\n", len_ft_printf);
		printf("\n-------------------------------------------------------");
		u_int++;
	}
	printf("*\n**********************************************************************************\n\n");
	printf("*\n*    ***printf p : %p\n", &c);
	ft_printf("*    ft_printf p : %p\n\n", &c);
	ft_putchar('>');
	len_printf = printf("%p", &c);
	len_ft_printf = ft_printf("%p", &c);
	printf("\n");
	printf("*     Valeur de ***len_printf : %d\n", len_printf);
	printf("*     Valeur de len_ft_printf : %d\n", len_ft_printf);
	printf("*\n");
	return (0);
}*/
