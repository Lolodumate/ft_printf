#include "ft_printf.h"

int	ft_print_str(tab *init)
{
	char	*str;
	int	len;
	int	i;
	int	width;

	width = 0;
	if (init->width != 0)
		width = init->width;
	else if (init->width_arg != 0)
		width = va_arg(init->args, int);
	str = malloc(sizeof(va_arg(init->args, char *)));
	if (str == NULL)
		return (-1);
	str = va_arg(init->args, char *);
	len = (int)ft_strlen(str);
	i = 0;
	while (str[i] && width > 0)
	{
		write(1, &str[i], 1);
		i++;
		width--;
	}
	return (len);
}
