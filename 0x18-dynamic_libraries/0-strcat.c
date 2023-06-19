#include "main.h"

/**
 * *_strcat - concatenates two strings
 * @dest: character parameter
 * @src: second charater parameter
 *
 * Return: a pointer
 */
char *_strcat(char *dest, char *src)
{
	int destlen = 0, srclen = 0;

	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (srclen >= 0)
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
