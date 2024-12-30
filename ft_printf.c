#include "ft_printf.h"

int init_format(const char *format)
{
    if (*format == '%')
        return (1);
    return (0);
}

int write_character(char c)
{
    return (write(1, &c, 1));
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
        write(1, "-", 1);
        nbr *= -1;
    }
    if (nbr > 9)
    {
        write_decimale(nbr / 10, count);
        nbr = nbr % 10;
    }
    **count += 1;
    ft_putchar(nbr + 48);
}

void    ft_putstr(char *str, int **count)
{
    while()
}

void    write_format(const char *format, va_list arg, int *count)
{
    format++;
    if (*format == 'c')
        *count += write_character(va_arg(arg, int));
    else if (*format == 'd')
        write_decimale(va_arg(arg, int), &count);
    else if (*format == 's')
        ft_putstr(va_arg(arg, char *), &count);
}

void    ft_putchar_2(const char *format)
{
    write(1, &*format, 1);
}

int ft_printf(const char *format, ...)
{
    va_list arg;
    int count;

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
    return (count);
}

int main()
{
    int count = ft_printf("%d %c", 97, 97);
    write(1, "\n", 1);
    int count2 = printf("%d %c", 97, 97);
    printf("\ndyali => %d\ndyalhom => %d", count, count2);
    return 0;
}