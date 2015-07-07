#include <iostream>
class linked_list
{
private:
	struct node
	{
		int value;
		node * Next;
	};
	node * Head;
	
public:
	linked_list();
	void append( int);

};
linked_list :: linked_list()
{
	Head = 0;
}
void linked_list:: append( int num)
{		
	node * newNode = new node;
	newNode->value = num;
	
	if (Head)
	{
		node * one = Head -> Next;
		while (one)
		{
			one = one->Next;
		}

		one->Next = newNode;
	}
	else
	{
		Head = newNode;
	}
	
}

int main ()
{
	return 0;
}
