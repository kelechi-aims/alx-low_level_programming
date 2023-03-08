#include "main.h"
int _sqrt(int n, int x);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer argument
 * Return: integer
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (_sqrt(1, n));
	}
}

/**
 * _sqrt - returns the natural square of a number
 * @n: the number
 * @x: natural square of the number n
 * Return: integer
 */
int _sqrt(int n, int x)
{
	if (n > x)
	{
		return (-1);
	}
	else if (n * n == x)
	{
		return (n);
	}
	return (_sqrt(n + 1, x));
}
