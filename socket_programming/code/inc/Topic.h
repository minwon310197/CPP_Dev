#ifndef TOPIC_H
#define TOPIC_H

#include <vector>
#include <iostream>
#include <algorithm>

class Topic {
public:
    Topic(unsigned int ID);
    void add_fd(int socket_fd);
    void remove_fd(int pos, int socket_fd);
    bool check_exist(int socket_fd);
    std::vector<int > _fdList;
    unsigned int TopicID;
private: 
    char* _msg;
    unsigned int _msgsize;
};

#endif //TOPIC_H
