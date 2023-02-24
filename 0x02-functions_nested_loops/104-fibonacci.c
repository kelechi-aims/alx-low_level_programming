#include <stdio.h>

/**
 * main - finds and prints the first 98 fibonacci numbers
 * Description: starting with 1 and 2, followed by a new line
 * Return: value 0
 */

int main(void)
{
	int i;
	unsigned long fn = 0, sn = 1, fb;
	unsigned long n1, n2, n3, n4;
	unsigned long sum1, sum2;

	for (i = 0; i < 92; i++)
	{
		fb = fn + sn;
		printf("%lu, ", fb);
		fn = sn;
		sn = fb;
	}
	n1 = fn / 10000000000;
	n2 = fn % 10000000000;
	n3 = sn / 10000000000;
	n4 = sn % 10000000000;
	for (i = 93; i < 99; i++)
	{
		sum1 = n1 + n3;
		sum2 = n2 + n4;
		if ((n2 + n4) > 9999999999)
		{
			sum1 += 1;
			sum2 %= 10000000000;
		}
		printf("%lu%lu", sum1, sum2);
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
