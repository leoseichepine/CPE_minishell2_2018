/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#ifndef HEADER_SH2_
    #define HEADER_SH2_

int my_exit(mysh_t *sh);
int my_env(mysh_t *sh);
int my_strcmp(char *str1, char *str2);
char *clean_input(char *input);
void free_arr(char **arr);
int get_input(mysh_t *sh);
int skip_spaces(char *str, int i);
int is_empty_str(char *str);
int count_aft(char *str);
int count_bef(char *str);
char *my_strdup_clean(char *str);
int get_word_len(char *str, int nb);
char *get_next_word(char *str, int nb, int len);
int count_word(char *str);

void reset_input(char **arr, char *s);
int error_input(mysh_t *sh, int read);

void signal_c(int sig);

int free_env(env_t **liste);
int add_env_elem(env_t **head, char *name, char *value);
int copy_env(env_t **list, char **envp);
char *my_str_before_tok(char *str, char tok);
char *my_str_after_tok(char *str, char tok);

mysh_t *init_struct(char **envp);
int free_struct(mysh_t *sh);

    #endif //HEADER_SH2_
