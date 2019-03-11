/*
** EPITECH PROJECT, 2019
** PSU_my_exec_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MINISHELL_1_H_
#define MINISHELL_1_H_

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include "my.h"

typedef enum
{
    false,
    true
}bool_t;

typedef struct s_list
{
    char *name;
    char *value;
    struct s_list *next;
}env_t;

typedef struct s_mysh
{
    int state;
    int argnb;
    char *input;
    char **arr_input;
    char *root_path;
    env_t *env_copy;
}my_sh_t;

typedef int(*sh_fct_t)(my_sh_t *sh);

void signal_c(int signal);
int my_cd(my_sh_t *sh);
char *get_path(env_t **env_copy);
int get_path_size(char *path);
int get_path_len(char *path, int number);
char *get_next_path(char *path, int path_len, int number);
char **get_real_path(env_t **env_copy);
char **load_env_arr(my_sh_t *sh);
int my_exec(my_sh_t *sh);
char *my_strdup(char *str);
char *get_next_word(char *str, int word_len, int number);
int input_to_tab(my_sh_t *sh);
int skip_spaces_before(char *str, int i);
int compare_input(my_sh_t *sh);
int my_exit(my_sh_t *sh);
int my_env(my_sh_t *sh);
int error_input(my_sh_t *sh, int err_in);
void free_all_input(my_sh_t *sh);
void reset_input(my_sh_t *sh);
char *clean_env_name(char *name);
int free_word_array(char **arr);
int count_words(char *str);
int get_word_len(char *str, int number);
int my_unsetenv(my_sh_t *sh);
int my_get_env(env_t **liste, char *name, char *value);
int setenv_overwrite(env_t **list, char *name, char *value);
int my_setenv(my_sh_t *sh);
char *my_str_before_tok(char *str, char tok);
char *my_str_after_tok(char *str, char tok);
int copy_env(env_t **liste, char **envp);
int get_env_size(char **envp);
int add_env_name(env_t **liste, char *name);
int show_list(my_sh_t *sh);
int free_list(env_t **liste);
bool_t is_string_egal(char *str1, char *str2);
my_sh_t *create_struct(char **envp);

#endif //MINISHELL_1_H_
