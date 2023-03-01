#include "main.h"

/**
 * reverse_array - reverse the content of an array of integers
 * @a: array of integers
 * @n: size of the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0, arr;
	
	while (i < n--)
	{
		arr = a[i];
		a[i++] =a[n];
		a[n] = arr;
	}
}
