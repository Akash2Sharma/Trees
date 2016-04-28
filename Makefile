# Makefile for SP2013/SectionD/examples/Completed_Trees
CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

.PHONY: clean 

all : trees

clean :
	rm -f *.o  *~ trees tst
	rm -rf *.dSYM

trees: ui.o trees.o main.o
	gcc $(CFLAGS) -o trees ui.o trees.o main.o $(LIBS)

test : test.c ui.o trees.o
	gcc $(CFLAGS) -o tst ui.o trees.o test.c

main.o : ui.o trees.o main.c trees.h ui.h
	gcc $(CFLAGS) -c main.c

ui.o : trees.o ui.c ui.h trees.h
	gcc $(CFLAGS) -c ui.c

trees.o : trees.c trees.h
	gcc $(CFLAGS) -c trees.c
