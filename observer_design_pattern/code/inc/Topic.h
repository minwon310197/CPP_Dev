#ifndef TOPIC_H
#define TOPIC_H

#include <vector>
#include <iostream>
#include <algorithm>

class Topic {
public:
   Topic(unsigned int ID);
   void notifyClients() ;
   unsigned int get_id();
   void get_message(char* msg,unsigned int msgsize, unsigned int ID);
   unsigned int get_msgID();

private:
   unsigned int TopicID;
   char* _msg;
   unsigned int _msgsize;
   unsigned int _msgID;   
};

#endif //TOPIC_H
