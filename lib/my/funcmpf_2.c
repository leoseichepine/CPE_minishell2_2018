/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int print_ptr(va_list arg)
{
    int nbchar = 0;

    my_putstr("0x");
    nbchar = convert_dec_to_hexa_lc(va_arg(arg, unsigned long));
    return (nbchar);
}

int print_char(va_list arg)
{
    my_putchar((char)va_arg(arg, int));
    return (1);
}

int print_str(va_list arg)
{
    int nbchar = 0;

    nbchar = my_putstr(va_arg(arg, char *));
    return (nbchar);
}

int print_str_oct(va_list arg)
{
    int nbchar = 0;

    nbchar = my_putstr_oct(va_arg(arg, char *));
    return (nbchar);
}
