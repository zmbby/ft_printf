#include "ft_printf.h"

void	ft_print_hex_V2(unsigned int a, int **count)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (a >= 16)
	{
		ft_print_hex_V2(a / 16, count);
		a = a % 16;
	}
	(**count)++;
	ft_putchar(base_hex[a]);
}

void	ft_print_hex_V3(unsigned int a, int **count)
{
	char	*base_hex;

	base_hex = "0123456789ABCDEF";
	if (a >= 16)
	{
		ft_print_hex_V3(a / 16, count);
		a = a % 16;
	}
	(**count)++;
	ft_putchar(base_hex[a]);
}

void	write_format(const char *format, va_list arg, int *count)
{
	format++;
	if (*format == 'c')
		write_character(va_arg(arg, int), &count);
	else if (*format == 'd')
		write_decimale(va_arg(arg, int), &count);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), &count);
	else if (*format == 'u')
		write_UNS_decimal(va_arg(arg, unsigned int), &count);
	else if (*format == '%')
	{
		(*count)++;
		write(1, "%", 1);
	}
	else if (*format == 'i')
		write_int(va_arg(arg, int), &count);
	else if (*format == 'p')
		write_hexa_add(va_arg(arg, void *), &count);
	else if (*format == 'x')
		ft_print_hex_V2(va_arg(arg, unsigned int), &count);
	else if (*format == 'X')
		ft_print_hex_V3(va_arg(arg, unsigned int), &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if ((init_format(format)))
		{
			write_format(format, arg, &count);
			format++;
		}
		else
		{
			count++;
			ft_putchar_2(format);
		}
		format++;
	}
	va_end(arg);
	return (count);
}

// // int main()
// // {

// //     // unsigned int p = 4294967295;
// //     int count = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
// 		%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%",
// 		'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C',
// 		"0", 0, 0 ,0 ,0, 42, 0);
// //     write(1, "\n", 1);
// //     int count2 = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
// 		%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%",
// 		'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C',
// 		"0", 0, 0 ,0 ,0, 42, 0);
// //     printf("\ndyali => %d\ndyalhom => %d", count, count2);
// //     return (0);
// // }