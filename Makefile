PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config -cflags sdl2`
LIBS=`pkg-config -libs sdl2`

gp: src/main.c src/triangle.h src/triangle.c src/style.h
	$(CC) $(CFLAGS) -o gp src/main.c  src/triangle.c $(LIBS)