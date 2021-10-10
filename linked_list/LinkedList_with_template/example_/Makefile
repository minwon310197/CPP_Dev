CC=g++

CFLAGS= -c -Wall

all: program

program: main.o
	$(CC) main.o -o program

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean: 
	rm -rf *o main program 
