#include "shell.c"

/**
 * _realloc - Realloc
 *
 * @ptr: P1
 * @old_size: P2
 * @new_size: P3
 *
 * Return: Void
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_all_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * fill_all_array - fill array
 *
 * @a: P1
 * @el: P2
 * @len: P3
 *
 * Return: Void
*/
void *fill_all_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _memcpy - Memcpy function
 *
 * @dest: P1
 * @src: P2
 * @n: P3
 *
 * Return: Pointer
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
