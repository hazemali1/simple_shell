#include "main.h"

/**
 * strtoken - splits a string into words. Repeat delimiters are ignored
 * @inputString: the input string
 * @d: the size of array integer
 */

void strtoken(char *inputString, int d)
{
	char words[d][d];
	int wordIndex = 0, indexCtr = 0, totalWords = 0;


	if (inputString == NULL || inputString[0] == 0)
		perror("No input String !");
	if (!d)
		d = 0;
	for (indexCtr = 0; indexCtr <= strlen(inputString); indexCtr++)
	{
		if (inputString[indexCtr] == ' ' || inputString[indexCtr] == '\0')
		{
			words[totalWords][wordIndex] = '\0';
			totalWords++;
			wordIndex = 0;
		}
		else
		{
			words[totalWords][wordIndex] = inputString[indexCtr];
			wordIndex++;
		}
	}

	printf("\n word from string are:\n");
	for (wordIndex = 0; wordIndex < totalWords; wordIndex++)
		printf(" %s\n", words[wordIndex]);

}
