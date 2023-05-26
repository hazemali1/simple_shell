#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		helper3_general();
	else if (compare_str(datash->args[1], "setenv") == 0)
		helper3_setenv();
	else if (compare_str(datash->args[1], "env") == 0)
		helper3_env();
	else if (compare_str(datash->args[1], "unsetenv") == 0)
		helper3_unsetenv();
	else if (compare_str(datash->args[1], "help") == 0)
		helper3();
	else if (compare_str(datash->args[1], "exit") == 0)
		helper3_exit();
	else if (compare_str(datash->args[1], "cd") == 0)
		helper1();
	else if (compare_str(datash->args[1], "alias") == 0)
		helper2();
	else
		write(STDERR_FILENO, datash->args[0],
		      getStringLength(datash->args[0]));

	datash->status = 0;
	return (1);
}
