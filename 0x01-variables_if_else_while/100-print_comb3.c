#include <stdio.h>

/**
 * main - The starting point of the code
 *
 * Return: The value 0
 */

int main(void)
{
	int i;
	int j;

	for (i = '0'; i <= '9'; i++)
	{
		for (j = '0'; j <= '9'; j++)
		{
			if (i != j && i < j)
			{
				putchar(i);
				putchar(j);
				if (i == '8' && j == '9')
				{
					break;
				}
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
