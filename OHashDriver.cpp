#include "OHash.h"
#include <iostream>
using namespace std;
int main()
{
    OHash test;
    cout << test.isEmpty() <<endl;
        cout << test.isFull() <<endl;

    test.insert("Hello");
    test.insert("Jello");

        test.insert("Sello");
            test.insert("Tello");

    test.insert("Hello");
    test.insert("World");
    test.insert("Goodbye");
    test.print();
    cout << test.search("Hello") << endl;
    test.remove("World");
    test.print();

            test.print();
            test.clear();
            cout << test.isEmpty() <<endl;
    return 0;
}
