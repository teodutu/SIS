#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void make_it_easy(void)
{
	system("ls");
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
