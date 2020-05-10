#ifndef  LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

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
   Node* pNode = m_pHead;

   while (pNode != nullptr)
   {
      if (pNode->getData() == data)
      {
         return pNode;
      }
      pNode = pNode->getNextPtr();
   }

   return nullptr;
}

template <typename DataType>
void LinkedList<DataType>::deleteNode(DataType data)
{
   Node* pNode = m_pHead;

   // if head node itself hold the key to be deleted 
   if ((pNode != nullptr) && (pNode->getData() == data))
   {
      m_pHead = pNode->getNextPtr();
      delete pNode;
      return;
   }

   Node* pPrev = nullptr;
   while ((pNode != nullptr) && (pNode->getData() != data))
   {
      pPrev = pNode;
      pNode = pNode->getNextPtr();
   }

   // if key is not present in linkedlist
   if (pNode == nullptr)
   {
      return;
   }

   // key is present, unlink the node from linked list
   pPrev->setNextPtr(pNode->getNextPtr());
   delete pNode;
}

template <typename DataType>
void LinkedList<DataType>::deleteList()
{
   Node* current = m_pHead;
   Node* next = nullptr;

   while (current != nullptr)
   {
      next = current->getNextPtr();
      delete current;
      current = next;
   }

   m_pHead = nullptr;
}

template <typename DataType>
void LInkedList(DataType>::printList()
{
   Node* pNode = m_pHead;
   while (pNode != nullptr)
   {
      cout << pNode->getData() << " ":
      pNode = pNode->getNextPtr();
   }
   cout << endl;
}

#endif // ! LINKEDLIST_H_#define LINKEDLIST_H_