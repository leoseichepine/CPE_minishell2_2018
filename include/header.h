/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#ifndef HEADER_SH2_
    #define HEADER_SH2_

int my_exit(mysh_t *sh);
int add_set_env(env_t **env_copy, char *name, char *value);
char **load_env_arr(mysh_t *sh);
char **get_real_path(env_t **env_copy);
char *get_word(char *str, char delim, int nb, int len);
int is_alphanum(char c);
int is_alphanum_str(char *str);
int print_err(char *err);
int my_redirect_exec(mysh_t *sh);
char *get_curr_path(void);
int my_env(mysh_t *sh);
int my_cd(mysh_t *sh);
int my_setenv(mysh_t *sh);
int delete_env_node(env_t **list, char *name);
int my_unsetenv(mysh_t *sh);
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
