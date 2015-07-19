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
		OrderedArrayList();
		OrderedArrayList(int);
		~OrderedArrayList();
};
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
