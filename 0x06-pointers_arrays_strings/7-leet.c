#include "main.h"

/**
 * *leet - encodes a string into 1337
 * @s: string parameter
 *
 * Return: char
 */
char *leet(char *s)
{
	int i = 0, j;
	int lower[] = {'a', 'e', 'o', 't', 'l'};
	int upper[] = {'A', 'E', 'O', 'T', 'L'};
	int numb[] = {'4', '3', '0', '7', '1'};

	while (s[i] != '\0')
	{
		for (j = 0; j < 5; j++)
		{
			if ((s[i] == lower[j]) || (s[i] == upper[j]))
			{
				s[i] = numb[j];
			}
		}
		i++;
	}
	return (s);

}
