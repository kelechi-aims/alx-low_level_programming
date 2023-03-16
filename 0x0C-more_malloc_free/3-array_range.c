#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: integer parameter
 * @max: integer parameter
 * Return: a ponter
 */
int *array_range(int min, int max)
{
	int *arr;
	int size, i;

	if (min > max)
	{
		return (NULL);
	}
	size = max - min + 1;
	arr = (int *) malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
