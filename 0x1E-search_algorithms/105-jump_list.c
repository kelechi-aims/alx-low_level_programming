#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list using
 * Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 * Return: Pointer to the first node where value is located, or NULL otherwise
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, index, j;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	jump = (size_t)sqrt((double)size);
	index = 0;
	j = 0;

	do {
		prev = list;
		j++;
		index = j * jump;
		while (list->next && list->index < index)
			list = list->next;
		if (list->next == NULL && index != list->index)
			index = list->index;
		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);
	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}
	return (NULL);
}
