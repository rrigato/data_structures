#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include "List.h"
#include <iostream>
using namespace std;

class CLinkedList : List
{
    struct Node
    {
        int data;
        Node * next;
    };
    Node * Head;
    Node * current;
    Node * Last;

    public:
    CLinkedList ()
    {
        Last = current = Head = NULL;
    }
    CLinkedList(const CLinkedList & f)
    {
        *this = f;
    }
    CLinkedList & operator = (const CLinkedList &);

    bool operator < (const CLinkedList & f)
    {
        int length1 = getLength();
        int length2 = f.getLength();
        return length1 < length2;

    }
    bool operator ==(const CLinkedList & f)
    {
        int length1 = getLength();
        int length2 = f.getLength();
        return length1 == length2;

    }

    ~CLinkedList()
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

};

CLinkedList :: CLinkedList & operator = (const CLinkedList & f)
    {

        Node * one  = f.Head;
        if (f.isEmpty())
        {
            Head = current = Last = NULL;
            return *this;
        }
        Node * Start = f.Head;
        do
        {
            insert(one->data);
            one = one->next;
        }while(one !=Start);
        return *this;
    }
void CLinkedList::clear()
{
    Node * Start = Head;
    Node * one = NULL;
    while (Head)
    {
        one = Head;
        Head = Head->next;
        delete one;
        if (Head == Start)
        {
            current = Last = Head = NULL;
        }
    }
}
bool CLinkedList::isEmpty() const
{
    return Head == NULL;
}

bool CLinkedList::isFull() const
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
int CLinkedList::insert(int value)
{
    if (isFull())
        return -1;
    Node * newNode = new Node;
    if (!newNode)
        return -1;
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty())
    {
         Head = newNode;
         current =  Last = Head;
         newNode->next = Head;
        return 0;
    }
    if ((Head->data) > value)
    {
        newNode->next = Head;
        Head = newNode;
        Last->next = Head;
        return 0;
    }
    Node * one = Head;
    Node * two = Head->next;
    for (; two !=NULL && two !=Head && two->data < value; one = one->next, two = two->next);

    one->next = newNode;
    newNode->next = two;
    if (two == Head)
           Last = newNode;

    return 0;
}

void CLinkedList::print() const
{
    if (isEmpty())
        return;
    Node * one = Head;
    do
    {
        cout << one ->data << " " ;
        one = one->next;
    } while(one != Head);

}

int CLinkedList::getLength() const
{
    if (isEmpty())
        return 0;
    Node * one = Head;
    Node * Start = Head;
    int length = 0;
    do
    {
        length++;
        one = one->next;
    }while(one !=Head);
    return length;
}

void CLinkedList::reset()
{
    current = Head;
}

int CLinkedList::getNext (int & value)
{
    if (current ==NULL)
        return -1;

    value = current->data;
    current = current->next;
    return 0;

}

bool CLinkedList::find(int value) const
{
    if (isEmpty())
        return false;
    if (Head->data == value)
            return true;
    Node * one = Head->next;
    for (; one != Head && one->data != value; one = one->next);
    if (one->data == value)
        return true;
    return false;
}

int CLinkedList::remove(int value)
{
    if (isEmpty())
        return -1;
    Node * Start = Head;
    if (Head->data == value)
    {
        Node * one = Head;
        Head = Head->next;
        if (Start == Last)
                current = Head =Last = NULL;
        else
        {
            Last->next = Head;
            if (current == one)
                    current = current->next;
        }


        delete one;
        return 0;
    }
    Node * one = Head;
    Node * two = Head->next;
    for(; two != Head && two->data != value; one = one->next, two = two->next);
    if (two->data == value)
    {

        if (two == current)
            current = current->next;
        if (two == Last)
            Last = Last->next;
        one->next = two->next;
        delete two;
        return 0;
    }
    else
        return -1;
}
#endif
