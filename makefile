CC = gcc
CFLAGS = -g -Wall -g
build: tema
tema: tema3.c
	$(CC) -o tema3 tema3.c $(CFLAGS)
.PHONY : clean
clean :
	rm -f tema3
	rm -f *.out
