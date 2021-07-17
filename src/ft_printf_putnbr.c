#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *b_symbl)
{
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		(*b_symbl)++;
	}
	else
	{
		ft_putnbr(n / 10, b_symbl);
		ft_putnbr(n % 10, b_symbl);
	}
}

void	ft_putnbr_x(unsigned int n, int *b_symbl)
{
	if (n > 15)
		ft_putnbr_x ((n / 16), b_symbl);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*b_symbl = ft_putchar((n % 16 + 48), b_symbl);
	if ((n % 16) == 10)
		*b_symbl = ft_putchar('a', b_symbl);
	if ((n % 16) == 11)
		*b_symbl = ft_putchar('b', b_symbl);
	if ((n % 16) == 12)
		*b_symbl = ft_putchar('c', b_symbl);
	if ((n % 16) == 13)
		*b_symbl = ft_putchar('d', b_symbl);
	if ((n % 16) == 14)
		*b_symbl = ft_putchar('e', b_symbl);
	if ((n % 16) == 15)
		*b_symbl = ft_putchar('f', b_symbl);
}

void	ft_putnbr_xx(unsigned int n, int *b_symbl)
{
	if (n > 15)
		ft_putnbr_xx ((n / 16), b_symbl);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*b_symbl = ft_putchar(((n % 16) + 48), b_symbl);
	if ((n % 16) == 10)
		*b_symbl = ft_putchar('A', b_symbl);
	if ((n % 16) == 11)
		*b_symbl = ft_putchar('B', b_symbl);
	if ((n % 16) == 12)
		*b_symbl = ft_putchar('C', b_symbl);
	if ((n % 16) == 13)
		*b_symbl = ft_putchar('D', b_symbl);
	if ((n % 16) == 14)
		*b_symbl = ft_putchar('E', b_symbl);
	if ((n % 16) == 15)
		*b_symbl = ft_putchar('F', b_symbl);
}

void	ft_putnbr(int n, int *b_symbl)
{
	char	minus;

	minus = '-';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*b_symbl) += 11;
	}
	else if (n >= 0 && n <= 9)
		*b_symbl = ft_putchar((n + 48), b_symbl);
	else if (n > 9)
	{
		ft_putnbr(n / 10, b_symbl);
		ft_putnbr(n % 10, b_symbl);
	}
	else
	{
		n = -n;
		write(1, &minus, 1);
		ft_putnbr(n, b_symbl);
		(*b_symbl)++;
	}
}

void	ft_putnbr_ptr_x(unsigned long n, int *b_symbl)
{
	if (n > 15)
		ft_putnbr_ptr_x ((n / 16), b_symbl);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*b_symbl = ft_putchar((n % 16 + 48), b_symbl);
	if ((n % 16) == 10)
		*b_symbl = ft_putchar('a', b_symbl);
	if ((n % 16) == 11)
		*b_symbl = ft_putchar('b', b_symbl);
	if ((n % 16) == 12)
		*b_symbl = ft_putchar('c', b_symbl);
	if ((n % 16) == 13)
		*b_symbl = ft_putchar('d', b_symbl);
	if ((n % 16) == 14)
		*b_symbl = ft_putchar('e', b_symbl);
	if ((n % 16) == 15)
		*b_symbl = ft_putchar('f', b_symbl);
}
