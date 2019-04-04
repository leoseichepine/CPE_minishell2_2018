/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int choose_function(int i, va_list arg)
{
    int nbrchar = 0;
    fctptr_t ptrarr[12] = { &print_int, &print_deci,
                            &print_unsigned_int, &print_pct,
                            &print_ptr, &print_char,
                            &print_str, &print_str_oct,
                            &print_octal, &print_hexa_uc,
                            &print_hexa_lc,
                            &print_binary };

    nbrchar = nbrchar + ptrarr[i](arg);
    return (nbrchar);
}

int compare_flag(char flag, va_list arg)
{
    char chararr[12] = {'i', 'd', 'u', '%', 'p', 'c',
                        's', 'S', 'o', 'X', 'x','b'};
    int nbrchar = 0;

    for (int i = 0; i < 12; i++) {
        if (chararr[i] == flag)
            nbrchar = nbrchar + choose_function(i, arg);
    }
    return (nbrchar);
}

int my_printf(char const *format, ...)
{
    va_list arg;
    int nbrchar = 0;
    char flag;

    va_start(arg, format);
    while (*format != '\0') {
        if (*format != '%') {
            my_putchar(*format);
            nbrchar++;
        }
        if (*format == '%') {
            format++;
            nbrchar = nbrchar + compare_flag(*format, arg);
        }
        format++;
    }
    va_end(arg);
    return (nbrchar);
}
