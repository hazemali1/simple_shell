#include "shell.h"

/**
 * help - Helping
 *
 * @sy: P1
 * @w: P2
 * @er: P3
 * @Sta: P4
*/
void help(int *sy, int *w, int *er, int *Sta)
{
	*sy = 1;
	*w = -1;
	*er = 1;
	*Sta = 1;
}

/**
 * handl_input - Handle input
 *
 * @buf: PArameter1
 * @Buff: PArameter2
 * @er: Parameter3
 * @w: Parameter4
 * @e: PArameter5
 * @cd: Parameter6
 * @v: Parameter7
 * @Buf: Parameter8
 * @sy: PArameter9
 * @Sta: Parameter10
*/
char *handle_input(char *buf, int *er, int *w, int *e, int *cd,
		int *v, struct stat *Buf, int *sy, int *Sta)
{
	char *Buff;

	if (buf[0] == '/' || (buf[0] == '.' && buf[1] == '/'))
	{
		Buff = malloc(sizeof(char) * _strlen(buf));
		if (Buff == NULL)
			exit(EXIT_FAILURE);
		_strcpy(Buff, my_strtok(buf, "\n"));
		*w = stat(my_strtok(Buff, " "), Buf);
		*er = 1;
	}
	if (buf[0] == '\n')
	{
		Buff = malloc(1);
		if (Buff == NULL)
			exit(EXIT_FAILURE);
		*w = 0;
		*e = 1;
	}
	if (buf[0] == 'c' && buf[1] == 'd' && (buf[2] == ' ' || buf[2] == '\n'))
	{
		Buff = malloc(sizeof(char) * _strlen(buf));
		if (Buff == NULL)
			exit(EXIT_FAILURE);
		*cd = 1;
		*w = 0;
	}
	if (buf[0] == 'e' && buf[1] == 'n' && buf[2] == 'v')
	{
		Buff = malloc(1);
		if (Buff == NULL)
			exit(EXIT_FAILURE);
		my_env();
		*w = 0;
		*v = 1;
	}
	if (buf[0] == ';')
	{
		write(STDERR_FILENO, "bash: syntax error near unexpected token `;'\n", 45);
		help(sy, w, er, Sta);
	}
	return (Buff);
}

/**
 * parse_command - Parse command
 *
 * @BUf: P1
 * @buf: P2
 * @env: P3
 * @buff: P4
 * @siz: P5
 * @Buff: P6
 * @w: P7
 * @e: P8
*/
void parse_command(char *BUf, char *buf, char **buff,
		int *siz, char *Buff, int *w, int *e)
{
	int size = 1;
	char *env;

	BUf = my_strtok(buf, "\n");
	env = my_strtok(BUf, " ");
	buff[0] = env;
	if (_strcmp(env, " ") == 0)
		env = NULL;
	if (env == NULL)
	{
		Buff = malloc(1);
		if (Buff == NULL)
		{
			exit(EXIT_FAILURE);
		}
		free(Buff);
		*w = 0;
		*e = 1;
	}
	while (env != NULL)
	{
		env = my_strtok(NULL, " ");
		buff[size] = env;
		size++;
	}
	size--;
	buff[size] = NULL;
	*siz = size;
}

/**
 * RE_set - Reset
 *
 * @w: P1
 * @v: P2
*/
void RE_set(int *w, int *v)
{
	*w = 0;
	*v = 1;
}

/**
 * handle_echo - Handle echo command
 *
 * @buff: P1
 * @Buff: P2
 * @ec: P3
 * @ECc: P4
 * @Echo: P5
 * @w: P6
 * @v: P7
 * @pid: P8
 * @status: P9
*/
void handle_echo(char **buff, char *Buff, char *ec, int *ECc, char *Echo,
		int *w, int *v, pid_t *pid, int *status)
{
		int Ec = *ECc;

		if (_strcmp(buff[0], "echo") == 0)
		{
			if (buff[1] == NULL)
				buff[1] = " ";
			else if (buff[1][0] == '$')
			{
				Buff = malloc(1);
				if (Buff == NULL)
					exit(EXIT_FAILURE);
				if (buff[1][1] == '$')
				{
					*pid = getpid();
					print_number(*pid);
					_putchar('\n');
				}
				else if (buff[1][1] == '?')
				{
					print_number(WEXITSTATUS(*status));
					_putchar('\n');
				}
				else if (buff[1][1])
				{
					while (buff[1][Ec])
					{
						ec[Ec - 1] = buff[1][Ec];
						Ec++;
					}
					(Ec)--;
					ec[Ec] = '\0';
					Echo = my_getenv(ec);
					if (Echo == NULL)
						_putchar('\n');
					else
						print_echo(Echo);
				}
				if (buff[1][1])
					RE_set(w, v);
			}
		}
		*ECc = Ec;
}
