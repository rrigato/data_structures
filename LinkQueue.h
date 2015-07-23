#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <iostream>
#include "Queue.h"
using namespace std;
template <class T>
class LinkQueue :public Queue<T>
{
	private:
		struct Node
		{
			Node * Next;
			T data;
		};
		Node * Head;
	
	public:
		LinkQueue();
		~LinkQueue();
		bool isFull() const;
		bool isEmpty() const;
		void makeEmpty();
		int dequeue(T&);
		int enqueue(T);

};



template <class T>
LinkQueue<T> ::LinkQueue()
{
	Head = NULL;

}


template <class T>
LinkQueue<T> ::LinkQueue()
{
	makeEmpty();
}


template <class T>
bool LinkQueue <T> :: isFull() const
{
	return false;
}


template <class T>
bool LinkQueue <T> :: isEmpty() const
{
	return Head ==NULL;
}


template <class T>
void LinkQueue <T> :: makeEmpty() 
{
	node * one ;
	while (Head)
	{
		one = Head;
		Head = Head->Next;
		delete one;

	}
}

template <class T>
int LinkQueue <T> :: dequeue(T & value) 
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
int LinkQueue <T> :: enqueue(T value)
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

}
#endif
