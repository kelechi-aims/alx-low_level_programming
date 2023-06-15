#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data(n) of a dlistint_t linked list
 * @head: points to the head node of the list
 * Return: 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
