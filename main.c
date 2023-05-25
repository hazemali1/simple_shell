#include "shell.h"

char *_getLineFunc(void);

/**
 * main - Main function
 *
 * Return: Always 0
*/
int main(void)
{
	pid_t pid;
	int status;
	char *buf, *buff[1024] = {NULL};

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		buf = _getLineFunc();
		buff[0] = my_strtok(buf, "\n");
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
		{
			execve(buff[0], buff, NULL);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	free(buf);
	}
	return (0);
}
