#include "shell.h"

/**
 * my_buff - Buffer
 *
 * @symo: P!
 * @size_getline: P2
 * @coun: P3
 *
 * Return: Buffer
*/
char *my_buff(char *symo, ssize_t *size_getline, int *coun)
{
	int count = *coun;
	char *buf;

	_strcpy(buf, symo);
	*size_getline = _strlen(buf);
	while (count >= 0)
	{
		symo[count] = '\0';
		count--;
	}
	count = 0;
	*coun = count;
	return (buf);
}

/**
 * execute_command - Execute
 *
 * @buff: P1
 * @s: P2
 * @status: P3
*/
void execute_command(char **buff, pid_t *s, int *status)
{
		*s = fork();
		if (*s == 0)
			execve(buff[0], buff, NULL);
		else if (*s == -1)
			exit(EXIT_FAILURE);
		else
			waitpid(*s, status, 0);
}
