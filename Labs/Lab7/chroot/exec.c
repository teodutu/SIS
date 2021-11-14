#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define A_PATH		"a.txt"
#define B_PATH		"../b.txt"

int main()
{
	int fd1, fd2;

	fd1 = open(A_PATH, O_RDONLY);
	if (fd1 < 0)
		fprintf(stderr, "Could not open file %s\n", A_PATH);

	fd2 = open(B_PATH, O_RDONLY);
	if (fd2 < 0)
		fprintf(stderr, "Could not open file %s\n", B_PATH);

	return 0;
}
