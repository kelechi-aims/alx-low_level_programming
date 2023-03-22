#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main -performs operation with command arguments
 * @argc: argument counter
 * @argv: argument vector
 * Return: integer
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	char *operator;
	int (*fun)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operator = argv[2];
	fun = get_op_func(operator);
	if (fun == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", fun(num1, num2));
	return (0);
}
