#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mega_checker(unsigned int a, unsigned int b)
{
	if (a == 0x88776655 && b == 0xaabbccdd)
		puts("Uberihahaha!");
}

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
	fgets(name, 120, stdin);
	printf("Hello, %s", name);
	return 0;
}
