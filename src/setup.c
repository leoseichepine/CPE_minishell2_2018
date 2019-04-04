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
    free(sh->input);
    free(sh->info->path->root);
    free(sh->info->path->curr);
    free(sh->info->path->prev);
    free(sh->info->path);
    free(sh->info);
    free(sh);
    return (0);
}

char *get_curr_path(void)
{
    char path[1024];

    getcwd(path, sizeof(path));
    return (my_strdup(path));
}

int init_path(mysh_t *sh)
{
    sh->info->path = malloc(sizeof(path_t));
    sh->info->path->root = get_curr_path();
    sh->info->path->curr = get_curr_path();
    sh->info->path->prev = NULL;
    if (!sh->info->path || !sh->info->path->root || !sh->info->path->curr)
        return (0);
    return (1);
}

mysh_t *init_struct(char **envp)
{
    mysh_t *sh = malloc(sizeof(mysh_t));

    if (!sh)
        return (NULL);
    sh->info = malloc(sizeof(info_sh_t));
    if (!sh->info)
        return (NULL);
    if (!init_path(sh))
        return (NULL);
    sh->env = NULL;
    copy_env(&sh->env, envp);
    sh->input = malloc(sizeof(input_t));
    sh->input->arr = NULL;
    sh->input->argnb = 0;
    if (!sh->input)
        return (NULL);
    return (sh);
}
