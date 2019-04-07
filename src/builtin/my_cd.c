/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int change_dir(mysh_t *sh, char *path)
{
    if (chdir(path) == -1) {
        my_printf("%s: %s.\n", path, strerror(errno));
        return (0);
    }
    free(sh->info->path->prev);
    sh->info->path->prev = my_strdup(sh->info->path->curr);
    if (!sh->info->path->prev)
        return (0);
    free(sh->info->path->curr);
    sh->info->path->curr = get_curr_path();
    if (!sh->info->path->curr)
        return (0);
    add_set_env(&sh->env, "PWD", sh->info->path->curr);
    add_set_env(&sh->env, "OLDPWD", sh->info->path->prev);
    return (1);
}

int my_cd(mysh_t *sh)
{
    if (sh->input->arr[1] == NULL) {
        return (change_dir(sh, sh->info->path->root));
    } else if (sh->input->argnb > 2) {
        print_err("Too many arguments\n");
    } else
        return (change_dir(sh, sh->input->arr[1]));
    return (0);
}
