#include "shell.h"

/**
 * _strcmp - Compare
 *
 * Description: Comparing
 *
 * @s1: Parameter1
 * @s2: Parameter2
 *
 * Return: Return value
*/
int _strcmp(char *s1, char *s2)
{
	int d = 0, f = 0, r = 0, o = 0, q = 0;

	while (s1[f] != '\0' || s2[q] != '\0')
	{
	if (s1[r] == s2[o])
	{
	r++;
	o++;
	}
	else if (s1[r] > s2[o])
	{
		d = s1[r] - s2[o];
	}
	else if (s1[r] < s2[o])
	{
		d = s1[r] - s2[o];
	}
	f++;
	q++;
	}
	return (d);
}
