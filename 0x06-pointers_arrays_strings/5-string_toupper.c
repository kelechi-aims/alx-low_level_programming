#include "main.h"

/**
 * *string_toupper - changes lowercase letters of a string to uppercase
 * @*: the function takes a character parameter
 *
 * Return: character
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
