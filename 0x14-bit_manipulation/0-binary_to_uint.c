#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a binary number to be converted to unsigned int
 * Return: the converted number, or 0 if it fails
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, con_num = 0;

	if (b == NULL)
	{
		return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
		con_num = con_num * 2 + (b[i] - '0'); 
	}
	return (con_num);
}
