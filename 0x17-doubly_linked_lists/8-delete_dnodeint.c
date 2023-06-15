#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head node of the list
 * @index: the index of the node that should be deleted. index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *past;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}
	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}
	for (i = 0; current != NULL && i < index; i++)
	{
		past = current;
		current = current->next;
	}
	if (current == NULL)
	{
		return (-1);
	}
	past->next = current->next;
	if (current->next != NULL)
	{
		current->next->prev = past;
	}
	free(current);
	return (1);
}
