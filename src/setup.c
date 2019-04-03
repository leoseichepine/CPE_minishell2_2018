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
    free(sh->info->path);
    free(sh->info);
    free(sh);
    return (0);
}

char *get_path(void)
{
    char path[1024];

    getcwd(path, sizeof(path));
    return (my_strdup(path));
}

mysh_t *init_struct(char **envp)
{
    mysh_t *sh = malloc(sizeof(mysh_t));

    if (!sh)
        return (NULL);
    sh->info = malloc(sizeof(info_sh_t));
    if (!sh->info)
        return (NULL);
    sh->info->path = malloc(sizeof(path_t));
    sh->info->path->root = get_path();
    if (!sh->info->path || !sh->info->path->root)
        return (NULL);
    sh->env = NULL;
    copy_env(&sh->env, envp);
    sh->input = malloc(sizeof(input_t));
    sh->input->cmd = NULL;
    if (!sh->input)
        return (NULL);
    sh->info->state = 1;
    return (sh);
}
