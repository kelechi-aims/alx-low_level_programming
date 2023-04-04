#include "lists.h"

/**
 * *reverse_listint - reserves a listint_t linked list
 * @head: double pointer to the head node of the listint_t list
 * Return: a pointer the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prenode, *temp, *postnode;

	prenode = NULL;
	temp = postnode = *head;
	while (postnode != NULL)
	{
		postnode = postnode->next;
		temp->next = prenode;
		prenode = temp;
		temp = postnode;
	}
	*head = prenode;
	return (prenode);
}
