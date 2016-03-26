##This repository implements some common data structures using C++

####Friday Linked List 3/25/2016
[FridayLL.h] (https://github.com/rrigato/data_structures/blob/master/FridayLL.h) is a dynamic Linked List implemented in C++
The linked list contains one variable a simple integer, however, this can easily be modified to hold any data type (even abstract ones!)
#####Methods implemented for the Linked List
* isFull = checks if C++ can allocate memory for a new node
* isEmpty = checks if the list is empty
*	putItem = places a value in the list, returns 0 if succesful, -1 otherwise
* destroy = removes all nodes from the linked list and deallocates their memory
* print = displays all nodes in linked list, or nothing if the list is empty
* search = returns true if a node containing the value provided is found, false otherwise
* remove = removes a node from the list. returns 0 if the data node was found, -1 otherwise

[FridayLL.cpp] (https://github.com/rrigato/data_structures/blob/master/FridayLL.cpp) is a test file, that tests every method in FridayLL.h
