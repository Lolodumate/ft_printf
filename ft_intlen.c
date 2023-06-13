#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	 len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
