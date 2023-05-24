#include "shell.h"


/**
 * my_env - Handle env command
*/
void my_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * _free - Free memory
 *
 * @node: Parameter
*/
void _free(path_node *node)
{
	while (node != NULL)
	{
		path_node *cur = node->next;

		free(node);
		node = cur;
	}
}

/**
 * print_number - Print int
 *
 * @n: Parameter
*/
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar(n % 10 + '0');
}
