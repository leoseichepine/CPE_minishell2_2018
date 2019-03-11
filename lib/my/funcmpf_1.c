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

int print_int(va_list arg)
{
    int nbchar = 0;

    nbchar = my_putnbr(va_arg(arg, int));
    return (nbchar);
}

int print_deci(va_list arg)
{
    int nbchar = 0;

    nbchar = convert_base(va_arg(arg, int), 10);
    return (nbchar);
}

int print_unsigned_int(va_list arg)
{
    int nbchar = 0;

    nbchar = my_put_unsigned_int(va_arg(arg, int));
    return (nbchar);
}

int print_pct(va_list arg)
{
    my_putchar('%');
    return (1);
}
