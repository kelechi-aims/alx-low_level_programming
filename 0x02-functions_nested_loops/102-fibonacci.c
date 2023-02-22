#include <stdio.h>

/**
 * main - prints the first 50 fibonacci numbers
 * Description: starting with 1 and 2
 * Return: value 0
 */

int main(void)
{
	int n;
	long int fn, sn, fb;

	fn = 1;
	sn = 2;
	fb = fn + sn;

	printf("%ld, %ld", fn, sn);
	for (n = 2; n < 50; ++n)
	{
		fb = fn + sn;
		printf(", %ld", fb);
		fn = sn;
		sn = fb;
	}
	printf("\n");
	return (0);


}
