#include "shell.h"

/**
 * _strlen - Lenght
 *
 * Description: Lenght
 *
 * @s: Parameter
 *
 * Return: Return 0 (sucess)
*/
int _strlen(char *s)
{
	int d = 0;

	while (*s != '\0')
	{
		d++;
		s++;
	}
	return (d);
}
