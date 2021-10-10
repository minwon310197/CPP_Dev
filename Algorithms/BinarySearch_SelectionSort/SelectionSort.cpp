#include "SelectionSort.h"

SelectionSortCls* SelectionSortCls::_instance = NULL;

SelectionSortCls* SelectionSortCls::getInstance()
{
	if (!_instance)
	{
		_instance = new SelectionSortCls();
	}

	return _instance;
}

SelectionSortCls::~SelectionSortCls()
{
	if (_instance)
	{
		delete _instance;
	}
}

void SelectionSortCls::generateArray(int array[])
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = rand()%100+1;
	}
}

void SelectionSortCls::swap(int* A, int* B)
{
	*A = *A + *B;
	*B = *A - *B;
	*A = *A - *B;
}

void SelectionSortCls::startSorting(int array[])
{
	for (int i = 0; i<ARRAY_SIZE; i++)
	{
		for (int j = i+1; j<(ARRAY_SIZE) ; j++)
		{
			if (array[j] > array[i]) // >: decreasing | <: increasing
			{
				swap(&array[i], &array[j]);
			}
		}
	}
}
