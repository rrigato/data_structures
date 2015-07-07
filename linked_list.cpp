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

};
linked_list :: linked_list()
{
	Head = 0;
}
int main ()
{
	return 0;
}
