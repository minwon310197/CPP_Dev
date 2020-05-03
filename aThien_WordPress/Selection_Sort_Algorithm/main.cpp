#include "inc/function_redo.h"

int main() 
{
    int size = 10;
    int array[size];
    generateArray(array, size);

    cout << "Unsorted : ";
    printArray(array, size);

    selectionSort(array, size);

    cout << "Sorted   : ";
    printArray(array, size);

    return 0;
}
