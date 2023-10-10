#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located, -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	int left = 0;
	int right = 0;
	int i;
	int jump = sqrt(size);

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	while (right < (int)size && array[right] < value)
	{
		printf("Value checked array[%d] = [%d]\n", right, array[right]);
		left = right;
		right += jump;
	}
	printf("Value found between indexes [%d] and [%d]\n", left, right);
	for (i = left; i <= right && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
