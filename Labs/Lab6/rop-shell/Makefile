CFLAGS = -Wall -fno-stack-protector -Wno-unused-function -mpreferred-stack-boundary=3 -fno-PIC
LDFLAGS = -no-pie

.PHONY: all clean

all: vuln

vuln: vuln.o

vuln.o: vuln.c

clean:
	-rm -f *~ *.o
	-rm -f vuln
