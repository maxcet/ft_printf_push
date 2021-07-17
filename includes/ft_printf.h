#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_print_char(va_list args, int *bytes, int *index);
void	ft_printf_string(va_list args, int *bytes, int *index);
void	ft_print_pointer(va_list args, int *bytes, int *index);
void	ft_print_iteger_dec(va_list args, int *bytes, int *index);
void	ft_print_unsigned_dec(va_list args, int *bytes, int *index);
void	ft_print_hexadecimal(va_list args, int *bytes, int *index);
void	ft_print_hexadecimal_p(va_list args, int *bytes, int *index);
void	ft_putnbr_u(unsigned int n, int *bytes);
void	ft_putnbr_x(unsigned int n, int *bytes);
void	ft_putnbr_ptr_x(unsigned long n, int *bytes);
void	ft_putnbr_xx(unsigned int n, int *bytes);
void	ft_putnbr(int n, int *bytes);
void	ft_index_swap(int *index, int *bytes);

int		ft_printf(const char *format, ...);
int		ft_putchar(char c, int *bytes);
int		ft_strlen(const char *s1);
int		*ft_print_arg(int *bytes, int *index, va_list args, const char *format);
int		ft_define_format(char c);

int		*ft_print_per(const char *format, int *index, int *b_symbl);

#endif
