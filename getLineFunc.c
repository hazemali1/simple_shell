#include "shell.h"

/**
* _getLineFunc - Read The Input from Keyboard
* Return: Input
*/
char *_getLineFunc()
{
	char *arr, c = 0;
	int i, memosize = 1024, rd;

	arr = malloc(memosize);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	_memset(arr, 0, memosize);

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(arr);
			exit(EXIT_SUCCESS);
		}
		arr[i] = c;
		if (i >= memosize)
		{
			arr = _realloc(arr, memosize, memosize + 1);
			if (arr == NULL)
			{
				return (NULL);
			}
		}
	}
	arr[i] = '\0';
	resetFunc(arr);
	return (arr);
}

/**
 * resetFunc - remove all after #
 * @str: input;
 * Return:void
 */
void resetFunc(char *str)
{
	int i;

		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '#')
			{
			str[i] = '\0';
			break;
			}
	}
}
