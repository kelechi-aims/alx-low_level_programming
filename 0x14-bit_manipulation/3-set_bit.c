#include "main.h"

/**
 * set_bit - sets a the value of a bit to 1 at a given index
 * @n: a pointer to the given number
 * @index: index to set bit to 1 of the n
 * Return: 1 if it worked, or -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1 << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n |= m;
	return (1);
}
