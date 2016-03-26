#include <iostream>
#include "FridayLL.h"
using namespace std;

int main()
{
    Linked L;
    cout << "Is the linked list full:" << L.isFull() <<endl;
    cout << "Is the linked list empty:"<< L.isEmpty() <<endl;

    L.putItem(10);
    for(int i = 22; i >12; i--)
    {
        L.putItem(i);
    }
    L.putItem(5);
    L.print();

    cout << "Searchs for 0, 5, 7, 20, 22: " << " " << L.search(0)
     << ", "  <<L.search(5)
    << ", " << L.search(7) << ", " << L.search(20)
    <<", " << L.search(22) <<endl;

    cout << "removes for 0, 5, 7, 20, 22: " << " " << L.remove(0)
     << ", "  <<L.remove(5)
    << ", " << L.remove(7) << ", " << L.remove(20)
    <<", " << L.remove(22) <<endl;
    L.destroy();
    L.print();

    cin.get();
	return 0;
}
