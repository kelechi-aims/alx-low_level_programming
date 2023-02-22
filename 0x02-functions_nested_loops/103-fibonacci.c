#include <stdio.h>

/**
 * main - prints the first 50 fibonacci numbers
 * Description: starting with 1 and 2
 * Return: value 0
 */

int main(void)
{
	long int fn, sn, fb, efb;

	fn = 1;
	sn = 2;
	fb = 2;
	efb = 2;
	while (fb <= 4000000)
	{
		fb = fn + sn;
		fn = sn;
		sn = fb;
		if ((fn % 2) == 0)
		{
			efb += fn;
		}
	}
	printf("%ld\n", efb);
	return (0);
}
