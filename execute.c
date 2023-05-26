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
	char *buf = malloc(sizeof(char) * _strlen(symo));

	if (buf == NULL)
	{
		free(buf);
		exit(1);
	}
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

/**
 * _strncmp - Strncmp function
 *
 * @s1: P2
 * @s2: P3
 * @n: P3
 *
 * Return: Int
*/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
