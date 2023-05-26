#include "shell.h"

/**
 * _memset - Function
 *
 * Description: Swich
 *
 * @s: Parameter1
 * @b: Parameter2
 * @n: Parameter3
 *
 * Return: Return s
*/
char *_memset(char *s, char b, unsigned int n)
{
	int d, w;

	w = (n * sizeof(*s));
			for (d = 0; d < w; d++)
			{
			s[d] = b;
			}
	return (s);
}
