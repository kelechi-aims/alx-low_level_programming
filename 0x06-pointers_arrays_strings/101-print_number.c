#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer parameter
 *
 * Return: void
 */
void print_number(int n)
{
	if (n > 0)
	{
		print_num(n);
	}
	else if (n < 0)
	{
		_putchar('-');
		print_num(-1 * n);
	}
	else
	{
		_putchar('0');
	}
}

/**
 * print_num - prints larger integer
 * @p: integer parameter
 *
 * Return: void
 */
void print_num(int p)
{
	unsigned int i = 1000000000;

	for (; i >= 1; i /= 10)
	{
		if (p / i != 0)
		{
			_putchar((p / i) % 10 + '0');
		}
	}
}
