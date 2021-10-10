#include "header/SelectionSort.h"
#include "header/BinarySearchCls.h"

int globalArray[ARRAY_SIZE];
unsigned int repeatTime = REPEAT_TIME;

void printGlobalArray()
{
    printf("globalArray:");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("[%d]", i);
        printf(" %d ", globalArray[i]);
    }
    printf("\n");
}

int main()
{
    //Selection Sort Algorithm wit harray handler
    SelectionSortCls* SelObjPtr = SelectionSortCls::getInstance();    
    BinarySearchCls* BinObjPtr = BinarySearchCls::getInstance();    
    while (repeatTime != 0)
    {
        repeatTime--;
        printf("------SelectionSort-----------------------------\n");
        
        SelObjPtr->generateArray(globalArray);
        printGlobalArray();
        SelObjPtr->startSorting(globalArray);
        printGlobalArray();

        printf("------BinarySearch-------------------------------\n");
        int numBinSearch;
        std::cout << "Choose numSearch: ";
        std::cin >> numBinSearch;
        printf("numBinSearch: %d \n", numBinSearch);
        int resultInt = BinObjPtr->startBinarySearchInt(globalArray, 0, ARRAY_SIZE - 1, numBinSearch);
        (resultInt == -1) ? std::cout << "Element is not present in array" : std::cout << "Element is present at index " << resultInt;
        printf("\n------------------------------------------------------\n");
    }

    return 0;
}