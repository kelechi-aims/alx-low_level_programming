#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to the head node of the listint_t list
 * Return: the size of list of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp = *h;
	size_t count = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		free_lists(temp);
		count++;
	}
	*h = NULL;
	return (count);

}

/**
 * free_listint - frees a listint_t list
 * @head: a pointer to the head node of listint_t list
 * Return: void
 */
void free_lists(listint_t *head)
{
	listint_t *newnode;

	while (head != NULL)
	{
		newnode = head;
		newnode = newnode->next;
		free(newnode);
		free_lists(newnode);
	}
	free(head);
}
