#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
*
* Description: getline function without using getline()
* Return: Always 0 (Success)
*/

int main(char argc, char *argv[])
{
	char arr[128];
	size_t len = sizeof(arr);
	char *line = malloc(len);
	FILE *f;

	line[0] = '\0';
	if (f == NULL)
	{
		perror("Unable to open file !");
		exit(EXIT_FAILURE);
	}
	if (line == NULL)
	{
		perror("unable to allocate memory line buffer");
		exit(EXIT_FAILURE);
	}
	while (fgets(arr, sizeof(arr), f) != NULL)
	{
		if (len - strlen(line) < sizeof(arr))
		{
			len *= 2;
			if ((line == realloc(line, len)) == NULL)
			{
				perror("realloc failed for line in line buffer");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		strcat(line, arr);
		if (line[strlen(line) - 1] == '\n')
		{
			fputs(line, stdout);
			fputs("|\n", stdout);
			line[0] = '\n';
		}
		fclose(f);
		free(line);
	}
	return (0);

}
