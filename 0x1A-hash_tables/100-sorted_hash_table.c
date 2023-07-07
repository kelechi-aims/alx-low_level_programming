#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the array
 * Return: a pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(shash_table_t));
	if (hash_table == NULL)
	{
		return (NULL);
	}
	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_table_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		hash_table->array[i] = NULL;
	}
	hash_table->shead = NULL;
	hash_table->stail = NULL;
	return (hash_table);

}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the sorted hash table you want to add or update the key/value to
 * @key: the key and this key can not be an empty string.
 * @value: the value associated with the key. value must be duplicated
 * value can not be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	new_node->sprev = NULL;
	new_node->snext = NULL;
	ht->array[index] = new_node;
	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		new_node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		node = ht->shead;
		while (node->snext != NULL && strcmp(key, node->snext->key) > 0)
			node = node->snext;
		new_node->sprev = node;
		new_node->snext = node->snext;
		if (node->snext != NULL)
			node->snext->sprev = new_node;
		node->snext = new_node;
	}
	if (ht->stail == NULL || strcmp(key, ht->stail->key) > 0)
		ht->stail = new_node;
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: is the sorted hash table you want to look into
 * @key: is the key you are looking for
 * Return: the value associated with element,
 * or NULL if the key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			return (node->value);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	int first = 1;
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (first)
		{
			first = 0;
		}
		else
		{
			printf(", ");
		}
		printf("'%s': '%s'", node->key, node->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table in reverse order
 * @ht: te sorted hash table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (first)
		{
			first = 0;
		}
		else
		{
			printf(", ");
		}
		printf("'%s': '%s'", node->key, node->value);
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *temp_node;

	if (ht == NULL)
	{
		return;
	}
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp_node = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp_node;
		}
	}
	free(ht->array);
	free(ht);
}
