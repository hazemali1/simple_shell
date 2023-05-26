#include "main.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, otherwise error code
 */
int main(void)
{
	char *command;

	while (1)
	{
		displayPrompt();

		/* Read the command */
		command = readCommand();

		/* Check for end of file condition (Ctrl+D) */
		if (feof(stdin))
		{
			printf("\n");
			break;
		}

		/* Execute the command */
		executeCommand(command);

		/* Free the allocated memory */
		free(command);
	}

	return (0);
}

