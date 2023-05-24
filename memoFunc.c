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

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
