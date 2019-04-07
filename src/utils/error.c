/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int print_err(char *err)
{
    my_putstr(err);
    my_putchar('\n');
    return (0);
}

int error_input(mysh_t *sh, int read)
{
    if (read < 0) {
        if (sh->info->tty)
            my_putstr("exit\n");
        sh->info->state = 0;
        return (84);
    }
    return (0);
}
