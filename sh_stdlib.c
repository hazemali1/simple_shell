#include "main.h"

/**
 * getNumberLength - Get the length of a number.
 * @num: type int number.
 * Return: Length of the number.
 */
int getNumberLength(int num)
{
	unsigned int numAbs;
	int length = 1;

	if (num < 0)
	{
		length++;
		numAbs = num * -1;
	}
	else
	{
		numAbs = num;
	}
	while (numAbs > 9)
	{
		length++;
		numAbs = numAbs / 10;
	}

	return (length);
}

/**
 * convertIntToString - Convert integer to string.
 * @num: type int number.
 * Return: String representation of the number.
 */
char *convertIntToString(int num)
{
	unsigned int numAbs;
	int length = getNumberLength(num);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == NULL)
		return (NULL);

	buffer[length] = '\0';

	if (num < 0)
	{
		numAbs = num * -1;
		buffer[0] = '-';
	}
	else
	{
		numAbs = num;
	}

	length--;
	do {
		buffer[length] = (numAbs % 10) + '0';
		numAbs = numAbs / 10;
		length--;
	} while (numAbs > 0);

	return (buffer);
}

/**
 * convertStringToInt - Convert a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int convertStringToInt(char *str)
{
	unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

	while (str[count] != '\0')
	{
		if (size > 0 && (str[count] < '0' || str[count] > '9'))
			break;

		if (str[count] == '-')
			sign *= -1;

		if ((str[count] >= '0') && (str[count] <= '9'))
		{
			if (size > 0)
				multiplier *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		result = result + ((str[i] - '0') * multiplier);
		multiplier /= 10;
	}

	return (result * sign);
}

