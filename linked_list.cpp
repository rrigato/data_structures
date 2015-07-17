//three problems, retrieve and getNext throw exceptions and the reset
//which resets the iteration? what does that mean

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <string>


#include <iostream>
using namespace std;
template <class T>
class LinkedList : public List <T>
{
private:
    struct node
    {
        T value;
        node * Next;
    };
    node * Head;
    node * current_position;

public:
        LinkedList ();
        void append (T);
        void remove (T);
        void clear ();
        void reset();
        T getNext ();
        int getLength () const;
        bool isFull () const;
        void print () const;
        bool isEmpty () const;
        T retrieve (int) const;

};

template <class T>
void LinkedList <T>::reset()
{
    current_position = NULL;
}

template <class T>
T LinkedList <T>::retrieve(int element_num) const
{
    string error = "Error: element out of bounds.";
    int counter = 0;
    //checks to make sure element number is in bounds
    if (element_num < 0 || getLength() < element_num)
        throw error;

    node * one = Head;
    while ( counter != element_num)
    {
        one = one->Next;
        counter++;
    }
    return one->value;
}



template <class T>
bool LinkedList <T>::isEmpty() const
{
    if (Head)
    {
        return false;
    }
    return true;
}


template <class T>
bool LinkedList <T>::isFull() const
{
    return false;
}
template <class T>
int LinkedList <T>::getLength() const
{
    node * one = Head;
    int count = 0;
    while (one)
    {
        one = one->Next;
        count ++;
    }
    return count;

}

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
    delete one;
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
