#include "main.h"
/**
 * exit_Shell - Exit Statue Of Shell
 * @pc: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
 */
void  exit_Shell(char **pc, char *input, char **argv, int c)
{
	int st, j = 0;

	if (pc[1] == NULL)
	{
		free(input);
		free(pc);
		exit(EXIT_SUCCESS);
	}
	while (pc[1][j])
	{
		if (_isalpha(pc[1][j++]) != 0)
		{
			_prerror(argv, c, pc);
			break;
		}
		else
		{
			st = _atoi(pc[1]);
			free(input);
			free(pc);
			exit(st);
		}
	}
}


/**
 * change_Dir - Change Dirctory
 * @pc: Parsed Command
 * @st: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed
 *
 */
int change_Dir(char **pc, __attribute__((unused))int st)
{
	int value = -1;
	char path[PATH_MAX];

	if (pc[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(pc[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(pc[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(path, sizeof(path));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", path, 1);
	}
	return (0);
}
/**
 * dis_env - Display Enviroment Variable
 * @pc:Parsed Command
 * @st:Statue of Last command Excuted
 * Return:Always 0
 */
int dis_env(__attribute__((unused)) char **pc, __attribute__((unused)) int st)
{
size_t j;
	int len;

	for (j = 0; environ[j] != NULL; j++)
	{
		len = _strlen(environ[j]);
		write(1, environ[j], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * dis_Build - Displaying For Builtin
 * @pc:Parsed Command
 * @st: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int dis_Build(char **pc, __attribute__((unused))int st)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(pc[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * exec_Disp - Excute Echo For Output
 * @st:Statue Of Last Command Excuted
 * @pc: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int exec_Disp(char **pc, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(pc[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(pc[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(pc[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(pc));

	return (1);
}
