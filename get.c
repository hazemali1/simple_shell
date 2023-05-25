#include "shell.h"

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
