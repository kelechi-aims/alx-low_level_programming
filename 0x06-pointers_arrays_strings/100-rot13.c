#include "main.h"

/**
 * *rot13 - encodes a string using rot13
 * @s: string parameter
 *
 * Return: string
 */
char *rot13(char *s)
{
	int i = 0, j;
	char alphas[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (s[i] != '\0')
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == alphas[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
		i++;
	}
	return (s);
}
