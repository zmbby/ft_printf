#include "ft_printf.h"

int init_format(const char *format)
{
    if (*format == '%')
        return (1);
    return (0);
}

void    write_character(char c, int **count)
{
    (**count) += write(1, &c, 1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void write_decimale(int i, int **count)
{
    long nbr;

    nbr = i;
    if (nbr < 0)
    {
        (**count)++;
        write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr > 9)
    {
        write_decimale(nbr / 10, count);
        nbr = nbr % 10;
    }
    (**count)++;
    ft_putchar(nbr + 48);
}

void    ft_putchar_2(const char *format)
{
    write(1, &*format, 1);
}

void    ft_putstr(char *str, int **count)
{
    if (!str)
        (**count) += write(1, "(null)", 6);
    else
        while(*str)
            **count += write(1, &(*str++), 1);
}

void    write_UNS_decimal(unsigned int nbr, int **count)
{
    if (nbr > 9)
    {
        write_UNS_decimal(nbr / 10, count);
        nbr = nbr % 10;
    }
    (**count)++;
    ft_putchar(nbr + 48);
}

void    write_int(int i, int **count)
{
    long nbr;

    nbr = i;
    if (nbr < 0)
    {
        (**count)++;
        write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr > 9)
    {
        write_int(nbr / 10, count);
        nbr = nbr % 10;
    }
    (**count)++;
    ft_putchar(nbr + 48);
}

void	ft_print_hex(unsigned long a, int ***count)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (a >= 16)
	{
		ft_print_hex(a / 16, count);
        a = a % 16;
	}
    (***count)++;
    ft_putchar(base_hex[a]);
}

void    write_hexa_add(void *ptr, int **count)
{
    unsigned long add = (unsigned long)ptr;
    if (add == 0)
        (**count) += write(1, "(nil)", 5);
    else
    { 
        (**count) += 2;
        write(1, "0x", 2);
        ft_print_hex(add, &count);
    }
}