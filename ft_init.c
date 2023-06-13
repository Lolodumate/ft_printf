#include "ft_printf.h"

tab	*ft_init(tab *init)
{
	init->index = 0;
	init->width = 0;
	init->width_arg = 0;
	init->precision = 0;
	init->lenght = 0;
	init->zero = 0;
	init->pointer = 0;
	init->dash = 0;
	init->sign = 0;
	init->is_zero = 0;
	init->percent = 0;
	init->space = 0;
	init->is_negative = 0;
	return (init);
}
