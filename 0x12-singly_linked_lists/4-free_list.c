#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: a pointer to the head of the list_t list
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *newnode;

	while (head != NULL)
	{
		newnode = head->next;
		free(head->str);
		free(head);
		head = newnode;
	}
}
