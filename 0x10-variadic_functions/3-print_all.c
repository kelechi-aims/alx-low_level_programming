#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: list of variable data types
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int j = 0;
	char *s;
	va_list ap;

	va_start(ap, format);
	while (format[j] != '\0')
	{
		switch (format[j])
		{
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s == NULL)
				{
					printf("(nil)");
					break;
				}
				printf("%s", s);
				break;
		}
		if ((format[j] == 'i' || format[j] == 'c' || format[j] == 'f'
					|| format[j] == 's')  && format[(j + 1)] != '\0')
			printf(", ");
		j++;
	}
	printf("\n");
	va_end(ap);
}
