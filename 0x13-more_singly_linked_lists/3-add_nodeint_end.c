#include "lists.h"

/**
 * *add_nodeint_end - addsa a new node at the end of a listin_t list
 * @head: a pointer tothe head node of a listint_t list
 * @n: integer value to be stored in the newly added node
 * Return: the address of the new element ,or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *temp;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;
	temp = *head;
	if (temp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return (newnode);
}
