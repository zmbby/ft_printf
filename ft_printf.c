#include "ft_printf.h"

void    write_hexa_add(void *ptr, int **count)
{
    uintptr_t hexa_int;

    hexa_int = (uintptr_t)ptr;
    write (1, "0x", 2);
    while ()
}


void    write_format(const char *format, va_list arg, int *count)
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
    va_end(arg);
    return (count);
}

int main()
{
    int a = 5;
    int *p = &a;
    // int count = ft_printf("%i\n", 0x2A);
    // write(1, "\n", 1);
    // int count2 = 
    printf("%p\n", p);
    // printf("\ndyali => %d\ndyalhom => %d", count, count2);
    return 0;
}