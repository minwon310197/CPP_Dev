#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "AlgorithmDefine.h"

class BinarySearchCls
{
public:
    static BinarySearchCls* getInstance();
    ~BinarySearchCls();
    std::string startBinarySearch(int array[], int arrayBegin, int arrayLast, int numSearch);
    int startBinarySearchInt(int array[], int arrayBegin, int arrayLast, int numSearch);

private:
    /*instance will be stored*/
    static BinarySearchCls* _instance;
    /*private constructor to prevent instancing*/
    BinarySearchCls() {};
    /*variable*/
};

