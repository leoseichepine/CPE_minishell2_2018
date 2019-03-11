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

int print_octal(va_list arg)
{
    int nbchar = 0;

    nbchar = convert_base(va_arg(arg, int), 8);
    return (nbchar);
}

int print_hexa_uc(va_list arg)
{
    int nbchar = 0;

    nbchar = convert_dec_to_hexa_lc(va_arg(arg, int));
    return (nbchar);
}

int print_hexa_lc(va_list arg)
{
    int nbchar = 0;

    nbchar = convert_dec_to_hexa_lc(va_arg(arg, int));
    return (nbchar);
}

int print_binary(va_list arg)
{
    int nbchar = 0;

    nbchar = convert_base(va_arg(arg, int), 2);
    return (nbchar);
}
