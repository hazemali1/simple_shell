#include "main.h"

/**
 * handle_error - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *handle_error(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = convertIntToString(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = getStringLength(datash->av[0]) + getStringLength(ver_str);
	length += getStringLength(datash->args[0]) + getStringLength(msg) + 4;
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
	combine(error, msg);
	combine(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = convertIntToString(datash->counter);
	length = getStringLength(datash->av[0]) + getStringLength(ver_str);
	length += getStringLength(datash->args[0]) + 24;
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
	combine(error, ": Permission denied\n");
	combine(error, "\0");
	free(ver_str);
	return (error);
}
