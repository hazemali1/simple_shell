#include "main.h"

/**
 * stringDuplicat - duplicates a string in the heap memory.
 * @source: Type char pointer str.
 * Return: duplicated string.
 */
char *stringDuplicat(const char *source)
{
	char *newString;
	size_t length;

	length = getStringLength(source);
	newString = malloc(sizeof(char) * (length + 1));
	if (newString == NULL)
		return (NULL);
	blockCopy(newString, source, length + 1);
	return (newString);
}

/**
 * getStringLength - Returns the length of a string.
 * @s: Type char pointer.
 * Return: Length of the string.
 */
int getStringLength(const char *s)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * compareCharacters - compare characters of strings.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if the characters are equal, 0 if not.
 */
int compareCharacters(char str[], const char *delim)
{
	unsigned int i, j, count;

	for (i = 0, count = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				count++;
				break;
			}
		}
	}
	if (i == count)
		return (1);
	return (0);
}

/**
 * stringTokenize - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: splited string.
 */
char *stringTokenize(char str[], const char *delim)
{
	static char *splitted, *strEnd;
	char *strStart;
	unsigned int i, isNonEmpty;

	if (str != NULL)
	{
		if (compareCharacters(str, delim))
			return (NULL);
		splitted = str; /* Store first address */
		i = getStringLength(str);
		strEnd = &str[i]; /* Store last address */
	}
	strStart = splitted;
	if (strStart == strEnd) /* Reaching the end */
		return (NULL);

	for (isNonEmpty = 0; *splitted; splitted++)
	{
		/* Breaking loop finding the next token */
		if (splitted != strStart)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/* Replacing delimiter with null char */
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == strStart)
					strStart++;
				break;
			}
		}
		if (isNonEmpty == 0 && *splitted) /* Str != Delim */
			isNonEmpty = 1;
	}
	if (isNonEmpty == 0) /* Str == Delim */
		return (NULL);
	return (strStart);
}

/**
 * isStringDigit - defines if string passed is a number.
 *
 * @s: input string.
 * Return: 1 if string is a number, 0 otherwise.
 */
int isStringDigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

