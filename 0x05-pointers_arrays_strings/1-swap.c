#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: first parameter of the function prototype
 * @b: second parameter of the function prototype
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
