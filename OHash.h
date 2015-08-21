#ifndef OHASH_H
#define OHASH_H

#include "Hash.h"
#include <iostream>
#include <string.h>
using namespace std;

class OHash : public Hash
{
    struct Node
    {
        string key;
        Node * next;
    };

    Node Table[10];
    int cap;
    int hash(string);
    int num_elements;
    public:
    OHash()
    {
        cap = 10;
        num_elements = 0;

    }
    ~OHash()
    {
        clear;
    }
    bool isFull () const
    {
        return false;
    }
    bool isEmpty() const
    {
            return num_elements == 0;
    }

    int insert (string value)
    {
        if (isFull())
            return -1;
        int num = hash(value);
        if (Table[num].key.empty())
            {
                Table[num].key = value;
                Table[num].next = NULL;
                num_elements ++;
            }
        else if (Table[num].next == NULL)
        {
            Node * newNode = new Node;
            newNode->next = NULL;
            Table[num].next = newNode;
            newNode->key = value;
        }
        else
        {
            Node * one = Table[num].next;
            while(one->next!=NULL)
            {
               one = one->next;
            }

            Node * newNode = new Node;
            newNode->next = NULL;
            one->next = newNode;
            newNode->key = value;
        }

        return 0;
    }

    void clear()
    {
        if (isEmpty())
            return;
        Node * one = NULL;
        int i = 0;
        for (; i <10 ; i++)
        {
            if (Table[i].key.empty())
                //do nothing
            else
            {

                one = Table[i].next;
                Node * two  = one;
                Table[i].key = "";//Makes the string empty
                Table[i].next = NULL;
                while(one->next)
                {
                    two = one->next;
                    one->key = "";
                    one->next = NULL;
                    delete one;

                    one = two;

                }
            }

        }
    }

        if (isEmpty())
            return;
        int i = 0;
        for (; i < 10; i++)
        {
            while
        }
    }
//    void base_clear()
//    {
//        int i = 0;
//        for (; i < 10;
//    }

};


int OHash::hash (string value)
{
    if (value.length()> 9)
        return 9;

    return value.length();
}

#endif // OHASH_H
