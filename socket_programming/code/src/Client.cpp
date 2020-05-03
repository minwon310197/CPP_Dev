#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#define MSG_LENGTH 1024
#define PORT 8080

#include <stdlib.h>
#include <thread>

void listenfunction(int socket_client) {
    while(1) {
        char message[MSG_LENGTH];

        bzero(message, sizeof(message));
        int msglength = read(socket_client, message, sizeof(message));
        std::cout << message << std::endl ;

        if ((strncmp(message,"exit",4)) == 0) {
            std::cout << "~~~ Client exit ~~~\n" ;
            close(socket_client);
            exit(EXIT_SUCCESS);
        }

    }
}

void writefunction(int socket_client) {
    while(1) {

        char message[MSG_LENGTH];
        bzero(message, sizeof(message));
        int n = 0;
 
        while ((message[n++] = getchar()) != '\n' ) ;
 
        send(socket_client, message, sizeof(message),0);
    }
}

int main() {
    int socket_client;
    struct sockaddr_in serverAddr;

    socket_client = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_client == -1) {
        std::cout << "socket creation failed..\n" ;
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Socket successfully created..\n" ;
    }

    bzero(&serverAddr, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(PORT);

    if (connect(socket_client, (struct sockaddr* )&serverAddr, sizeof(serverAddr)) != 0) {
        std::cout << "connection failed ...please check server status ! \n " ;
        exit(EXIT_FAILURE);
    }

    std::thread writeThread(writefunction,socket_client);
    std::thread readThread(listenfunction,socket_client);
    readThread.join();

    close(socket_client);
    return 0;
}
