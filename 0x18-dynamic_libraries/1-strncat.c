#include "main.h"

/**
 * *_strncat - concatenates two strings
 * @dest: string where src string is append to
 * @src: string that is append to the dest string
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
