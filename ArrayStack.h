#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
 
#include "Stack.h"
#include <iostream>
using namespace std;
template <class T>
class ArrayStack : public Stack <T>
{
private:
        int num_elements;
        int Top;
        int capacity;
        T * Array_Stack ;
public:
    ArrayStack();
    ~ArrayStack();
    int push(T);
    int pop( T& );
    int top( T& ) const; //return the top value on the stack
    bool isFull() const ;
    bool isEmpty() const ;
};
 
template <class T>
 ArrayStack <T> :: ArrayStack()
 {
     Array_Stack = new T[20];
     capacity = 20;
     num_elements =0;
     Top = -1;
 
 }
 
 template <class T>
 ArrayStack <T> :: ~ArrayStack()
 {
    delete [] Array_Stack;
 }
 
 template <class T>
int ArrayStack <T> ::push(T value)
{
    if (isFull())
        return -1;
    Array_Stack[Top +1] = value;
    Top ++;
    return 0;
}
 
 template <class T>
int ArrayStack <T> ::pop(T & value)
{
    if (isEmpty())
        return -1;
    value = Array_Stack[Top];
    Top --;
    return 0;
}
 
 template <class T>
int ArrayStack <T> ::top(T & value) const
{
    if(isEmpty())
        return -1;
    value = Array_Stack[Top];
    return 0;
}
 
template <class T>
bool ArrayStack <T> ::isFull() const
{
    return Top == capacity -1;
}
 template <class T>
bool ArrayStack <T> ::isEmpty()const
{
    return Top == -1;
}
 
 
#endif
