CC=gcc
CFLAGS=-Wall -std=c11
ASM = nasm
OBJS=asmpow.o asmpow.c.o
Target=potega

potega: $(OBJS)
	$(CC) $(CFLAGS) -o potega $(OBJS)

asmpow.c.o: asmpow.c
	$(CC) $(CFLAGS) -o asmpow.c.o -c asmpow.c

asmpow.o: asmpow.asm
	$(ASM) -f elf64 asmpow.asm

.PHONY: clean
clean:
	rm -f *.o potega
