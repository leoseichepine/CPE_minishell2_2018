/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int free_struct(mysh_t *sh)
{
    free_env(&sh->env);
    free(sh->info->path);
    free(sh->info);
    free(sh);
    return (0);
}

mysh_t *init_struct(char **envp)
{
    mysh_t *sh = malloc(sizeof(mysh_t));
    char path[1024];

    sh->info = malloc(sizeof(info_t));
    getcwd(path, sizeof(path));
    sh->info->path = my_strdup(path);
    sh->env = NULL;
    copy_env(&sh->env, envp);
    sh->input = NULL;
    sh->info->state = 1;
    return (sh);
}
