#include <stdio.h>
#include <stdlib.h>

/* global test variable */
static size_t g = 0;

static void axeoth(void)
{
	puts("chieftain");
}

static void erathia(void)
{
	system("/bin/ls");
}

static void enroth(void)
{
	if (g == 0xc001face)
		system("/bin/sh");
}

static void reader(void)
{
	char buffer[64];

	printf("fill global variable: ");
	scanf("%zu", &g);

	printf("gimme message: ");
	fgets(buffer, 128, stdin);
	printf("hello, %s\n", buffer);
}

int main(void)
{
	puts("hello, heroes!");

	reader();

	return 0;
}
