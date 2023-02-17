#include <stdio.h>
/**
 * main - The entry point of the code
 *
 * Return: The value 0
 */
int main(void)
{
	char alphabet;

	alphabet = 'a';

	for (alphabet <= 'z'; alphabet++;)
	{
		putchar(alphabet);
	}
	putchar('\n');
	return (0);
}
