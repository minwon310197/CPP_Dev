CC=g++

CFLAGS= -c -Wall

all: server client

server: main.o
	$(CC) main.o -o server

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp 

client: src/Client.o
	$(CC) src/Client.o -o client -lpthread

Client.o: src/Client.cpp
	$(CC) $(CFLAGS) src/Client.cpp 

clean: 
	rm -rf *o main server 
	rm -rf *o Client client src/Client.o
