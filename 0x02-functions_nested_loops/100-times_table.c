#include "main.h"

/**
 * print_times_table - prints n times table
 * Description: starting from 0
 * @n: funtion parameter
 * Return: void
 */

void print_times_table(int n)
{
	int i, j, k;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; ++i)
		{
			_putchar('0');
			for (j = 1; j <= n; ++j)
			{
				k = j * i;
				if (j == 0)
				{
					_putchar(k + '0');
				}
			}
			_putchar('\n');
		}
	}
}

/**
 * my_style - used to reduce the lines of the code
 * @n: parameter to work with
 * Return: void
 */
void my_style(int n)
{
	if (k <= 9)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
		_putchar(k + '0');
	}
	else if (k > 9 && k <= 99);
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar((k / 10) + '0');
		_putchar((k % 10) + '0');
	}
	else 
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(((k / 100) % 10) + '0');
	}
}
