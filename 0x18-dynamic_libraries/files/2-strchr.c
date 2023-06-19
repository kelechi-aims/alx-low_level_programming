#include "main.h"

/**
 * *_strchr - locates a character in a string
 * @s: string character
 * @c: character to locate
 * Return: a pointer or null
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	if (s[i] == c)
	{
		return (s + i);
	}
	return ('\0');
}
