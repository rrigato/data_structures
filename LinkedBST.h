
#ifndef LINKEDBST_H
#define LINKEDBST_H

//#include "BST.h"
#include <iostream>
using namespace std;


class LBST
{
    protected:

    struct Node
    {
        char key;
        Node* left, *right;
    } *root;

    // private, helper methods.
    void inprint( Node* r ) const       // recursively displays tree inorder
    {
        if ( r == NULL )
            return;

        inprint( r->left );
        cout << r->key << " ";
        inprint( r->right );
    }

 virtual   void preprint( Node* ) const = 0;   // recursively displays tree preorder
 virtual   void postprint( Node* ) const = 0;  // recursively displays tree postorder
   virtual  void insert( Node*&, char ) = 0;     // recursively inserts a node
virtual    bool search( Node*, char ) const = 0; // recursively finds a node
/*    void seek( Node*&, char ) = 0;      // searches for node to destroy, then
   virtual void destroy( Node*& ) = 0; */        // calls this to destroys a node
    virtual void delTree( Node*& ) = 0;         // destroys tree, call in destructor

    public:
    // public interface methods call the private helper methods.
    // I've done inprint() to get you started.
    void inprint() const            // displays tree using inorder traversal
    {
        inprint( root );
        cout << endl;
    }

    virtual void preprint() const = 0;      // calls preprint( Node* )
   virtual void postprint() const = 0;     // calls postprint( Node* )
    virtual void insert( char ) = 0;        // calls insert( Node*&, char )
  //  void seek( char ) = 0;          // calls seek( Node*&, char )
virtual    bool search( char ) const = 0;  // calls search( Node*, char )
    virtual bool isEmpty() const = 0;       // empty=true, otherwise false
};





class LinkedBST : public LBST
{
    private:
        void insert(Node *&, char);
        void delTree(Node *&);
        void postprint(Node *) const;
        void preprint(Node *) const;
        bool search( Node *, char) const;
    public:
        void insert(char);
        LinkedBST()
        {
            root = NULL;
        }
        ~LinkedBST()
        {
            delTree(root);
        }
        void postprint() const;
        bool isEmpty() const;
        void preprint() const;
        bool search (char) const;

};
void LinkedBST ::insert(Node *& r, char data)
{
    Node * newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    if (r == NULL)
    {
            r= newNode;
            r->key = data;
    }
    else if (r->key < data)
    {
        insert(r->right, data);
    }
    else
    {


        insert(r->left, data);
    }
}
void LinkedBST :: insert(char data)
{
    insert(root, data);
}

void LinkedBST::delTree(Node *& r)
{
    if (r == NULL)
        return;
    delTree(r->left);
    delTree(r->right);
    delete r;
}

void LinkedBST::postprint(Node * r) const
{
    if (r == NULL)
        return;
    postprint(r->left);
    postprint(r->right);
    cout << r->key << " ";

}
void LinkedBST:: postprint() const
{
    postprint(root);
}

bool LinkedBST::isEmpty() const
{
    return root == NULL;
}
void LinkedBST :: preprint() const
{
    preprint(root);
}

void LinkedBST:: preprint(Node * r) const
{
    if (r == NULL)
        return;
    cout << r->key << " ";
    preprint(r->left);
    preprint(r->right);
}

bool LinkedBST :: search (Node * r, char value) const
{
    if ( r == NULL)
        return false;
    else if (r->key == value)
        return true;
    else if (r->key > value)
        return search(r->left, value);
    else
        return search(r->right, value);
}

bool LinkedBST :: search(char value) const
{
    return search (root, value);
}

#endif // LINKEDBST_H
