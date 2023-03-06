#include "main.h"
#include <stdio.h>

/**
 * *_strchr - locates a character in a string
 * @s: string of characters
 * @c: character to locate in s
 * Return: a pointer or null
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return (NULL);
}
