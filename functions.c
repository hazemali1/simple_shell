#include "main.h"

/**
 * displayPrompt - Displays the shell prompt
 */
void displayPrompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
/**
 * readCommand - Reads a command from the user
 *
 * Return: The command entered by the user
 */
char *readCommand(void)
{
	char *command = malloc(MAX_INPUT_LENGTH * sizeof(char));

	fgets(command, MAX_INPUT_LENGTH, stdin);

	return (command);
}

/**
 * executeCommand - Executes a command
 * @command: The command to execute
 */

void executeCommand(char *command)
{
	char *args[MAX_INPUT_LENGTH];
	/* Array to store command and arguments */
	int argc = 0; /* Argument count */

	/* Remove the newline character at the end */
	command[strcspn(command, "\n")] = '\0';

	/* Tokenize the command into arguments */
	char *token = strtok(command, " ");
	while (token != NULL)
	{
		args[argc++] = token;
		token = strtok(NULL, " ");
	}
	args[argc] = NULL;  /* Set the last element to NULL as required by execvp */

	/* Execute the command */
	execvp(args[0], args);

	/* If execvp returns, it means the command was not found */
	fprintf(stderr, "%s: command not found\n", args[0]);
	exit(EXIT_FAILURE);
}

