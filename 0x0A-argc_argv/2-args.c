#include <stdio.h>

/**
 * main - prints all arguments it receives
 * @argc: argument count
 * @argv:  argument vector
 * Return: zero
 */
int main(int argc, char *argv[])
{
	int i = 0;

	if (argc > 0)
	{
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			i++;
		}
	}
	return (0);
}
