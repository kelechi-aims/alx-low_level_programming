#include <stdio.h>

/**
 * main - The starting point of the code
 *
 * Return: The value 0
 */

int main(void)
{
int i, j, k, l, p, q;

for (i  = '0'; i <= '9'; i++)
{
	for (j = '0'; j <= '9'; j++)
	{
		for (k = '0'; k <= '9'; k++)
		{
			for (l = '0'; l <= '9'; l++)
			{
				p = (k * 10) + l;
				q = (i * 10) + j;
				if (q < p)
				{
					putchar(i);
					putchar(j);
					putchar(' ');
					putchar(k);
					putchar(l);
					if (i == 9 && j == 8 && k == 9 && l == 9)
					{
						break;
					}
					putchar(',');
					putchar(' ');
				}
			}

		}
	}
}
	putchar('\n');
	return (0);
}
