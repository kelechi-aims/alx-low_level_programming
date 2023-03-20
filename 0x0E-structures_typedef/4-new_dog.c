#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * *new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: dog's owner
 * Return: dog_t type
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int len1, len2;

	if (name == NULL || owner ==  NULL)
	{
		return (NULL);
	}
	len1 = strlen(name) + 1;
	len2 = strlen(owner) + 1;
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return (NULL);
	}
	new_dog->name = malloc(sizeof(len1));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_dog->owner = malloc(sizeof(len2));
	if (new_dog->owner == NULL)
	{
		free(new_dog);
		free(new_dog->name);
		return (NULL);
	}
	strcpy(new_dog->name, name);
	strcpy(new_dog->owner, owner);
	new_dog->age = age;
	return (new_dog);
}
