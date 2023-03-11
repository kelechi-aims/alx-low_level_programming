#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money
 * @argc: argument counter
 * @argv: argument vector
 * Return: zero
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc == 1 || argc > 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
	}
	while (cents > 0)
	{
		coins++;
		if (cents >= 25)
		{
			cents -= 25;
			continue;
		}
		if (cents >= 10)
		{
			cents -= 10;
			continue;
		}
		if (cents >= 5)
		{
			cents -= 5;
			continue;
		}
		if (cents >= 2)
		{
			cents -= 2;
			continue;
		}
		if (cents >= 1)
		{
			cents -= 1;
			continue;
		}
	}
	printf("%d\n", coins);
	return (0);
}
