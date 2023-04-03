#include "lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: a pointer to the head node of listint_t list
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *newnode;

	while (head != NULL)
	{
		newnode = head->next;
		free(head);
		head = newnode;
	}
}
