/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

void signal_c(int sig)
{
    sig += 0;
    my_printf("\n$>");
    return ;
}
