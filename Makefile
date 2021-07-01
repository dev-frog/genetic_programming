CFLAGS=-Wall -ggdb -std=c11 -pedantic
LIBS=

gp: src/main.c
	$(CC) $(CFLAGS) -o gp src/main.c  $(LIBS)