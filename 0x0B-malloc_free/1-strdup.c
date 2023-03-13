#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string parameter
 * Return: a pointer or NULL
 */
char *_strdup(char *str)
{
	unsigned int len;
	char *newstr;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str) + 1;
	newstr = malloc(sizeof(char) * len);
	if (newstr == NULL)
	{
		return (NULL);
	}
	strcpy(newstr, str);
	return (newstr);
}
