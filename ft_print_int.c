#include "ft_printf.h"

static void	ft_padding(tab *init, char *str)
{
	int	i;
	char	c; 

	i = 0;
	if (init->zero != 0)
		c = '0';
	else
		c = 'X';
	while (str[i])
	{
		str[i] = c;
		i++;
	}
//	printf("\nTaille de str dans ft_padding : %ld\n", ft_strlen(str));
}

static void	ft_fillstr(tab *init, char *str, int n, int len_n)
{
	int	i;
	int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
		nb *= -1;
	ft_padding(init, str);
//	printf("\nValeur de len_n dans ft_fillstr : %d\n", len_n);
//	printf("\nValeur de ft_strlen(str) dans ft_fillstr : %ld\n", ft_strlen(str));
//	printf("\n%s\n", str);
	if (n >= 0 && init->sign != 0 && init->zero != 0)
		str[0] = '+';
	else if (n < 0 && init->zero != 0)
		str[0] = '-';
	if (str[0] == '+' || str[0] == '-')
		i++;
//	printf("\nValeur de init->width : %d\n", init->width);
//	printf("\nValeur de len_n : %d\n", len_n);
	while (len_n-- > 0 && nb > 0)
	{
		str[len_n] = (nb % 10) + '0';
//		printf("Valeur de nb : %d\n", nb);
		nb /= 10;
	}
	if (init->zero == 0 && n >= 0 && init->sign != 0)
		str[len_n] = '+';
	else if (n < 0)
		str[len_n] = '-';
}

int	ft_print_int(tab *init)
{
	int	i;
	int	n;
	int	len_n;
	char	*str;

	i = 0;
	n = va_arg(init->args, int);
	len_n = ft_intlen(n);
//	printf("\nValeur de len_n : %d\n", len_n);
	if (init->width > len_n)
		len_n = init->width;
//	printf("\nValeur de len_n : %d\n", len_n); // Verif faite : len_n vaut bien 18/19
	str = malloc(sizeof(char) * len_n);
	if (str == NULL)
		return (-1);
	// Problème à ce stade du programme : taille de str de 9 au lieu de 18/19.
//	printf("Taille de str AVANT ft_itoa : %ld\n", ft_strlen(str));
	str = ft_itoa(n);
	while (i < len_n)
	{
		str[i] = '0';
		i++;
	}
//	printf("Taille de str APRES ft_itoa : %ld\n", ft_strlen(str));
	ft_fillstr(init, str, n, len_n);
	ft_putstr(str);
	free(str);
	return (len_n);
}
