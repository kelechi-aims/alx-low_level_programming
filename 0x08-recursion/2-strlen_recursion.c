#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string parameter
 * Return: integer
 */
int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s != '\0')
	{
		len++;
		return (len + _strlen_recursion(s + 1));
	}
	return (0);
}
