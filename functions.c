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
	pid_t pid;

	/* Remove the newline character at the end */
	command[strcspn(command, "\n")] = '\0';

	/* Create a child process */
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */

		/* Execute the command */
		if (execlp(command, command, NULL) == -1)
		{
			fprintf(stderr, "%s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}


