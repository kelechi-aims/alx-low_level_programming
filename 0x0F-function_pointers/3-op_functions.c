#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * op_add - sums two integer
 * @a: first parameter
 * @b: second parameter
 * Return: interger
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: first parameter
 * @b: second parameter
 * Return: integer
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integers
 * @a: first parameter
 * @b: second parameter
 * Return: integer
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: first parameter
 * @b: second parameter
 * Return: integer
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}
/**
 * op_mod - returns the remainder of the division of a and b
 * @a: first parameter
 * @b: second parameter
 * Return: integer
 */
int op_mod(int a, int b)
{
	 if (b == 0)
	 {
		printf("Error\n");
		exit(100);
	 }
	return (a % b);
}
