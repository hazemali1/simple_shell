#include "shell.h"

/**
 * get_path_list - Get path
 *
 * Return: Head
*/
path_node *get_path_list()
{
	path_node *head = NULL;
	char *path = getenv("PATH");
	char *tok = strtok(path, ":");

	while (tok != NULL)
	{
		path_node *node = malloc(sizeof(path_node));

		if (node == NULL)
		{
			exit(EXIT_FAILURE);
		}
		_strcpy(node->str, tok);
		node->next = head;
		head = node;
		tok = strtok(NULL, ":");
	}
	return (head);
}

/**
 * read_file - Read from file
 *
 * @path: Parameter
 * @non: P2
 * @f: P3
 *
 * Return: Pointer
*/
char **read_file(char *path, int *non, int *f)
{
	int o, si = 1;
	ssize_t r;
	char Read[1024], **REad, *Re;

	o = open(path, O_RDONLY);
	if (o == -1)
	{
		exit(EXIT_FAILURE);
	}
	r = read(o, Read, 1024);
	if (r == -1)
	{
		exit(EXIT_FAILURE);
	}
	REad = malloc(sizeof(char *) * _strlen(Read));
	Re = strtok(Read, "\n");
	REad[0] = Re;
	while (Re != NULL)
	{
		Re = strtok(NULL, "\n");
		REad[si] = Re;
		si++;
	}
	si--;
	REad[si] = NULL;
	*non = 1;
	*f = 1;
	if (close(o) == -1)
	{
		exit(EXIT_FAILURE);
	}
	return (REad);
}
/**
 * set_arr - Set
 *
 * @symo: PArameter1
 * @coun: Parameter2
 * @Che: Parameter3
 * @buf: Parameter4
*/
void set_arr(char *symo, int *coun, int *Che, char *buf)
{
	int count = *coun, che = *Che;

	symo[count] = buf[che + 2];
	count++;
	che++;
	*coun = count;
	*Che = che;
}

/**
 * parse_input - Parse input
 *
 * @buf: Parameter1
 * @symo: Parameter2
 * @pop: Parameter3
 * @And: Parameter4
 * @coun: Parameter5
*/
void parse_input(char *buf, char *symo, int *pop, int *And, int *coun)
{
	int che = 1;
	int count = 0;

	while (buf[che] != '\0')
	{
		if (buf[che] == ';')
		{
			buf[che] = '\0';
			while (buf[che + 1] != '\0')
			{
				symo[count] = buf[che + 1];
				count++;
				che++;
			}
		}
		else if (buf[che] == '|' && buf[che + 1] == '|')
		{
			buf[che] = '\0';
			buf[che + 1] = '\0';
			while (buf[che + 2] != '\0')
				set_arr(symo, &count, &che, buf);
			*pop = 1;
		}
		else if (buf[che] == '&' && buf[che + 1] == '&')
		{
			buf[che] = '\0';
			buf[che + 1] = '\0';
			while (buf[che + 2] != '\0')
				set_arr(symo, &count, &che, buf);
			*And = 1;
		}
		else if (buf[che] == '#')
		{
			buf[che] = '\0';
			while (buf[che + 1] != '\0')
				che++;
		}
		che++;
	}
	*coun = count;
}
