#include <stdio.h>

/**
 *main - The entry point of the code
 *
 * Return: The value 0
 */

int main(void)
{
	char b;

	for (b = 'a'; b <= 'z'; ++b)
	{
		putchar(b);
	}
	for (b = 'A'; b <= 'Z'; ++b)
	{
		putchar(b);
	}
	putchar('\n');
	return (0);
}
