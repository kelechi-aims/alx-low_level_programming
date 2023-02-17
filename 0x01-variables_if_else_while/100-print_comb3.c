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

	i = '0';
	j = '0';

	while (j <= '9')
	{
		i = '0';
		while (i <= '9')
		{
			if (j != i && j < i)
			{
				putchar(j);
				putchar(i);
				if (i == '8' && j == '9')
				{
					break;
				}
				putchar(',');
				putchar(' ');
			}
			i++;
		}
		j++;
	}
	putchar('\n');
	return (0);
}
