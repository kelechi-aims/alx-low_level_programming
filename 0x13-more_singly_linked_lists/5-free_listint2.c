#include "lists.h"

/**
 * free_listint2 - frees a listint_t list
 * @head: double pointer to the head node of listint_t list
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *first, *newnode;

	if (head == NULL || *head == NULL)
	{
		return;
	}
	first = *head;
	while (first != NULL)
	{
		newnode = first->next;
		free(first);
		first = newnode;
	}
	*head = NULL;
}
