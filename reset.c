#include "shell.h"

/**
 * reset - Reset varabiles for loop
 *
 * @Sta: P1
 * @pop: P2
 * @And: P3
 * @Ec: P4
 * @che: P5
 * @sy: P6
 * @_cd: P7
 * @v: P8
 * @cd: P9
 * @e: P10
 * @w: P11
 * @size: P12
 * @d: P13
*/
void reset(int *Sta, int *pop, int *And, int *Ec, int *che, int *sy,
		int *_cd, int *v, int *cd, int *e, int *w, int *size, size_t *d)
{
	*Sta = 0;
	*pop = 0;
	*And = 0;
	*Ec = 1;
	*che = 1;
	*sy = 0;
	*_cd = 0;
	*v = 0;
	*cd = 0;
	*e = 0;
	*w = -1;
	*size = 1;
	*d = 0;
}

/**
 * reset_arr - reset array
 *
 * @coun: P1
 * @status: P2
 * @Sta: P3
 * @And: P4
 * @pop: P5
 * @symo: P6
*/
void reset_arr(int *coun, int *status, int *Sta, int *And, int *pop,
		char *symo)
{
	int count = *coun;

	if (count != 0)
	{
		if (((WEXITSTATUS(*status) != 0 || *Sta != 0) &&
					*And == 1) || (*pop == 1 && (WEXITSTATUS(*status) == 0 && *Sta == 0)))
		{
			while (count >= 0)
			{
				symo[count] = '\0';
				count--;
			}
			count = 0;
		}
	}
	*coun = count;
}

/**
 * free_buf - free buffer
 *
 * @fr: P1
 * @count: P2
 * @buf: P3
 * @env: P4
 * @f: P5
 * @node: P6
*/
void free_buf(int *fr, int *count, char *buf, int *f,
		path_node *node)
{
	(void)fr;
	(void)count;
		free(buf);
	if (*f == 2)
	{
		_free(node);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_input - Read input
 *
 * @size_getline: Parameter
 *
 * Return: Buffer
*/
char *read_input(ssize_t *size_getline, path_node *head)
{
	char *buf;
		buf = _getLineFunc(head);
		if (*size_getline == -1)
			exit(EXIT_FAILURE);
		return (buf);
}

/**
 * read_file_as_input - Read from file as input
 *
 * @fr: P1
 * @size_getline: P2
 * @REad: P3
 * @ii: P4
 * @f: P5
 *
 * Return: Buffer
*/
char *read_file_as_input(int *fr, ssize_t *size_getline, char **REad,
		int *ii, int *f)
{
		char *buf;
		int i = *ii;

		*fr = 1;
		*size_getline = _strlen(REad[i]);
		buf = REad[i];
		i++;
		if (!REad[i])
			*f = 2;
		*ii = i;
		return (buf);
}
