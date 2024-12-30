#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>


int     init_format(const char *format);
void    write_character(char c, int **count);
void    write_decimale(int i, int **count);
void    ft_putchar_2(const char *format);
void    ft_putstr(char *str, int **count);
void    ft_putchar(char c);
void    write_UNS_decimal(unsigned int nbr, int **count);
void    write_int(int i, int **count);


#endif