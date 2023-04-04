#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head neode of listint_t list
 * @idx: index at where to insert the new node
 * @n: integer to be stored at the inserted node
 * Return: address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *temp;
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	temp = *head;
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->next = temp->next;
	temp->next = newnode;
	return (newnode);
}
