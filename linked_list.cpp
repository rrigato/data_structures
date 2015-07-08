
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"


#include <iostream>
using namespace std;
template <class T>
class LinkedList : public List
{
private:
    struct node
    {
        T value;
        node * Next;
    };
    node * Head;

public:
        void append (T);
        void remove (T);
};
template <class T>
void LinkedList <T>::append (T data)
{
    node * newNode = new node;
    newNode->value = data;
    if (Head)
    {
        node * one = Head -> Next;
        while (one)
        {
            one = one->Next;
        }

        one->Next = newNode;
    }
    else
    {
        Head = newNode;
    }
}

template <class T>
void LinkedList <T>::remove (T data)
{
        node * one = Head;
    if (!Head)
    {
        return;
    }

    else if (Head->value == data)
    {
        Head = Head->Next;
        delete one;

    }
    else
    {
        node * two = one->next;
        while (two->value != data && two->Next != NULL)
        {
            one = one->Next;
            two = two->Next;
        }
        if (two)
        {
            one->Next = two->Next;
            delete two;

        }
        return;
    }

}


#endif
