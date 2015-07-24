#ifndef ORDEREDARRAYLIST_H
#define ORDEREDARRAYLIST_H
#include <iostream>
#include <string>
#include "List.h"
using namespace std;
class OrderedArrayList : public List
{
    private:
        int num_elements;
        int max_num;
        Record * Array_list;
           
    public:
        void remove(string);
        void clear();
        int length () const;
        int search (string) const;
        void print () const;
        void insert (string, string, string);
        bool isFull () const;
        bool isEmpty() const;
        OrderedArrayList();
        OrderedArrayList(int);
        ~OrderedArrayList();
           
};
  
void OrderedArrayList::remove(string last_name)
{
    if (isEmpty())
	return;
    int element;
    element = search(last_name);
    if (element == -1)
        return;
    int i ;
    for (i = element; i < num_elements -1; i++)
    {   
 	Array_list[i] = Array_list[i+1];
    }
    num_elements --;
} 
void OrderedArrayList::clear()
{
    num_elements = 0;
}
int OrderedArrayList::length () const
{
    return num_elements;
}
int OrderedArrayList::search(string last_name) const
{
    int left = 0;
    int right = num_elements -1;
    int middle  ; 
    while (left <= right )
    {
        middle = (left + right)/2;
        if (Array_list[middle].last == last_name)
            return middle;
        else if (Array_list[middle].last > last_name)
        {
            right = middle -1;
        }
        else
        {
            left = middle +1;
        }
    }
    return -1;
}
  
void OrderedArrayList::print() const
{
    if (isEmpty())
        return;
    int i =0;
    for (; i < num_elements; i++)
    {
        cout << Array_list[i].last << " "<< Array_list[i].first << " " << Array_list[i].phone <<endl;
    }
}
void OrderedArrayList:: insert(string last_name, string first_name, string phone_num)
{
    Record newRecord;
    newRecord.last =last_name;
    newRecord.first = first_name;
    newRecord.phone = phone_num;
    if (isFull())
    {        
        return;
    }   
    int i =0;
    for ( i = num_elements-1 ; i >= 0 && Array_list[i].last > last_name; i--)
            Array_list[i+1] = Array_list[i];
    Array_list[i+1] = newRecord;
    num_elements++;
}
bool OrderedArrayList::isEmpty() const
{
    return num_elements == 0;
}
bool OrderedArrayList::isFull() const
{
    return num_elements == max_num;
}
OrderedArrayList::OrderedArrayList()
{
    Array_list = new Record[10];
    num_elements = 0;
    max_num = 10;
}
OrderedArrayList::OrderedArrayList(int length)
{
    Array_list = new Record[length];
    num_elements = 0;
    max_num = length;
}
   
OrderedArrayList::~OrderedArrayList()
{
    delete [] Array_list;
}
#endif
