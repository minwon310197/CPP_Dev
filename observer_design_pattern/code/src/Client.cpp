#include "../inc/Client.h"

Client::Client(unsigned int id) {
   _clientid = id ;
}

Client::~Client() {}

unsigned int Client::getClientID() {
   return _clientid;
}

void Client::update() {

   int status = 0;
   
   for (Topic* subcrTopic : subscrTopicS) {
      status += subcrTopic->get_msgID() ;
   }

   if (status != 0) {

      std::cout << "Client[" << _clientid << "]" << std::endl;

      for (Topic* subcrTopic : subscrTopicS) {
         std::lock_guard<std::mutex> lock{mu};
         subcrTopic->notifyClients();
      }

   }
   
}

void Client::unsubscribeTopic(Topic* subcrTopic) {
   auto iterator = std::find(subscrTopicS.begin() ,subscrTopicS.end() ,subcrTopic);

   if (iterator != subscrTopicS.end()) {
      subscrTopicS.erase(iterator);
   }

}

void Client::subscribeTopic(Topic* subcrTopic) {
   subscrTopicS.push_back(subcrTopic);
}
