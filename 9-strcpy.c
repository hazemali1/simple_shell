#include "shell.h"

/**
 * _strcpy - Copies
 *
 * Description: Copies
 *
 * @dest: Parameter
 * @src: Parameter
 *
 * Return: Return 0 (sucess)
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}
