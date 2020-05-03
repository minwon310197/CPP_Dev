#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "Topic.h"
#include <mutex>

class Client {
public:
   Client(unsigned int id);
   ~Client();
   virtual void update() ;
   unsigned int getClientID() ;
   void subscribeTopic(Topic* subcrTopic) ;
   void unsubscribeTopic(Topic* subcrTopic) ;

private:
   std::vector<Topic* > subscrTopicS;
   unsigned int _clientid;
   std::mutex mu;
};

#endif //CLIENT_H
