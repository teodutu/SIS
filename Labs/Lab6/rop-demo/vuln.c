#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void checker(unsigned int a)
{
	if (a == 0x11223344)
		puts("ihahaha!");
}

int main(void)
{
	char name[32];

	printf("Tell me your name: ");
	fflush(stdout);
	fgets(name, 80, stdin);
	printf("Hello, %s", name);
	return 0;
}
