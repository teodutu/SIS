#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* byte string shellcode */
static const char shellcode[] = "\x6a\x01\xfe\x0c\x24\x68\x2e\x74\x78\x74\x68"
	"\x2e\x2e\x2f\x62\x89\xe3\x31\xc9\x31\xd2\x6a\x05\x58\xcd\x80\x6a\x74"
	"\x68\x61\x2e\x74\x78\x68\x61\x69\x6c\x2f\x68\x2e\x2e\x2f\x6a\x89\xe3"
	"\x31\xc9\x31\xd2\x6a\x05\x58\xcd\x80\xeb\x1b\x59\xba\x0e\x00\x00\x00"
	"\xbb\x01\x00\x00\x00\xb8\x04\x00\x00\x00\xcd\x80\x31\xdb\xb8\x01\x00"
	"\x00\x00\xcd\x80\xe8\xe0\xff\xff\xff\x48\x65\x6c\x6c\x6f\x2c\x20\x57"
	"\x6f\x72\x6c\x64\x21\x0a\x00";

int main()
{
	void (*func_ptr)(void) = (void (*)(void)) shellcode;

	/* Call shellcode. */
	func_ptr();

	return 0;
}
