#include "lists.h"

/**
 * *add_node - adds a new node at the beginning of a list_t list
 * @head: a pointer to the head of a list_t list
 * @str: a pointer to the new node to be added
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;
	size_t leng = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->str = strdup(str);
	while (str[leng])
	{
		leng++;
	}
	newnode->len = leng;
	newnode->next = *head;
	*head = newnode;
	return (newnode);

}
