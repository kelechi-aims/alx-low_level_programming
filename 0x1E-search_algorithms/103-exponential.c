#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of
 * integers using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located, -1 otherwise
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t left, right, mid, i;
	size_t b = 1;

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	while (b < size && array[b] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", b, array[b]);
		b *= 2;
	}
	left = b / 2;
	right = (b < size - 1) ? b : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	while (left <= right)
	{
		mid = (left + right) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; ++i)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");
		if (array[mid] == value)
			return ((int)mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("Value checked array[%lu] is out of range\n", right);
	return (-1);
}
