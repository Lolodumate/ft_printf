#include "ft_printf.h"

int	ft_print_str(tab *init)
{
	char	*str;
	int	len;
	int	i;

	str = malloc(sizeof(va_arg(init->args, char *)));
	if (str == NULL)
		return (-1);
	str = va_arg(init->args, char *);
	len = (int)ft_strlen(str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}
