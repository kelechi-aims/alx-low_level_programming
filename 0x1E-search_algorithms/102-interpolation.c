#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 * of integers using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located, -1 otherwise
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low = 0, high = size - 1;
	double slope;
	size_t offset;

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	while (low <= high && value >= array[low] && value <= array[high])
	{
		slope = (double)(high - low) / (array[high] - array[low]);
		offset = (size_t)(slope * (value - array[low]));

		pos = low + offset;
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
		{
			return ((int)pos);
		}
		if (array[pos] < value)
		{
			low = pos + 1;
		}
		else
		{
			high = pos - 1;
		}
	}
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}

