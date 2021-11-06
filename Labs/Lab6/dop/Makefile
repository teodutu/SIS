all: dop payload

.PHONY: all clean

CC = clang
CFLAGS = -static
#CFLAGS = -fsanitize=safe-stack

dop: dop.c
	$(CC) $(CFLAGS) -o $@ $<

payload: payload.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f dop payload *.o
