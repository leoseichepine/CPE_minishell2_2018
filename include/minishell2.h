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
    char *current;
    char *prev;
} path_t;

typedef struct s_info_sh
{
    int state;
    path_t *path;
} info_sh_t;

typedef struct s_cmd
{
    int argnb;
    char **arr;
    struct s_input *next;
} cmd_t;

typedef struct s_input
{
    int cmd_nb;
    cmd_t *cmd;
} input_t;

typedef struct s_mysh
{
    info_sh_t *info;
    input_t *input;
    env_t *env;
} mysh_t;

typedef int(*builtin_t)(mysh_t *sh);

    #endif //MINISHELL_1_H_
