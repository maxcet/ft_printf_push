#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		b_symbl;
	int		index;

	index = 0;
	va_start(args, format);
	b_symbl = 0;
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			write(1, &format[index++], 1);
			b_symbl++;
		}
		else
		{
			if (ft_define_format(format[index + 1]) == 1)
				ft_print_arg(&b_symbl, &index, args, format);
			else
				index += 2;
		}
	}
	va_end(args);
	return (b_symbl);
}

int	ft_define_format(char c)
{
	int		i;
	char	*CONV;

	CONV = "cspdiuxX%";
	i = 0;
	while (CONV[i] != '\0')
	{
		if (c == CONV[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_print_arg(int *b_symbl, int *index, va_list args, const char *format)
{
	while (format[*index] == '%')
	{
		if (args == NULL)
			return (0);
		if (format[(*index) + 1] == 'd' || format[(*index) + 1] == 'i')
			ft_print_iteger_dec(args, b_symbl, index);
		else if (format[(*index) + 1] == 'c')
			ft_print_char(args, b_symbl, index);
		else if (format[(*index) + 1] == 's')
			ft_printf_string(args, b_symbl, index);
		else if (format[(*index) + 1] == 'u')
			ft_print_unsigned_dec(args, b_symbl, index);
		else if (format[(*index) + 1] == 'x')
			ft_print_hexadecimal(args, b_symbl, index);
		else if (format[(*index) + 1] == 'X')
			ft_print_hexadecimal_p(args, b_symbl, index);
		else if (format[(*index) + 1] == 'p')
			ft_print_pointer(args, b_symbl, index);
		else if (format[(*index) + 1] == '%')
			return (ft_print_per(format, index, b_symbl));
		(*index) += 1;
	}
	return (b_symbl);
}

int	*ft_print_per(const char *format, int *index, int *b_symbl)
{
	(*b_symbl)++;
	write(1, &format[(*index) + 1], 1);
	(*index) += 2;
	return (b_symbl);
}
