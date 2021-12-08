#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char *endp;
	float f = strtof(argv[1], &endp);

	if( f >= 0 )
		printf("No luck, it's bigger!\n");
	else if( f < 0 )
		printf("No luck, it's smaller!\n");
	else
	{
		printf("Ah... Just perfect!\n");
		system("/bin/bash");
	}
		
	return 0;
}
