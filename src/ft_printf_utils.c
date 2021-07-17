#include "ft_printf.h"

int	ft_putchar(char c, int *b_symbl)
{
	write (1, &c, 1);
	*b_symbl = *b_symbl + 1;
	return (*b_symbl);
}

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}
