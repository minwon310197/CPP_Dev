#include "BinarySearchCls.h"

BinarySearchCls* BinarySearchCls::_instance = NULL;

BinarySearchCls* BinarySearchCls::getInstance()
{
	if (!_instance)
	{
		_instance = new BinarySearchCls();
	}

	return _instance;
}

BinarySearchCls::~BinarySearchCls()
{
	if (_instance)
	{
		delete _instance;
	}
}

int BinarySearchCls::startBinarySearchInt(int array[], int arrayBegin, int arrayLast, int numSearch) //reference \\decreasing
{
	static int count(0);
	int debugCount(0);
	count++;
	printf("startBinarySearchInt called %d time(s) \n", count);

	//debug
	printf("arrayBegin(%d)\n", arrayBegin);
	printf("arrayLast(%d)\n", arrayLast);
	printf("0_debugCount(%d)\n", debugCount++);

	if (numSearch < array[arrayLast] || numSearch > array[arrayBegin]) //for decreasing array
	{
		return -1;
	}

	printf("1_debugCount(%d)\n", debugCount++);
	if (arrayLast >= arrayBegin) {
		int mid = arrayLast + (arrayBegin - arrayLast) / 2;
		//debug
		printf("arrayMid(%d)\n", mid);
		// If the element is present at the middle
		// itself
		if (array[mid] == numSearch)
		{
			return mid;
			printf("return_mid_debugCount(%d)\n", debugCount++);
		}
		else if (array[arrayLast] == numSearch)
		{
			return arrayLast;
			printf("return_last_debugCount(%d)\n", debugCount++);
		}
		else if (array[arrayBegin] == numSearch)
		{
			return arrayBegin;
			printf("return_begin_debugCount(%d)\n", debugCount++);
		}

		printf("debugCount(%d)\n", debugCount++);
		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (array[mid] < numSearch)
			return startBinarySearchInt(array, arrayBegin, mid - 1, numSearch);
		printf("debugCount(%d)\n", debugCount++);
		// Else the element can only be present
		// in right subarray
		return startBinarySearchInt(array, mid + 1, arrayLast, numSearch); //else case
		printf("debugCount(%d)\n", debugCount++);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
