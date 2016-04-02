##This repository implements some common data structures using C++

####Friday Binary Search Tree 4/01/2016
[FridayBST.h] (https://github.com/rrigato/data_structures/blob/master/FridayBST.h)
The Binary Search Tree is a common tree based list that is used to reduce search time
The driving principle behind the BST is that the current node is always greater than any nodes value in its left subtree and less than
any value in its right subtree.
#####Methods implemented for the Binary Search Tree
*isFull = checks to see if you can allocate enough memory for a new node
*isEmpty = checks to see if their are any nodes currently in the BST
*destroy = removes all nodes from the BST and deallocates the memory they used. Also has a wrapper function for the public interface
*insert = inserts a value into the BST while maintaining the properties of a BST. Also has a wrapper function for the public interface
*print = displays all nodes in the BST or nothing if it is empty

[FridayBST.cpp] (https://github.com/rrigato/data_structures/blob/master/FridayBST.cpp)
Client used for testing the Binary Search tree.



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
