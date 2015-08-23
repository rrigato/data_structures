#ifndef CHASH_H
#define CHASH_H

#include "Hash.h"
#include <iostream>
#include <string.h>
using namespace std;

class OrderedLinkedList
{
    private:
        struct Record
        {
            string last;
            Record * next;
            bool safe_delete;
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
        void set_delete(int value)
        {
            if (value ==1)
                Head->safe_delete = true;
            else
                Head->safe_delete = false;
        }
        bool get_delete()
        {
            return Head->safe_delete;
        }

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

class CHash : public OrderedLinkedList, public Hash
{


    OrderedLinkedList Table [20];
    int hash(string);
    int cap ;
    int num_elements;
    public:
    CHash()
    {
        cap = 20;
        num_elements = 0;

    }
    int insert(string value)
    {

        int num;
        num = hash(value);
        if (isFull())
            return -1;

        if (Table[num].isEmpty())
            {
                Table[num].insert(value);
                Table[num].set_delete(1);
            }
        else
        {
            int start = num;
            Table[start].set_delete(0);
            while (!Table[num].isEmpty())
                {
                    num++;
                    if (num ==20)
                        num = 0;
                }
                Table[num].insert(value);
                Table[num].set_delete(0);
        }
        num_elements++;
        return 0;
    }


};


int CHash::hash (string value)
{
    if (value.length()> 19)
        return 19;

    return value.length();
}

#endif // OHASH_H
