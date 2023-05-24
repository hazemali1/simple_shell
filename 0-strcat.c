#include "shell.h"

/**
 * _strcat - Conect
 *
 * Description: Conection
 *
 * @dest: Parameter1
 * @src: Parameter2
 *
 * Return: Return dest
*/
char *_strcat(char *dest, char *src)
{
	int d = 0, r = 0, u;
	char *e, *w;

	e = dest;
	w = src;
	while (*w != '\0')
	{
		w++;
		r++;
	}
	while (*e != '\0')
	{
		e++;
		d++;
	}
	for (u = 0; u <= r; u++)
	{
		dest[d] = src[u];
		d++;
	}
	return (dest);
}
