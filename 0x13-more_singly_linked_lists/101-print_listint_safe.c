#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: a pointer to the head node of listint_t list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *temp = head;

	while (temp != NULL)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;
		if (temp <= temp->next)
		{
			printf("-> [%p] %d\n", (void *)temp->next, temp->next->n);
			exit(98);
		}
		temp = temp->next;
	}
	return (count);
}
