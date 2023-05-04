#include "main.h"

/**
 * clear_bit - sets the value of a bit to zero at a given index
 * @n: a pointer to the number
 * @index: bit index to set to zero
 * Return: 1 if it workeds, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1 << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n &= ~m;
	return (1);
}
