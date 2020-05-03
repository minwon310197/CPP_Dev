#ifndef FUNCTION_REDO_H
#define FUNCTION_REDO_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// function to swap items in array
void swap(int* varA, int* varB)
{
    int temp = *varA;
    *varA = *varB;
    *varB = temp;
}

//function for selecction sorting
void selectionSort(int array[],int size)
{
    // from zero to theend_loop
    for ( int zero = 0; zero < size - 1; zero++)
    {
        int minIndex = zero;

        // from zero+1 to the end_loop
        for ( int zeroPlusOne = zero + 1; zeroPlusOne < size; zeroPlusOne++)
        {
            if (array[zeroPlusOne] < array[zero])
            {
                minIndex = zeroPlusOne;
                //then swap
                swap(&array[zero],&array[minIndex]);                
            }
        }
    }
}

//function to PRNG array
void generateArray(int array[],int size)
{
    srand(time(NULL));
    for (int i = 0; i < size-1; i++)
    {
        array[i] = rand()%100 + 1;
    }
}

void printArray(int array[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

























#endif // !FUNCTION_REDO_H
