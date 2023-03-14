#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *str_concat - concatenates two string and returns pointer to a
 * newly allocated space in memory which contains the contents of
 * s1, followed by the contents of s2 and null terminated
 * @s1: destination string
 * @s2: source string
 * Return: a pointer or NULL
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1, len2, len3;
	char *str;

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
	len3 = len1 + len2 + 1;
	str = malloc(sizeof(char) * (len3));
	if (str == NULL)
	{
		return (NULL);
	}
	strcat(str, s1);
	strcat(str,s2);

	return (str);
}
