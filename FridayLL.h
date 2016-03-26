/**
This is a dynamic linked list implementation.
It will be implemented in increasing order.
**/

#ifndef LINKED_H
#define LINKED_H
#include <iostream>
using namespace std;
class Linked
{
	public:
		Linked();
		~Linked();
		bool isEmpty();
		bool isFull();
		int putItem(int);
		void destroy();
		void print();
		bool search(int);
		int remove (int);
	private:
		struct Node
		{
			int value;
			Node * Next;
		};
		Node * Head;

};

Linked::Linked()
{
	Head = NULL;
}

Linked::~Linked()
{
    destroy();
}

bool Linked::isEmpty()
{
	return Head == NULL;

}

bool Linked::isFull()
{
	Node * newNode;
	try
	{
		newNode = new Node;
		delete newNode;
		return false;
	}
	catch(bad_alloc exception)
	{
		return true;
	}
}


//placing an item into the list
//return 0 if successfull, -1 otherwise
int Linked::putItem(int data)
{
	if (isFull())
	{
		return -1;
	}
    Node * newNode;
	newNode = new Node;
	newNode->value = data;
	newNode->Next = NULL;

    if (isEmpty())
    {
            Head = newNode;
            return 0;
    }


	Node * one = Head;

    if(one->value > data)
    {
        newNode->Next = one;
        Head = newNode;
        return 0;
    }
	while(one->Next != NULL && one->Next->value < data)
	{
		one = one ->Next;
	}

	newNode->Next = one->Next;
    one->Next = newNode;
    return 0;
}

void Linked::destroy()
{
    Node * one = Head;
    while(Head != NULL)
    {
        Head = Head->Next;
        delete one;
        one = Head;
    }
}

void Linked::print()
{
    if(isEmpty())
    {
        return;
    }

    Node * one = Head;
    while(one != NULL)
    {
        cout << one->value << " " << "->";
        one = one->Next;
    }
    cout << endl;

}

bool Linked::search(int data)
{
    if (isEmpty())
    {
        return false;
    }

    Node * one = Head;
    while(one->Next != NULL && one->value != data)
    {
        one = one->Next;
    }
    return one->value == data;
}
//removes a values if it is in the linked list
//returns 0 if successfull, 1 otherwise
int Linked:: remove(int data)
{
    if(!search(data))
    {
        return -1;

    }

    Node * one = Head;
    if(Head->value == data)
    {
        Head = Head->Next;
        delete one;
        one = NULL;
        return 0;
    }


    Node * two = one->Next;

    while(two != NULL && two->value != data)
    {
        one = one->Next;
        two = two->Next;
    }
    if(two)
    {
            one->Next = two->Next;
            delete two;
            two = NULL;
            return 0;
    }
    else
    {
        return 0;
    }

}
#endif
