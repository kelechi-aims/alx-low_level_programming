#include "main.h"

/**
 * *_strstr - locates a substring in a haystack
 * @haystack: the string to look into
 * @needle: the substring to look for
 * Return: a pointer or null
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;

	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*haystack)
	{
		if (haystack[i] == needle[i])
		{
			for (; needle[i + 1] == '\0'; i++)
			{
				return (haystack);
			}
		}
		haystack++;
	}
	return ('\0');
}
