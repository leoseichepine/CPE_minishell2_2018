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

typedef struct s_infos
{
    int state;
    path_t *path;
} info_t;

typedef struct s_input
{
    int argnb;
    char **arr;
} input_t;

typedef struct s_mysh
{
    info_t *info;
    input_t *input;
    env_t *env;
} mysh_t;

    #endif //MINISHELL_1_H_
