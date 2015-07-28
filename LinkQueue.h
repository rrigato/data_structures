#ifndef LISTQUEUE_H
#define LISTQUEUE_H
#include <iostream>
#include "Queue.h"
using namespace std;
template <class T>
class ListQueue :public Queue<T>
{
    private:
        struct Node
        {
            Node * Next;
            T data;
        };
        Node * Head;
     
    public:
        ListQueue();
        ~ListQueue();
        bool isFull() const;
        bool isEmpty() const;
        void makeEmpty();
        int dequeue(T&);
        int enqueue(T);
 
};
 
 
 
template <class T>
ListQueue<T> ::ListQueue()
{
    Head = NULL;
 
}
 
 
template <class T>
ListQueue<T> ::~ListQueue()
{
    makeEmpty();
}
 
 
template <class T>
bool ListQueue <T> :: isFull() const
{
    return false;
}
 
 
template <class T>
bool ListQueue <T> :: isEmpty() const
{
    return Head ==NULL;
}
 
 
template <class T>
void ListQueue <T> :: makeEmpty() 
{
    Node * one ;
    while (Head)
    {
        one = Head;
        Head = Head->Next;
        delete one;
 
    }
}
 
template <class T>
int ListQueue <T> :: dequeue(T & value) 
{
        if (isEmpty())
            return -1;
        Node * one = Head;
        Head  = Head-> Next;
        value = one->data;
        delete one;
        return 0;
}
 
template <class T>
int ListQueue <T> :: enqueue(T value)
{
    if (isFull())
        return -1;
    Node * one = Head;
    Node * newNode = new Node;
    newNode ->data = value;
    newNode->Next = NULL;
    while(one)
    {
            one = one->Next;
    }
 
 
    one = newNode;
	return 0;
 
}
#endif
