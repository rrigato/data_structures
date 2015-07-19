#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>
#include <string>
#include "List.h"



using namespace std;
class OrderedLinkedList : public List
{
	private:
		Record * Head;
	public:
		OrderedLinkedList();
		~OrderedLinkedList();
		void clear();
		void insert( string, string, string);
		bool isFull() const;
		bool isEmpty() const;
		void print() const;
		int length() const;
		int search(string) const; 
		//void remove(string);
};
/*
void OrderedLinkedList::remove(string key)
{
	int Record_num = 0;
	Record_num = search(key);
	if (Record_num == -1)
		return;
	int counter = 2;
	Record * one = Head;
	Record * two = Head->next;
	if(Record_num ==0)
	{
		Head = Head->next;
		delete one;
	}
	else if (Record_num==1)
	{
		one = two->next;
		delete two;
	}
	else
	{
		while (counter != Record_num)
		{
			one = one->next;
			two = two->next;
			counter++;
		} 
		one = two->next;
		delete two;
	}
}*/
int OrderedLinkedList::search(string key) const
{
	int element_num = -1;
	Record *one = Head;
	for (; one && one->last != key; one = one->next, element_num++);
	if (one)
		return element_num;
	return -1;
}
int OrderedLinkedList::length() const
{
	Record * one = Head;
	int counter = 0;
	for (; one != NULL; counter++, one = one->next);
	return counter;
}
void OrderedLinkedList::print() const
{
	if (!Head)
		cout << "No Records" <<endl;
	Record * one = Head;
	while(one)
	{
		cout << one->last <<" " << one->first << " " << one->phone <<endl;
		one = one->next;
	}
}
bool OrderedLinkedList::isEmpty() const
{
	return Head ==NULL;
}

bool OrderedLinkedList::isFull() const
{
	return false;
}

void OrderedLinkedList::insert( string last_name, string first_name, string phone_num)
{
	Record * newRecord = new Record;
	newRecord->last = last_name;
	newRecord->first = first_name;
	newRecord->phone = phone_num;
	Record * one = Head;
	if (!Head)
	{
		newRecord->next = NULL;
		Head = newRecord;
	}
	else if (Head->last < last_name)
	{
		newRecord->next = Head;
		Head = newRecord;
	}
	else
	{
		Record * two = Head->next;
		for(; two != NULL && two->last < last_name; one = one->next, two = two->next);

		one->next = newRecord;
		newRecord->next = two;				
	}
}


OrderedLinkedList ::OrderedLinkedList()
{
	Head = NULL;
}

OrderedLinkedList :: ~OrderedLinkedList()
{
	clear();	
}
void OrderedLinkedList:: clear()
{
	Record * one = Head;
	while (Head)
	{
		Head = Head->next;
		delete one;
		one = Head;
	}
}


#endif
