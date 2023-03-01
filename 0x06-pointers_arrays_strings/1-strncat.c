#include "main.h"

/**
 * *_strncat - concatenates two strings
 * @dest: first character parameter
 * @src: second charater parameter
 * @n: third parameter and an integer
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int destlen = 0, srclen = 0;

	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (srclen < n)
	{
		dest[destlen] = src[srclen];
		if (src[srclen] == '\0')
		{
			break;
		}
		destlen++;
		srclen++;
	}
	return (dest);
}
