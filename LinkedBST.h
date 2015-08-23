#ifndef LINKEDBST_H
#define LINKEDBST_H

#include <iostream>
#include "LBST.h"
using namespace std;

class LinkedBST : public LBST
{
    private:
        void insert(Node *&, char);
        void delTree(Node *&);
        void postprint(Node *) const;
        void preprint(Node *) const;
        bool search( Node *, char) const;
        void seek ( Node * &, char);
        void destroy (Node * & );
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
        void seek (char);

};
void LinkedBST ::insert(Node *& r, char data)
{

    if (r == NULL)
    {
            Node * newNode = new Node;
            newNode->left = NULL;
            newNode->right = NULL;
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

void LinkedBST:: seek( char value)
{
    seek(root, value);
}

void LinkedBST :: seek (Node * & r, char value)
{
    if (r == NULL)
        return;
    else if (r->key == value)
        destroy(r);
    else if (r->key < value)
        seek(r->right, value);
    else
        seek(r->left, value);
}

void LinkedBST :: destroy(Node * & r)
{
    Node * one = NULL;
    if (r->right == NULL && r->left == NULL)
    {
        delete r;
        r = NULL;

    }
    else if (r->right ==NULL && r->left != NULL)
    {
        one = r;
        r = r->left;
        delete one;


    }
    else if (r->right !=NULL && r->left == NULL)
    {
        one = r;
        r = r->right;
        delete one;
    }
    else
    {
        one = r->right;
        while (one->left != NULL)
            one = one->left;
        one->left = r->left;
        one = r;
        r = r->right;
        delete one;
    }
}

#endif // LINKEDBST_H
