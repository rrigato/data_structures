#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <iostream>
#include "Queue.h"
using namespace std;
template <class T>
class ArrayQueue :public Queue<T>
{
    private:
        int maxLength;
        int num_elements;
        int Rear;
        int Front;
        T * ArrayPointer;
    public:
        ArrayQueue();
        ~ArrayQueue();
        bool isFull() const;
        bool isEmpty() const;
        void makeEmpty();
        int dequeue(T&);
        int enqueue(T);
 
};
template <class T>
ArrayQueue<T> ::ArrayQueue()
{
    ArrayPointer = new T[20];
    num_elements = 0;
    Front = -1;
    maxLength = 20;
    Rear = -1;
}
 
template <class T>
ArrayQueue <T> :: ~ArrayQueue()
{
        delete [] ArrayPointer;
}
 
template <class T>
bool ArrayQueue <T> :: isFull() const
{
    return num_elements == maxLength;
}
 
 
template <class T> 
bool ArrayQueue <T> :: isEmpty() const
{
    return 0 == num_elements;
}
 
template <class T>
void ArrayQueue <T> :: makeEmpty()
{
    num_elements = 0;
    Front = -1;
    Rear = 0;
}
 
template <class T>
int ArrayQueue<T> :: dequeue(T& value)
{
    if (isEmpty())
        return -1;
    value  =ArrayPointer[Front];
    Front ++;
	if (Front == maxLength)
	{
		Front = 0;
	}
	num_elements --;
    return 0;
}
 
template <class T>
int ArrayQueue<T>:: enqueue(T value)
{
    if (isFull())
        return -1;
	
	if (Rear == maxLength)
		Rear = 0;
    ArrayPointer[Rear] = value;
	Rear ++;


    return 0;
}
 
#endif
