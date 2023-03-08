#include "main.h"
int is_not_prime(int n, int x);

/**
 * is_prime_number - returns 1 if the input integer is a 
 * prime number otherwise return 0
 * @n: integer parameter
 * Return: integer
 */
int is_prime_number(int n)
{
	if (n == 2)
	{
		return (1);
	}
	if (n <= 1)
	{
		return (0);
	}
	return (is_not_prime(n, 2));
}

/**
 * is_not_prime - returns divisible number
 * @n: integer to check
 * @x: divisor
 * Return: integer
 */
int is_not_prime(int n, int x)
{
	if (n % x == 0)
	{
		return (0);
	}
	if (x * x > n)
	{
		return (1);
	}
	return (is_not_prime(n, x + 1));

}
