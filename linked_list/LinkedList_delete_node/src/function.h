#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include "src/linked_list.h"

node *start, *enD = NULL;

void addNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
 
    if(start == NULL)
    {
        start = newnode;
        enD = newnode;
    }
    else
    {
        enD->next = newnode;
        enD = newnode;
    }
}
 
void display()
{
    node* current = start;
    std::cout << "list of singly linked list : " ;
    while(current != NULL)
    {
        std::cout << current->data << " " ;
        current = current->next;
    }
    std::cout << "\n" ;
}
 
void deleteValue(int deletevalue)
{
    node* current = start;
 
    while(current != NULL)
    {
        if(current->data == deletevalue)
        {
            if(current == enD)
            {
                delete current;
            }
            else
            {
                node* temp = current;
                temp = current->next;
                current->data = temp->data;
                current->next = temp->next;
                delete temp;
            }
        }
        else
        {
            if(current->next == enD && current->next->data == deletevalue)
            {
                enD = current;
            }
            current = current->next;
        }
    }
}
 
void deleteAllNodes()
{
    node* current = start;
    node* next;
 
    while(current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

#endif // #IFNFDEF FUNCTION_H