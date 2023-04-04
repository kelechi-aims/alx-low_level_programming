#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of
 * a listint_t linked list
 * @head: double pointer to the head node to listint_t list
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 it if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *postnode, *temp;
	unsigned int i = 1;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	postnode = *head;
	while (postnode != NULL && i < index)
	{
		postnode = postnode->next;
		i++;
	}
	if (postnode == NULL || postnode->next == NULL)
	{
		return (-1);
	}
	temp = postnode->next;
	postnode->next = temp->next;
	free(temp);
	return (1);
}
