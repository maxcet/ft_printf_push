#include "ft_printf.h"

void	ft_print_char(va_list args, int *b_symbl, int *index)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*b_symbl)++;
	(*index)++;
}

void	ft_printf_string(va_list args, int *b_symbl, int *index)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)\0";
	len = ft_strlen(str);
	write(1, str, len);
	*b_symbl = (*b_symbl) + len;
	(*index)++;
}

void	ft_print_pointer(va_list args, int *b_symbl, int *index)
{
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	write(1, "0x", 2);
	(*b_symbl) = (*b_symbl) + 2;
	ft_putnbr_ptr_x(p, b_symbl);
	(*index)++;
}
