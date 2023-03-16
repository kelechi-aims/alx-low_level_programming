#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_number - checks if argument is number
 * @str: argument of the function
 * Return: integer
 */
int is_number(char *str)
{
	int i, len;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 * Return: integer
 */
int main(int argc,  char *argv[])
{
	int mul, num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (!is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	else
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		mul = num1 * num2;
		printf("%d\n", mul);
	}
	return (0);
}
