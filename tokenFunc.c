#include "main.h"

/**
 * strtoken - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the size of array integer
 */

void strtoken(char *str, int d)
{
	char wrd[10][10];
	int wdIn = 0, index = 0, totWrd = 0;


	if (str == NULL || str[0] == 0)
		perror("No input String !");
	if (!d)
		d = 0;
	for (index = 0; index <= (int) strlen(str); index++)
	{
		if (str[index] == ' ' || str[index] == '\0')
		{
			wrd[totWrd][wdIn] = '\0';
			totWrd++;
			wdIn = 0;
		}
		else
		{
			wrd[totWrd][wdIn] = str[index];
			wdIn++;
		}
	}

	printf("\n word from string are:\n");
	for (wdIn = 0; wdIn < totWrd; wdIn++)
		printf(" %s\n", wrd[wdIn]);

}
