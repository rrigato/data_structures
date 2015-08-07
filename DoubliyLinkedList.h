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

	public:
	DLinkedList ()
	{
		Head = NULL;
	}
	~DLinkedList()
	{
		clear();
	}
	void clear();
	bool isEmpty() const;
	bool isFull() const;
	int insert (int) ;
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
		return 0;
	}
	if ((Head->data) > value)
	{
		newNode->next = Head;
		Head->prev = newNode;
		Head = newNode;
		return 0;
	}
	Node * two = Head->next;
	for (; two !=NULL && two->data < value;two = two->next);
	two->prev->next = newNode;
	newNode->prev = two->prev;
	newNode->next = two;
	return 0;
}
#endif
