#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: parameter of the function
 *
 * Return: value 0
 */
int _atoi(char *s)
{
	int a = 1;
	unsigned int b = 0;
	char c = 0;

	while (*s)
	{
		if (*s == '-')
		{
			a = a * -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			c = 1;
			b = b * 10 + *s - '0';
		}
		else if (c)
		{
			break;
		}
		s++;
	}
	if (a < 0)
	{
		b = (-b);
	}
	return (b);
}
