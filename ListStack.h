#ifndef LISTSTACK_H
#define LISTSTACK_H
 
#include "Stack.h"
#include <iostream>
using namespace std;
template <class T>
class ListStack : public Stack <T>
{
private:
        struct Node
        {
            Node* Next;
            T Data;
        };
        Node * Top;
 
public:
    ListStack();
    ~ListStack();
    int push(T);
    int pop( T& );
    int top( T& ) const; //return the top value on the stack
    bool isFull() const ;
    bool isEmpty() const ;
};
 
template <class T>
 ListStack <T> :: ListStack()
 {
    Top = NULL;
 
 }
 
 template <class T>
 ListStack <T> :: ~ListStack()
 {
     int value;
    while(!isEmpty())
        pop(value);
 }
 
 template <class T>
int ListStack <T> ::push(T value)
{
    if (isFull())
        return -1;
    Node * newNode = new Node;
    newNode->Data = value;
    newNode->Next = Top;
    Top = newNode;
    return 0;
}
 
 template <class T>
int ListStack <T> ::pop(T & value)
{
    if (isEmpty())
        return -1;
    Node * one = Top;
    value = one->Data;
    Top = Top->Next;
    delete one;
    return 0;
}
 
 template <class T>
int ListStack <T> ::top(T & value) const
{
    if(isEmpty())
        return -1;
    Node * one = Top;
    value = one->Data;
    return 0;
 
}
 
template <class T>
bool ListStack <T> ::isFull() const
{
    return false;
}
 template <class T>
bool ListStack <T> ::isEmpty()const
{
    return Top ==NULL;
}
 
 
#endif
