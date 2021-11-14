CFLAGS = -Wall -m32 -g -fno-stack-protector -Wno-unused-function -mpreferred-stack-boundary=2 -fno-PIC
LDFLAGS = -no-pie -m32 -zexecstack

.PHONY: all clean

all: exec

exec: exec.o

clean:
	-rm -f *~
	-rm -f peda-session*.txt
	-rm -f exec.o
	-rm -f exec
