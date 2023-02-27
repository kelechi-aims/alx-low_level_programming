#include "main.h"

/**
 * rev_string - function that reverses a string
 * @s: parameter of the function
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char str;

	while (*(s + i) != '\0')
	{
		i++;
	}
	while (j < i--)
	{
		str = *(s + j);
		*(s + j++)  = *(s + i);
		*(s + i) = str;
	}
}
