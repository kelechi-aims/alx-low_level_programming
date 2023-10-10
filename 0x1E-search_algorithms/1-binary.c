#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	int left = 0;
	int right = size - 1;
	int mid, i;

	if (array == NULL)
	{
		return (-1);
	}
	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i <= right; ++i)
		{
			printf("%d", array[i]);
			if (i < right)
			{
				printf(", ");
			}
		}
		printf("\n");
		mid = left + (right - left) / 2;
		if (array[mid] == value)
		{
			return (mid);
		}
		if (array[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (-1);
}
