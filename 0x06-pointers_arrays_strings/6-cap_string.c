#include "main.h"

/**
 * *cap_string - capitalizes all words of a string
 * @str: string parameter
 * use of ascii code to reduce code line
 * Return: string
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		if (septor(str[i]) && (str[i + 1] >= 'a') && (str[i + 1] <= 'z'))
		{
			str[i + 1] = str[i + 1] - 32;
		}
		i++;
	}
	return (str);
}

/**
 * septor - words seperator function
 * @a: words seperator
 *
 * Return: 1 or 0
 */
int septor(char a)
{
	int j = 0;
	int septor[] = {32, 9, 10, 44, 59, 46, 33, 63, 34, 40, 41, 123, 125};

	while (j < 13)
	{
		if (a == septor[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}
