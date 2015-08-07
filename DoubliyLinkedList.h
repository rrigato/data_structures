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
	DLinkedList () //
	{
		Head = NULL;
	}
	~DLinkedList() //
	{
		clear();
	}
	void clear(); //
	bool isEmpty() const; // 
};

void DLinkedList::clear()
{
	if (isEmpty())
		return;
	while(Head->next != NULL)
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = NULL;
	}
	delete Head;
	Head = NULL;
}
bool DLinkedList::isEmpty() const
{
	return Head == NULL;
}
#endif
