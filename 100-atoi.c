#include "shell.h"

/**
 * _atoi - Atoi
 *
 * Description: Print
 *
 * @s: Parameter
 *
 * Return: Return 0 (sucess)
*/
int _atoi(char *s)
{
	int d = 0, e = 0, o = 1;
	unsigned int w = 0;

	while (s[d])
	{
		if (s[d] == 45)
		{
			o *= -1;
		}
		while (s[d] >= 48 && s[d] <= 57)
		{
			e = 1;
			w = (w * 10) + (s[d] - '0');
			d++;
		}
		if (e == 1)
		{
			break;
		}
		d++;
	}
	w *= o;
	return (w);
}
