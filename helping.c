#include "main.h"

/**
 * structure_free - Frees the data structure.
 * @datash: Pointer to the data structure.
 *
 * Return: No return value.
 */
void structure_free(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data-Initializes the data structure.
 * @datash: Pointer to the data structure.
 * @av: Argument vector.
 *
 * Return: No return value.
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = stringDuplicat(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = convertIntToString(getpid());
}

