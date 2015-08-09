#include "DLinkedList.h"
using std::cout;
using std::endl;
int main ()
{
    DLinkedList test;
    cout << test.isEmpty() <<endl;
    int i = 0;
//    for (; i < 100; i++)
//    {
//        cout << test.isFull() << " " ;
//    }
    i = 10;
    for (; i >0; i--)
        test.insert(i);

    test.insert (7);
    test.insert(11);
    int z = 0;
    cout <<endl;
    test.reset();
    cout << test.getNext(z) <<endl;
    cout << z << endl;
    cout << test.find(5) <<endl;
        cout << test.find(11) <<endl;
            cout << test.find(20) <<endl;
                cout << test.find(-5) <<endl;
//    for ( g =0 ; g < 12 ; g++)
//    {
//       cout << test.getNext(z) << " " << z << " ";
//    }
    cout <<endl;
    test.print();
    test.rprint();
    DLinkedList test2;
    test2 = test;
    test2.print();
     DLinkedList test3(test2);
     test3.print();

    cout << test.isFull() <<endl;

    cout << test.getLength() <<endl;


    test.remove(1);test.remove(5);test.remove(8);test.remove(11); cout <<test.remove(20)<<endl;
    test.print();
    test.rprint();
    cout << test.getLength()<<endl;


    test.clear();
    cout << test.getLength() <<endl;
    test.print();
    test.rprint();
    cout << (test < test2) <<endl;

    cout << (test2 < test3) <<endl;
    cout << (test == test2) <<endl;

    cout << (test2 == test3) <<endl;
    return 0;
}
