#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = compare_str("$HOME", dir);
		ishome2 = compare_str("~", dir);
		isddash = compare_str("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (compare_str("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (compare_str(".", dir) == 0 || compare_str("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
