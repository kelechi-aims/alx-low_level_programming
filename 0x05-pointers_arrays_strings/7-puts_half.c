#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: parameter of the function
 *
 * Return: void
 */
void puts_half(char *str)
{
	unsigned int i  = 0, n;

	while (str[i] != '\0')
	{
		i++;
	}
	if (i % 2 == 0)
	{
		n = i / 2;
	}
	else
	{
		n = (i - 1) / 2;
	}
	for (; n < i; n++)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
}
