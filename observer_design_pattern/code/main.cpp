#include <iostream>
#include <thread>
#include "src/Topic.cpp"
#include "src/Client.cpp"
#include "src/Generator.cpp"
#include <vector>
#include <mutex>

using namespace std;

void threadClient1(Client& one) { 
   one.update();
}

void threadClient2(Client& two) {
   two.update();
}

void threadClient3(Client& three) {
   three.update();
}

void threadClient4(Client& four) { 
   four.update();
}

void threadClient5(Client& five) { 
   five.update();
}

int main() {
   Topic TopicA(1),TopicB(2),TopicC(3);
   Client one(1),two(2),three(3),four(4),five(5);
   std::vector<Topic* > topics;    

   topics.push_back(&TopicA);
   topics.push_back(&TopicB);
   topics.push_back(&TopicC);

   one.subscribeTopic(&TopicA);
   one.subscribeTopic(&TopicB);
   one.subscribeTopic(&TopicC);

   two.subscribeTopic(&TopicB);
   two.subscribeTopic(&TopicC);

   three.subscribeTopic(&TopicA);
   three.subscribeTopic(&TopicB);

   four.subscribeTopic(&TopicA);

   five.subscribeTopic(&TopicA);
   five.subscribeTopic(&TopicC);

   while(1) {
      Generator Gen(topics);
      this_thread::sleep_for(chrono::milliseconds(1000));
      thread client1{threadClient1,ref(one)};
      client1.join();
      thread client2{threadClient2,ref(two)};
      client2.join();
      thread client3{threadClient3,ref(three)};
      client3.join();
      thread client4{threadClient4,ref(four)};
      client4.join();
      thread client5 {threadClient5,ref(five)};
      client5.join();
      this_thread::sleep_for(chrono::milliseconds(2000));
   }
   return 0;
}
