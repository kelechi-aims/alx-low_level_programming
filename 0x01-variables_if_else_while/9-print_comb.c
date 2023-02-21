#include <stdio.h>

/**
 * main - The entry point of the code
 *
 * Return: The value 0
 */

int main(void)
{
	int i;

	for (i = '0'; i <= '9'; ++i)
	{
		putchar(i);
		if (i != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}