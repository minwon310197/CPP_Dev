#include "../inc/Topic.h"

unsigned int Topic::get_id() {
   return TopicID;
}

Topic::Topic(unsigned int ID) {
   TopicID = ID;
}

unsigned int Topic::get_msgID() {
   return _msgID;
}

void Topic::notifyClients() {

   if (get_id() == _msgID) {      
      std::cout << " From Topic[" << get_id() << "] :" ;

      for(unsigned int i = 0 ; i < _msgsize ; i++) {
         std::cout << _msg[i] ;
      }

      std::cout << std::endl;
   }

}

void Topic::get_message(char* msg,unsigned int msgsize, unsigned int ID) {

   if ( TopicID == ID ) {
   _msg = msg;
   _msgID = ID;
   _msgsize = msgsize;
   }
   else {
      _msgID = 0;
   }

}
