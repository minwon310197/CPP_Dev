#include "../inc/Topic.h"

Topic::Topic(unsigned int ID) {
    TopicID = ID;
}


void Topic::add_fd(int socket_fd) {
    _fdList.push_back(socket_fd);
}

void Topic::remove_fd(int pos, int socket_fd) {
    auto iterator = std::find(_fdList.begin() ,_fdList.end() ,socket_fd);
    
    if (iterator != _fdList.end()) {
        _fdList.erase(iterator);
    }

    std::cout << "From Topic[" << TopicID << "], client[" << pos << "] removed !" << std::endl ;
}

bool Topic::check_exist(int socket_fd) {
    bool tempcheck;

    auto iterator = std::find(_fdList.begin() ,_fdList.end() ,socket_fd);

    if (iterator != _fdList.end()) {
        tempcheck = true;
    }
    else {
        tempcheck = false;
    }

    return tempcheck;
}
