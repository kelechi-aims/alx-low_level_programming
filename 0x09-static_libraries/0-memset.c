#include "main.h"

/**
 * *_memset - fills memory
 * @s: destination string
 * @b: source string
 * @n: number of bytes to occupy
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
