#include "ft_printf.h"

int	ft_width(tab *init, const char *format, int i)
{
	int	len;
	char	*str;

	len = 0;
	while (ft_isdigit(format[i]))
	{
		i++;
		len++;
	}
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);
	while (len > 0)
	{
		str[len - 1] = format[i - 1];
		len--;
		i--;
	}
	while (str[len])
		len++;
	init->width = ft_atoi(str);
	free(str);
	return (init->width);
}
