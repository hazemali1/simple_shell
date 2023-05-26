#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = handle_error(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = not_found(datash);
		break;
	case 2:
		if (compare_str("exit", datash->args[0]) == 0)
			error = shell_exit(datash);
		else if (compare_str("cd", datash->args[0]) == 0)
			error = display_cd_error(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, getStringLength(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
