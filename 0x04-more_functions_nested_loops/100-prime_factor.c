#include <stdio.h>

/**
 * main - prints the largest prime factor of the number n
 *
 * Return: value 0
 */
int main(void)
{
	unsigned long fp;
	unsigned long n = 612852475143;

	for (fp = 2; fp <= n; fp++)
	{
		if (n % fp == 0)
		{
			n /= fp;
			fp--;
		}
	}
	printf("%lu\n", fp);
	return (0);
}
