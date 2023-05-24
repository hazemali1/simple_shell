#include "shell.h"

/**
 * print_echo - Print buff
 *
 * @Echo: Parameter
*/
void print_echo(char *Echo)
{
	write(STDOUT_FILENO, Echo, _strlen(Echo));
	_putchar('\n');
}

/**
 * handle_exit - Exit
 *
 * @buf: P1
 * @buff: P2
 * @node: P3
*/
void handle_exit(char *buf, char **buff, path_node *node)
{
	if (_strcmp(buf, "exit") == 0)
	{
		if (buff[1])
		{
			_free(node);
			exit(_atoi(buff[1]));
		}
		else
		{
			_free(node);
			exit(0);
		}
	}
}

/**
 * ch_dir - Change dir
 *
 * @buff: P1
 * @home: P2
 * @symo: P3
 * @count: P4
 * @_cd: P5
 * @Sta: P6
 * @Buf: P7
 * @ch: P8
*/
void ch_dir(char **buff, char *home, char *symo, int *count,
		int *_cd, int *Sta, struct stat *Buf, int *ch)
{
		char *cwd, Cwd[1024];

		if (buff[1] == NULL)
			buff[1] = home;
		if (_strcmp(buff[1], "-") == 0)
		{
			if (Cwd[0] != '\0')
			{
				symo[0] = 'p';
				symo[1] = 'w';
				symo[2] = 'd';
				symo[3] = '\0';
				*count = 4;
				_strcpy(buff[1], Cwd);
			}
			else
			{
				*_cd = 1;
				write(STDERR_FILENO, "bash: cd: OLDPWD not set\n", 25);
				*Sta = 1;
			}
		}
		if (stat(buff[1], Buf) == 0)
		{
			cwd = getcwd(NULL, 0);
			if (cwd == NULL)
				exit(1);
			_strcpy(Cwd, cwd);
		}
		*ch = chdir(buff[1]);
		if (*ch == -1 && *_cd == 0)
		{
			write(STDERR_FILENO, "bash: cd: ", 10);
			perror(buff[1]);
			*Sta = 1;
		}
}

/**
 * set_path - Set path
 *
 * @h: P1
 * @w: P2
 * @size_getlin: P3
 * @buff: P4
 * @Buf: P5
 *
 * Return: Pointer
*/
char *set_path(path_node *h, int *w, ssize_t *size_getlin,
		char **buff, struct stat *Buf)
{
	ssize_t size_getline = *size_getlin;
	char *Buff;

	while (h != NULL && *w == -1)
	{
		Buff = malloc(sizeof(char) * (size_getline + 1 + _strlen(h->str)));
		if (Buff == NULL)
			exit(EXIT_FAILURE);
		_strcpy(Buff, h->str);
		_strcat(Buff, "/");
		_strcat(Buff, strtok(buff[0], "\n"));
		*w = stat(Buff, Buf);
		h = h->next;
	}
	*size_getlin = size_getline;
	return (Buff);
}

/**
 * handle_error - Error
 *
 * @w: P1
 * @non: P2
 * @buff: P3
 * @Buff: P4
 * @argv: P5
 * @Sta: P6
 * @er: P7
 * @sy: P8
*/
void handle_error(int *w, int *non, char **buff, char *Buff,
		char *argv, int *Sta, int *er, int *sy)
{
	if (*w == 0)
		buff[0] = Buff;
	else if (*non == 1)
	{
		write(STDERR_FILENO, argv, _strlen(argv));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, buff[0], _strlen(buff[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		*Sta = 1;
	}
	else
	{
		if (*er == 0)
		{
			write(STDERR_FILENO, buff[0], _strlen(buff[0]));
			write(STDERR_FILENO, ": command not found\n", 20);
			*Sta = 1;
		}
		else if (*sy == 0)
		{
			write(STDERR_FILENO, "bash: ", 6);
			perror(buff[0]);
			*Sta = 1;
		}
	}
}
