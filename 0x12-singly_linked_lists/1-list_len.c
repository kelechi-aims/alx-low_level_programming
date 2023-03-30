#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t lists
 * @h: pointer to the head of the list_t list
 * Return: number of elements in list_t list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	return (len);
}

