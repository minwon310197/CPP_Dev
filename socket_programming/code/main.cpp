#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "src/Topic.cpp"
#include <vector>

#define PORT 8080
#define MSG_LENGTH 1024

int main(int argc, char* argv[]) {
    Topic Topic1(1), Topic2(2), Topic3(3);
    std::vector<Topic* > topiclist;
    topiclist.push_back(&Topic1);
    topiclist.push_back(&Topic2);
    topiclist.push_back(&Topic3);

    int master_socket, addrlen, i, valread, counter = 0;
    int max_fd;
    int max_clients = 30;
    int client_socket[max_clients];
    char buffer[MSG_LENGTH];
    char message[] = " Connected to Server. \r\n";

    for (i = 0 ; i < max_clients ; i++) {
        client_socket[i] = 0;
    }

    if ( (master_socket = socket(AF_INET, SOCK_STREAM, 0) ) == -1) {
        std::cout << "socket failed";
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons (PORT);

    if (bind(master_socket, (struct sockaddr* ) &address, sizeof(address)) < 0 ) {
        std::cout << "bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Listener on port " << PORT << std::endl;

    if (listen(master_socket, 6) < 0) {
        std::cout << "listen failed" ;
        exit(EXIT_FAILURE);
    }

    addrlen = sizeof(address);
    std::cout << "waiting for connections...\n";

    while(1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(master_socket, &readfds);
        max_fd = master_socket;

        for (i = 0 ; i < max_clients ; i++) {
            int fd = client_socket[i];

            if(fd > 0) {
                FD_SET(fd, &readfds);
            }

            if(fd > max_fd) {
                max_fd = fd;
            }
        }

        std::cout << "waiting for update...." << std::endl;
        select(max_fd + 1, &readfds, NULL, NULL, NULL);

        std::cout << " ~~~~~~~~~~~~~~updated [" << counter++ << "]" << std::endl;

        if (FD_ISSET(master_socket, &readfds)) {
            int new_socket = 0;

            if ((new_socket = accept(master_socket, (struct sockaddr* ) &address, (socklen_t*) &addrlen)) < 0) {
                std::cout << "accept error !" ;
                exit(EXIT_FAILURE);
            }

            std::cout << "NEW CONNECTION |SOCKET_FD:" << new_socket << " |IP:" << inet_ntoa(address.sin_addr) << " |PORT:" << ntohs(address.sin_port) << std::endl;

            if(send(new_socket, message, strlen(message), 0) != ssize_t(strlen(message))) {
                std::cout << " !ErroR! " ;
            }

            puts("Connected to Client !");

            for(i = 0 ; i < max_clients ; i++) {

            if (client_socket[i] == 0) {
                client_socket[i] = new_socket;
                std::cout << "adding to list of sockets as " << i << std::endl;
                break;
            }
            }
        }

        for (i = 0 ; i < max_clients ; i++) {
            int fd = client_socket[i];
            //
            if (FD_ISSET(fd, &readfds)) {

                if ((valread = read(fd, buffer, MSG_LENGTH)) == 0) {                    

                    for ( Topic* topic : topiclist ) {
                        if (topic->check_exist(fd)) {
                            topic->remove_fd(i,fd);
                        }
                    }

                    getpeername(fd, (struct sockaddr* ) &address, (socklen_t*) &addrlen);
                    std::cout << "Host disconnected, ip " << inet_ntoa(address.sin_addr) << ", port " << ntohs(address.sin_port) << ", position: " << i << std::endl;
                    close(fd);
                    client_socket[i] = 0;
                    std::cout << std::endl;
                }
                else {
                    buffer[valread] = '\0';
                    // client subscribe
                    if ((strncmp(buffer,"subscribe",9)) == 0) {
                        char SUBSCRIBE[] = "subscribe";
                        char counter = '0';

                        for ( unsigned int count = 0 ; count < topiclist.size() ; count++) {
                            SUBSCRIBE[9] = ++counter;

                            if ((strncmp(buffer,SUBSCRIBE,10)) == 0) {
                                
                                if (topiclist[count]->check_exist(fd)) {
                                    send(fd,"Error: Already subsribed !.. ",29,0);
                                }
                                else {
                                    send(fd,"~~ subscribed ~~ ",17,0);
                                    topiclist[count]->add_fd(fd);
                                }
                                
                            }                            
                             
                        }
                        break;

                    }
                    // client publish
                    if ((strncmp(buffer,"publish",7)) == 0) {

                        char PUBLISH[] = "publish";
                        char TOPIC[] = "topic";
                        
                        char counter = '0';

                        for ( unsigned int count = 0 ; count < topiclist.size() ; count++) {
                            PUBLISH[7] = ++counter;


                            if ((strncmp(buffer,PUBLISH,8)) == 0) {
                            TOPIC[5] += counter ;
                                if (topiclist[count]->check_exist(fd)) {
                                    char tempBuffer[MSG_LENGTH];

                                    for( int H = 8 ; H < valread ; H++ ) {
                                        tempBuffer[H-8] = buffer[H];
                                    }

                                    for (unsigned int G = 0 ; G < topiclist[count]->_fdList.size() ; G++) {
                                        send(topiclist[count]->_fdList[G],TOPIC,6 , 0); 
                                        send(topiclist[count]->_fdList[G],tempBuffer,(valread-8), 0);
                                    }
                                }
                                else {
                                    send(fd,"Published without Subscribe.. ",30,0);

                                    char tempBuffer[MSG_LENGTH];

                                    for( int H = 8 ; H < valread ; H++ ) {
                                        tempBuffer[H-8] = buffer[H];
                                    }

                                    for (unsigned int G = 0 ; G < topiclist[count]->_fdList.size() ; G++) {
                                        send(topiclist[count]->_fdList[G],TOPIC,6 , 0); 
                                        send(topiclist[count]->_fdList[G],tempBuffer,(valread-8), 0);
                                    }

                                }

                            }                            
                             
                        }

                        break;
                    }
                    // client exit 
                    if ((strncmp(buffer,"exit",4)) == 0) {
                        send(fd,"exit",4,0);
                        break;
                    }
                    // default
                    send(fd,"\n~~ Avaiable Function : subscribe,publish,exit ~~\n",47,0);
                }
            }
        }
    }
    return 0;
}
