CC = gcc
OBJ = main.o dllist.o

all: test

test: $(OBJ)
	$(CC) -o test $(OBJ)

main.o: main.c dllist.h
	$(CC) -o main.o -c main.c

dllist.o: dllist.c dllist.h
	$(CC) -o dllist.o -c dllist.c



