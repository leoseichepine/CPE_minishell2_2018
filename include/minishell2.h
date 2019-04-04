/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MINISHELL_1_H_
    #define MINISHELL_1_H_

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

enum
{
    FALSE,
    TRUE
};

typedef struct s_list
{
    char *name;
    char *value;
    struct s_list *next;
}env_t;

typedef struct s_path
{
    char *root;
    char *curr;
    char *prev;
} path_t;

typedef struct s_info_sh
{
    int state;
    path_t *path;
} info_sh_t;

typedef struct s_input
{
    int argnb;
    char **arr;
} input_t;

typedef struct s_mysh
{
    info_sh_t *info;
    input_t *input;
    env_t *env;
} mysh_t;

typedef int(*builtin_t)(mysh_t *sh);

    #endif //MINISHELL_1_H_
