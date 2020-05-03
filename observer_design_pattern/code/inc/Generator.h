#ifndef GENERATOR_H
#define GENERATOR_H
#define msgSize 10

#include "Topic.h"
#include <vector>

class Generator {
public:
   Generator(std::vector<Topic* > topics);
   ~Generator();
private:
   char* str;
};

#endif //GENERATOR_H