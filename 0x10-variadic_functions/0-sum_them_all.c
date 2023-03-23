#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: numberof args to sum
 * Return: integer
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
