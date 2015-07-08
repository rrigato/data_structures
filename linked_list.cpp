

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <string>


#include <iostream>
using namespace std;
template <class T>
class LinkedList //: public List
{
private:
    struct node
    {
        T value;
        node * Next;
    };
    node * Head;

public:
        LinkedList ();
        void append (T);
        void remove (T);
        void print () const;
        void clear ();
        T getNext ();
};
template <class T>
T LinkedList <T>::getNext()
{
    if (Head == 0)
    {
        string error;
        error = "Error: empty list";
        throw error;
    }
    node * one = Head;
    Head = Head->Next;
    T First = one->value;
    return First;
}



template <class T>
void LinkedList <T>::clear()
{
    node * one = Head;
    while (Head)
    {
        Head = Head->Next;
        delete one;
        one = Head;

    }

}
template <class T>
LinkedList <T>::LinkedList()
{
    Head = 0;
}
template <class T>
void LinkedList <T>::print () const
{
    node * one = Head;
    while (one)
    {
        cout << one-> value << " -> " ;
        one = one->Next;
    }
    cout <<endl;
}
template <class T>
void LinkedList <T>::append (T data)
{
    node * newNode = new node;
    newNode->value = data;
    newNode->Next = 0;
    if (Head ==0)
    {
        Head = newNode;
    }
    else
    {
        node * one = Head;
        while (one->Next != 0)
        {
            one = one->Next;
        }

        one->Next = newNode;
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
        node * two = one->Next;
        while (two != 0 && two->value != data )
        {
            one = one->Next;
            two = two->Next;
        }
        if (two)
        {
            one->Next = two->Next;
            delete two;

        }
        else
        return;
    }

}


#endif
