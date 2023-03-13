#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * *create_array - creates an array of chars, and initializes
 * it with a specific char
 * @size: parameter counter
 * @c: char parameter
 * Return: a pointer or NULL
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *carr;

	if (size == 0)
	{
		return (0);
	}

	carr = malloc(size + 1 * sizeof(char));
	if (carr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		carr[i] = c;
	}
	carr[i] = '\0';
	return (carr);
}
