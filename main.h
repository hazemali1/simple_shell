#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include"structures.h"

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

void structure_free(data_shell *datash);
void set_data(data_shell *datash, char **av);
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *node_addition(r_var **head, int lvar, char *var, int lval);
void free_em(r_var **head);
char *combine(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int compare_str(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
void blockCopy(void *newptr, const void *ptr, unsigned int size);
void *resizeMemory(void *ptr, unsigned int old_size, unsigned int new_size);
char **dynamicResizeDP(char **ptr,
		unsigned int old_size, unsigned int new_size);
char *stringDuplicat(const char *s);
int getStringLength(const char *s);
int compareCharacters(char str[], const char *delim);
char *stringTokenize(char str[], const char *delim);
int isStringDigit(const char *s);
void rev_string(char *s);
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);
char *without_comment(char *in);
void shell_loop(data_shell *datash);
char *read_line(int *i_eof);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int exec_line(data_shell *datash);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);
int cd_shell(data_shell *datash);
int (*get_builtin(char *cmd))(data_shell *datash);
int exit_shell(data_shell *datash);
int getNumberLength(int n);
char *convertIntToString(int n);
int convertStringToInt(char *s);
char *strcat_cd(data_shell *, char *, char *, char *);
char *display_cd_error(data_shell *datash);
char *not_found(data_shell *datash);
char *shell_exit(data_shell *datash);
char *error_get_alias(char **args);
char *handle_error(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);
int get_error(data_shell *datash, int eval);
void get_sigint(int sig);
void helper3_env(void);
void helper3_setenv(void);
void helper3_unsetenv(void);
void helper3_general(void);
void helper3_exit(void);
void helper3(void);
void helper2(void);
void helper1(void);
int get_help(data_shell *datash);

#endif
