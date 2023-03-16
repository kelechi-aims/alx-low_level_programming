#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * *string_nconcat - concatenates two strings
 * @s1: destination string
 * @s2: source string
 * @n: number of first bytes to copy from source string
 * Return: a pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2;
	char *dest;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n >= len2)
	{
		n = len2;
	}
	dest = malloc(sizeof(char) * (len1 + n + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	strcpy(dest, s1);
	strncat(dest, s2, n);
	dest[len1 + n] = '\0';
	return (dest);
}
