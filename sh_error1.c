#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	combine(error, ": ");
	combine(error, ver_str);
	combine(error, ": ");
	combine(error, datash->args[0]);
	combine(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		combine(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		combine(error, datash->args[1]);
	}

	combine(error, "\n");
	combine(error, "\0");
	return (error);
}

/**
 * display_cd_error - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *display_cd_error(data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = convertIntToString(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = getStringLength(datash->args[1]);
	}

	length = getStringLength(datash->av[0]) + getStringLength(datash->args[0]);
	length += getStringLength(ver_str) + getStringLength(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *not_found(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = convertIntToString(datash->counter);
	length = getStringLength(datash->av[0]) + getStringLength(ver_str);
	length += getStringLength(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	combine(error, ": ");
	combine(error, ver_str);
	combine(error, ": ");
	combine(error, datash->args[0]);
	combine(error, ": not found\n");
	combine(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * shell_exit - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *shell_exit(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = convertIntToString(datash->counter);
	length = getStringLength(datash->av[0]) + getStringLength(ver_str);
	length += getStringLength(datash->args[0]) +
		getStringLength(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	combine(error, ": ");
	combine(error, ver_str);
	combine(error, ": ");
	combine(error, datash->args[0]);
	combine(error, ": Illegal number: ");
	combine(error, datash->args[1]);
	combine(error, "\n\0");
	free(ver_str);

	return (error);
}
