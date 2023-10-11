#include "search_algos.h"

/**
 * advanced_recursive - Recursive helper function for
 * advanced binary search
 * @array: Pointer to the first element of the array to search in
 * @size: size of the array
 * @value: Value to search for
 * Return: Index of the value if found
 */
int advanced_recursive(int *array, size_t size, int value)
{
	size_t i;
	size_t mid = size / 2;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array");
	for (i = 0; i < size; i++)
	{
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);		}
	printf("\n");
	if (mid && size % 2 == 0)
		mid--;

	if (array[mid] == value)
	{
		if (mid > 0)
			return (advanced_recursive(array, mid + 1, value));
		return ((int)mid);
	}
	if (array[mid] > value)
		return (advanced_recursive(array, mid + 1, value));
	mid++;
	return (advanced_recursive(array + mid, size - mid, value) + mid);
}

/**
 * advanced_binary - Searches for a value in a sorted array using
 * advanced binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the value if found, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = advanced_recursive(array, size, value);

	if (i >= 0 && array[i] != value)
		return (-1);
	return (i);
}
