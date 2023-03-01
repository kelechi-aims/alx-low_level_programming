#include "main.h"

/**
 * *_strncpy - copies a string
 * @dest: string that the src string is append to
 * @src: string that is append to the dest string
 * @n: miximum number of byte from src
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
