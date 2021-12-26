#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "AlgorithmDefine.h"

class SelectionSortCls
{
public:
    static SelectionSortCls* getInstance();
    ~SelectionSortCls();

    void generateArray(int array[]);
    void swap(int* A, int* B);
    void startSorting(int array[]);
    
private:
    /*instance will be stored*/
    static SelectionSortCls* _instance;
    /*private constructor to prevent instancing*/
    SelectionSortCls() {};
    /*variable*/ 
};

#endif // !SELECTIONSORT_H
