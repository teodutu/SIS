CFLAGS = -Wall -m32
LDFLAGS = -m32
LDLIBS = -lseccomp

.PHONY: all clean

all: exec

exec: exec.o

clean:
	-rm -f *~
	-rm -f peda-session*.txt
	-rm -f exec.o
	-rm -f exec
