#include "shell.h"

/**
 * _strchr - Function
 *
 * Description: Prints
 *
 * @s: Parameter1
 * @c: Parameter2
 *
 * Return: Return s
*/
char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
	s++;
	}
		return ('\0');
}
