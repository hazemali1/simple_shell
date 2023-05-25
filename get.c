#include "shell.h"

/**
 * my_getenv - Geten function
 *
 * @name: Parameter
 *
 * Return: Pointer
*/
char *my_getenv(char *name)
{
	char **env = environ;
	size_t len = _strlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
                env++;
	}
	return (NULL);
}

/**
 * my_strtok - Strtok function
 *
 * @str: Parameter1
 * @delim: Parameter2
 *
 * Return: Pointer
*/
char *my_strtok(char *str, char *delim)
{
	static char *last = NULL;
	char *tok;

	if (str != NULL)
	{
		last = str;
	}
	if (last == NULL || *last == '\0')
	{
		return (NULL);
	}
	while (*last != '\0' && _strchr(delim, *last) != NULL)
	{
		last++;
	}
	tok = last;
	while (*last != '\0')
	{
		if (_strchr(delim, *last) != NULL)
		{
			*last++ = '\0';
			break;
		}
		last++;
	}
	return (tok);
}

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
