
#ifndef OHASH_H
#define OHASH_H
#include "Hash.h"
#include <iostream>
#include <string.h>
using namespace std;
class OrderedLinkedList
{
    protected:
        struct Record
        {
            string last;
            Record * next;
        };
        Record * Head;
    public:
        OrderedLinkedList();
        ~OrderedLinkedList();
        void clear();
        void insert( string);
        bool isFull() const;
        bool isEmpty() const;
        void print() const;
        int length() const;
        int search(string) const;
        void remove(string);
};

void OrderedLinkedList::remove(string key)
{

 	if (isEmpty())
      	  return;

  	 Record * one =NULL;

	if(Head->last ==key)
	{
	one = Head;
        Head = Head->next;
        delete one;
	return;
	}
	Record * two = NULL;
	for(one = Head, two =Head->next; two != NULL && two->last !=key; one = one->next, two = two->next);
	if (two != NULL)
	{
		one->next = two->next;
		delete two;
		return;
	}

}
int OrderedLinkedList::search(string key) const
{
    int element_num = 0;
    Record *one = Head;
	while(one)
	{
		if (one->last == key)
			return element_num;
		element_num++;
		one = one->next;
	}
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
       return;
    Record * one = Head;
    while(one)
    {
        cout << one->last << " ";
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

void OrderedLinkedList::insert( string last_name)
{
    Record * newRecord = new Record;
    newRecord->last = last_name;

    newRecord->next = NULL;
    Record * one = Head;
    if (!Head)
    {

        Head = newRecord;
    }
    else if (Head->last > last_name)
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












class OHash : public OrderedLinkedList, Hash
{
    private:
        int hash(string );

    public:
};

int OHash :: hash (string value)
{
    return 2;
}





#endif
