#include <stdio.h>

/**
 * main - finds and prints the first 98 fibonacci numbers
 * Description: starting with 1 and 2, followed by a new line
 * Return: value 0
 */

int main(void)
{
	int i;
	long fn = 1, sn = 2, fb;
	long n1, n2, n3, n4, sum1, sum2;

	for (i = 1; i < 80; ++i)
	{
		fb = fn + sn;
		printf("%ld, ", fb);
		fn = sn;
		sn = fb;
	}
	n1 = fn / 10000000000;
	n2 = fn % 10000000000;
	n3 = sn / 10000000000;
	n4 = sn % 10000000000;
	for (i = 81; i < 98; ++i)
	{
		sum1 = n1 + n3;
		sum2 = n2 + n4;
		if ((n2 + n4) > 999999999)
		{
			sum1 += 1;
			sum2 %= 10000000000;
		}
		printf("%ld%ld", sum1, sum2);
		if (i != 98)
		{
			printf(", ");
		}
		n1 = n3;
		n2 = n4;
		n3 = sum1;
		n4 = sum2;
	}
	printf("\n");
	return (0);
}
