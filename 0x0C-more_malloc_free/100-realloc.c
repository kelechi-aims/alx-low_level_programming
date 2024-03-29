#include "main.h"
#include <stdlib.h>
#include <sys/param.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the allocated memory
 * @old_size: allocated memory size
 * @new_size: reallocating memory size
 * Return: void
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;

	if (new_size > old_size)
	{
		free(ptr);
		new = malloc(new_size);
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		new = malloc(new_size);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new == NULL)
	{
		return (NULL);
	}
	return (new);
}
