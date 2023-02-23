#include "main.h"

/**
 * print_number - prints and integer
 * @n: function's parameter
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
 * @q: parameter of the function
 *
 * Return: void
 */
void print_num(int q)
{
	unsigned int i = 1000000000;

	for (; i >= 1; i /= 10)
	{
		if (q / i != 0)
		{
			_putchar((q / i) % 10 + '0');
		}
	}
}
