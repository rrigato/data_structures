#include <iostream>
using namespace std;
   
#include "OrderedArrayList.h"
   
int main()
{
    OrderedArrayList oll(8);
    oll.insert("Stalica", "Hank", "925-555-1234");
    oll.insert("Stalica", "Hank", "925-555-1234");
    oll.insert("Bob", "Hank", "925-555-1234");
    oll.insert("Fred", "Hank", "925-555-1234");
   oll.insert("Joe", "Hank", "925-555-1234");
    oll.insert("Xkdfj", "Hank", "925-555-1234");
   oll.insert("Zrdfs", "Hank", "925-555-1234");
    oll.insert("Fekf", "Hank", "925-555-1234");
   
    oll.print();
    cout << oll.length() << endl;

        
	oll.print();
    cout << oll.search("Fekf") << endl;
     cout << oll.search("Stalica") << endl;
      cout << oll.search("Stlcia") <<endl;

     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;
     oll.remove("Stalica") ;
	oll.print();
	cout << endl;

     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;     cout << oll.search("Stalica") << endl;
     oll.remove("Zrdfs");
	oll.print();

	cout << endl;
     oll.remove("Xkdfj");
	oll.print();

	cout << endl;
     oll.remove("Joe");
	oll.print();

	cout << endl;
     oll.remove("Fred");
	oll.print();
	

	cout << endl;
     oll.remove("Stalica");
	oll.print();
	
  //    oll.remove("Efowejnf");

     oll.remove("Fred");
      cout << oll.length() <<endl;

        
        
      oll.clear();
   

   
    oll.print();
    cout << oll.length() << endl;




    // Test 1: Insert 3 records into the list
    oll.insert("Doe", "John", "555-1234" );
    oll.insert("Jones", "Jim", "555-1235" );
    oll.insert("Branson", "Richard", "555-1236");
    
    // Test 2:  Print List
    /* Expected output the records in order, for example:
        Branson, Richard, 555-1236
        Doe, John, 555-1234
        Jones, Jim, 555-1235    
    */
    oll.print();
    
    // Test 3:  length.  Expected output:  3
    cout << oll.length() << endl;
    
    // Test 4:  isEmpty. Expected output: false
    cout << oll.isEmpty() << endl;

    // Test 5:  Search for Jim Jones. Expected output, 2
    cout << oll.search("Jones") << endl;
    
    // Test 6:  Remove John Doe, the print list.
    // expected output: something like:
    /*  Branson, Richard, 555-1236
        Jones, Jim, 555-1235    */
    oll.remove("Doe");
    oll.print();
    
    // Test 7:  clear() the list destroys the list, then print().
    // expected output:  nothing.  List is empty.
    oll.clear();
    oll.print();
    
    // Test 8: isFull() - expected result:  false.
    cout << oll.isFull() << endl;
    
    // Test 9: isEmpty() - expected result: true.
    cout << oll.isEmpty() << endl;
    cin.get();
    return 0;
};
