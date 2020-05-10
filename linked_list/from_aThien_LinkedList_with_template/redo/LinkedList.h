#ifndef  LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

template <typename DataType>
class LinkedList
{
public:
   class Node
   {
   private;
      DataType data;
      Node* pNext;
   public:
      Node (DataType value): data(vavlue), pnext(nullptr) {};
      ~Node() {};

      void setData(DataType value) { data = value; }
      DataType getData() { return data; }

      void setNextPtr(Node* ptr) { pNext = ptr; }
      Node* getNextPtr() { return pNext; }
   };
private:
   Node* m_pHead;
public:
   LinkedList();
   ~LinkedList();

   LinkedList(const LinkedList<DataType>&) = delete;
   LinkedList& operator=(const LinkedList<DataType>&) = delete;

   void insertNode (DataType data);
   Node* searchNode(DataType data);
   void deleteNode(DataType data);
   void printList();
}

template <typename DataType>
LinkedList<DataType>::~LinkedList()
{
   deleteList();
}

template <typename DataType>
void LinkedList<DataType>::insertNode(DataType data)
{
   Node* pNewData = new Node(data);
   if (m_pHead == nullptr)
   {
      m_pHead = pNewData;
   }
   else
   {
      Node* temp = m_pHead;

      //find the last element
      while (temp->getNextPtr() != nullptr)
      {
         temp = temp->getNextPtr();
      }

      // insert to the end of list
      temp->setNextPtr(pNewData);
   }
}

template <typename DataType>
typename LinkedList<DataType>::Node* LinkedList<DataType>::searchNode(DataType data)
{
   
}





























#endif // ! LINKEDLIST_H_#define LINKEDLIST_H_