#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: argumenat counter
 * @argv: argument vector
 * Return: integer
 */
int main(int argc, char *argv[])
{
	int number_of_bytes, i;
	unsigned char *fun;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	number_of_bytes = atoi(argv[1]);
	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	fun = (unsigned char *)main;
	for (i = 0; i < number_of_bytes; i++)
	{
		printf("%02x ", fun[i]);
	}
	printf("\n");
	return (0);
}
