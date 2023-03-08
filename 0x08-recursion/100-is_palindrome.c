#include "main.h"
int _strlen_recursion(char *s);
int palin_checker(char *s, int n1, int n2);

/**
 * is_palindrome - returns 1 if a string is a palindrome
 * and 0 if not
 * @s: string argument
 * Return: integer
 */
int is_palindrome(char *s)
{
	return (palin_checker(s, 0, _strlen_recursion(s) - 1));
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: string argument
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

/**
 * palin_checker - checks characters of a string
 * @s: string argument
 * @n1: start of the string lenth
 * @n2: end of the string length
 * Return: integer
 */
int palin_checker(char *s, int n1, int n2)
{
	if (n1 >= n2)
	{
		return (1);
	}
	else if (s[n1] != s[n2])
	{
		return (0);
	}
	return (palin_checker(s, n1 + 1, n2 - 1));
}
