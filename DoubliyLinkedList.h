#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "List.h"
#include <iostream>
using namespace std;

class DLinkedList : List
{
	struct Node
	{
		int data;
		Node * prev;
		Node * next;
	};
	Node * Head;
	Node * current;

	public:
	DLinkedList ()
	{
		Head = NULL:
	//	current = Head = NULL;
	}
	DLinkedList ( const DLinkedList & f)
	{
        *this = f;
	}
	~DLinkedList()
	{
		clear();
	}
	void clear();
	bool isEmpty() const;
	bool isFull() const;
	int insert (int);
	void print () const;
	int getLength() const;
	void reset();
	int getNext (int &);
	bool find (int) const;
	int remove (int);
	void rprint() const;
	DLinkedList & operator = (const DLinkedList & f)
	{
        Node * one  = f.Head;
        while (one)
        {
            insert(one->data);
            one = one->next;
        }
        return *this;
    }
    bool operator < (const DLinkedList & f)
    {
        int length1 = getLength();
        int length2 = f.getLength();
        return length1 < length2;

    }
    bool operator ==(const DLinkedList & f)
    {
        int length1 = getLength();
        int length2 = f.getLength();
        return length1 == length2;

    }
};


void DLinkedList::clear()
{
	Node * one = NULL;
	while (Head)
	{
		one = Head;
		Head = Head->next;
		delete one;
	}
}
bool DLinkedList::isEmpty() const
{
	return Head == NULL;
}

bool DLinkedList::isFull() const
{
	Node * newNode;
	try
	{
		newNode = new Node;
		delete newNode;
		return false;
	}
	catch (bad_alloc Name)
	{
		return true;
	}
}
int DLinkedList::insert(int value)
{
	if (isFull())
		return -1;
	Node * newNode = new Node;
	if (!newNode)
		return -1;
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (isEmpty())
	{
		 Head = newNode;
		 current = Head;
		return 0;
	}
	if ((Head->data) > value)
	{
		newNode->next = Head;
		Head->prev = newNode;
		Head = newNode;
		return 0;
	}
    Node * one = Head;
	Node * two = Head->next;
	for (; two !=NULL && two->data < value; one = one->next, two = two->next);
	if (two)
        	two->prev = newNode;
	one->next = newNode;
	newNode->prev = one;
	newNode->next = two;

	return 0;
}

void DLinkedList::print() const
{
    if (isEmpty())
        return;
	Node * one = Head;
	while (one)
	{
		cout << one ->data << " " ;
		one = one->next;
	}
    cout << endl;
}

int DLinkedList::getLength() const
{
	Node * one = Head;
	int length = 0;
	while (one)
	{
		length++;
		one = one->next;
	}
	return length;
}

void DLinkedList::reset()
{
	current = Head;
}

int DLinkedList::getNext (int & value)
{
	if (current ==NULL)
		return -1;

	value = current->data;
	current = current->next;
	if (current ==NULL)
		current = Head;
	return 0;

}

bool DLinkedList::find(int value) const
{
	Node * one = Head;
	for (; one && one->data != value; one = one->next);
	if (one)
		return true;
	return false;
}

int DLinkedList::remove(int value)
{
	if (isEmpty())
		return -1;
	if (Head->data == value)
	{
		Node * one = Head;
		Head = Head->next;
		if (Head)
			Head->prev = NULL;
		delete one;
		return 0;
	}
	Node * one = Head;
	Node * two = Head->next;
	for(; two && two->data != value; one = one->next, two = two->next);
	if (two)
	{
		one->next = two->next;
		if (two->next)
			two->next->prev = one;
		delete two;
		return 0;
	}
	else
		return -1;
}

void DLinkedList::rprint() const
{
	if (isEmpty())
		return;
	Node * one = Head;
	while (one->next)
		one = one->next;
	while (one)
	{
		cout << one->data << " ";
		one = one->prev;
	}
	cout <<endl;
}
#endif
