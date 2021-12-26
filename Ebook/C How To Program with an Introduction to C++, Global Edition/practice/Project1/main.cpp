#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int debugCount(0);
struct linkedList
{
	char value;
	struct linkedList* nextPtr;
};
struct queue
{
	char value;
	struct linkedList* nextPtr;
};
struct stack
{
	char value;
	struct linkedList* nextPtr;
};

typedef struct linkedList LINKEDLIST;
typedef LINKEDLIST* llPtr;
typedef struct stack STACK;
typedef STACK* stackPtr;
typedef struct queue QUEUE;
typedef QUEUE* queuePtr;

void insertLinkedList(llPtr*, char);
void deleteLinkedListNode(llPtr*, char);
void insertQueue(queuePtr);
void removeQueue(queuePtr);
void insertStack(stackPtr);
void popStack(stackPtr);

void printLinkedList(llPtr);
void printQueue(queuePtr);
void printStack(stackPtr);

int main(void)
{
	puts("-----------LinkedList----------\n");
	llPtr startPtr = NULL;
	insertLinkedList(&startPtr, 'A');	
	insertLinkedList(&startPtr, 'A');
	insertLinkedList(&startPtr, 'B');
	insertLinkedList(&startPtr, 'C');	
	insertLinkedList(&startPtr, 'D');
	insertLinkedList(&startPtr, 'E');
	insertLinkedList(&startPtr, 'F');
	insertLinkedList(&startPtr, 'G');
	insertLinkedList(&startPtr, 'H');	
	insertLinkedList(&startPtr, 'A');
	insertLinkedList(&startPtr, 'I');
	insertLinkedList(&startPtr, 'J');
	insertLinkedList(&startPtr, 'K');
	insertLinkedList(&startPtr, 'L');
	insertLinkedList(&startPtr, 'M');	
	insertLinkedList(&startPtr, 'B');
	insertLinkedList(&startPtr, 'B');
	insertLinkedList(&startPtr, 'N');
	insertLinkedList(&startPtr, 'O');
	insertLinkedList(&startPtr, 'P');
	printLinkedList(startPtr);
	deleteLinkedListNode(&startPtr, 'A');
	printLinkedList(startPtr);
	puts("\n-----------LinkedList----------\n");
}

void insertLinkedList(llPtr* ptr, char newData)
{
	llPtr newPtr = (llPtr)malloc(sizeof(LINKEDLIST));
	llPtr previousPtr(*ptr);

	if (newPtr != NULL)
	{
		newPtr->value = newData;
		newPtr->nextPtr = NULL;
		if (*ptr == NULL)
		{
			*ptr = newPtr;
		}
		else
		{			
			llPtr tempPtr = *ptr;
			while (tempPtr != NULL)
			{
				if (newData < tempPtr->value)
				{
					newPtr->value = tempPtr->value;
					tempPtr->value = newData;
					newPtr->nextPtr = tempPtr->nextPtr;
					tempPtr->nextPtr = newPtr;
					break;
				}

				if (tempPtr->nextPtr != NULL)
				{	
					previousPtr = tempPtr;
					tempPtr = tempPtr->nextPtr;
				}
				else
				{
					tempPtr->nextPtr = newPtr;
					break;
				}
			}
		}
	}
	else
	{
		puts("not enough memory to allocate");
	}
}

void deleteLinkedListNode(llPtr* ptr, char dataDelete)
{	

	if (*ptr != NULL && dataDelete == (*ptr)->value)
	{
		llPtr tempPtr = *ptr;
		*ptr = (*ptr)->nextPtr;
		free(tempPtr);
	}
}



void insertQueue(queuePtr* ptr)
{

}
void removeQueue(queuePtr* ptr)
{

}

void insertStack(stackPtr* ptr)
{

}
void popStack(stackPtr* ptr)
{

}

void printLinkedList(llPtr currentPtr)
{
	if (currentPtr == NULL)
	{
		puts("\nLinked list is empty");
	}
	else
	{
		puts("\nLinked list is ready to print:\n");
		while (currentPtr != NULL)
		{
			printf(" %c - ", currentPtr->value);
			currentPtr = currentPtr->nextPtr;
		}
	}
}
void printQueue(queuePtr ptr)
{

}
void printStack(stackPtr ptr)
{

}

