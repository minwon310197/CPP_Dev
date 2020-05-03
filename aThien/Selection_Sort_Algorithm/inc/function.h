#ifndef FUCNTION_H
#define FUNCTION_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std; 

/* function to swap value of 2 variables */
void swap(int *varA, int *varB)
{
   int temp = *varA;
   *varA = *varB;
   *varB = temp;
}

/* Function to sort an array */
void selectionSort(int array[], int size)
{
   for (int nParentLoop = 0; nParentLoop < size - 1; ++nParentLoop)
   {
      // Set current element as minumum value
      int minIndex = nParentLoop;

      // Search the rest of array to find the minumum value
      for (int nChildLoop = nParentLoop +1; nChildLoop < size; ++nChildLoop)
      {
         if (array[minIndex] > array[nChildLoop])
         {
            minIndex = nChildLoop;
         }
      }
      // if a minumum value is found, swap it with the current element
      if (minIndex != nParentLoop)
      {
         swap(&array[minIndex], &array[nParentLoop]);
      }
   }
}

/* Function to generate an array */
void generateArray(int array[], int size)
{
   srand(time(NULL));
/*
srand(time(NULL)); 
Required headers:
#include <stdlib.h> : srand();
#include <time.h> : time(NULL);
*/
   for (int i = 0; i < size; ++i)
   {
      array[i] = rand()%100 +1; // 1~100  (%n = 100 - 1 + 1)
   }
}

/* Function to print an array */
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

#endif // !FUCNTION_H