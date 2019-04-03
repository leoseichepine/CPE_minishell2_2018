/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int my_cd(mysh_t *sh)
{
    if (sh->input->arr[1] == NULL) {
        if (chdir(sh->info->path->root) == -1)
            return (84);
    } else if (sh->input->argnb > 2) {
        my_printf("Too many arguments\n");
        return (84);
    } else
        if (chdir(sh->input->arr[1]) == -1) {
            my_printf("%s: No such file or directory\n", sh->input->arr[1]);
            return (84);
        }
    return (0);
}
