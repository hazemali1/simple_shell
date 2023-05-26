#include "main.h"

/**
 * helper3 - Help information for the builtin help.
 * Return: no return
 */
void helper3(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, getStringLength(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, getStringLength(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, getStringLength(help));
}
/**
 * helper2 - Help information for the builtin alias.
 * Return: no return
 */
void helper2(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, getStringLength(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, getStringLength(help));
}
/**
 * helper1 - Help information for the builtin alias.
 * Return: no return
 */
void helper1(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, getStringLength(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, getStringLength(help));
}
