#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *argstostr - concatenates all the arguments of your program
 * @ac: argument counter
 * @av: argument vector
 * Return: a pointer or NULL
 */
char *argstostr(int ac, char **av)
{
	int i, j = 0, len = 0;
	char *dest;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		len += strlen(av[i]) + 1;
	}
	dest = (char *) malloc(sizeof(char) * len + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		strcpy(dest + j, av[i]);
		j += strlen(av[i]);
		dest[j++] = '\n';
	}
	dest[j] = '\0';
	return (dest);
}
