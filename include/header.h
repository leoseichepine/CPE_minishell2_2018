/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#ifndef HEADER_SH2_
    #define HEADER_SH2_

void reset_input(input_t *input);

void signal_c(int sig);

int free_env(env_t **liste);
int add_env_elem(env_t **head, char *name, char *value);
int copy_env(env_t **list, char **envp);
char *my_str_before_tok(char *str, char tok);
char *my_str_after_tok(char *str, char tok);

mysh_t *init_struct(char **envp);
int free_struct(mysh_t *sh);

    #endif //HEADER_SH2_
