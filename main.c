#include "main.h"

/**
 * main - Entry point of the program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	structure_free(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}

