#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * struct node - My struct
 *
 * @str: Parameter1
 * @next: Parameter2
*/
typedef struct node
{
	char str[1024];
	struct node *next;
} path_node;

char *my_getenv(const char *name);
char *my_strtok(char *str, const char *delim);
void my_env(void);
void resetFunc(char *str);
char *_getLineFunc();
void _free(path_node *node);
void print_number(int n);
path_node *get_path_list();
char **read_file(char *path);
void parse_input(char *buf, char *symo, int *pop, int *And, int *coun);
void handle_input(char *buf, char *Buff, int *er, int *w, int *e, int *cd,
		int *v, struct stat *Buf, int *sy, int *Sta);
void parse_command(char *BUf, char *buf, char *env, char **buff, int *siz,
		char *Buff, int *w, int *e);
void handle_echo(char **buff, char *Buff, char *ec, int *ECc, char *Echo,
		int *w, int *v, pid_t *pid, int *status);
void handle_exit(char *buf, char **buff, path_node *node);
void ch_dir(char **buff, char *home, char *symo, int *count, int *_cd,
		int *Sta, struct stat *Buf, int *ch);
char *set_path(path_node *h, int *w, ssize_t *size_getlin,
		char **buff, struct stat *Buf);
void handle_error(int *w, int *non, char **buff, char *Buff, char *argv,
		int *Sta, int *er, int *sy);
void reset(int *Sta, int *pop, int *And, int *Ec, int *che, int *sy, int *_cd,
		int *v, int *cd, int *e, int *w, int *size, size_t *d);
void reset_arr(int *coun, int *status, int *Sta, int *And,
		int *pop, char *symo);
void free_buf(int *fr, int *count, char *buf, char *env,
		int *f, path_node *node);
char *read_input(ssize_t *size_getline);
char *read_file_as_input(int *fr, ssize_t *size_getline,
		char **REad, int *ii, int *f);
char *my_buff(char *symo, ssize_t *size_getline, int *coun);
void execute_command(char **buff, pid_t *s, int *status);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
char *_strchr(char *s, char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _putchar(char c);


#endif
