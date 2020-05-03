#include "../inc/Generator.h"

Generator::Generator(std::vector<Topic* > topics) {
   char Top[] = {
         "abcdefghijklmnopqrstuvwxyz"
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
         "0123456789"
   };

   str = new char[msgSize];

   for (unsigned int i = 0 ; i < msgSize ; i++) {
         str[i] = Top[rand()%(sizeof(Top)-1)];
   }

   unsigned int id  = rand()%topics.size() + 1 ;

   for (Topic* topic : topics) {
      topic->get_message(str, msgSize, id);
   }
   
   std::cout << "-------notification's ID: ----------[" << id << "] ---------------"<< std::endl;
}

Generator::~Generator() {
   delete[] str;
}