#include <stdio.h>

/*Declaration of the b_main funtion using constructor*/
void without_main(void) __attribute__((constructor));

/**
 * without_main - prints a text before the main function is executed
 */
void without_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
