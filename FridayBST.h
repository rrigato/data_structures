#ifndef FRIDAYBST_H
#define FRIDAYBST_H

#include <iostream>

using namespace std;

class BinaryTree
{
    private:


            struct Node
            {
                int value;
                Node * left;
                Node * right;

            };
            Node * root;
            void destroy(Node * & );
            void insert(int, Node *&);
            void print(Node *) const;
    public:
        BinaryTree();
        ~BinaryTree();
        void destroy();
        void insert(int);
        bool isFull() const;
        void print() const;

};//BinaryTree

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    destroy(root);
}

void BinaryTree::destroy(Node * & one)
{
    if (one == NULL)
    {
        return;
    }
    if (one->left != NULL)
    {
        destroy(one->left);
    }
    if (one->right != NULL)
    {
        destroy(one->right);
    }
    if(one->right != NULL && one->left != NULL)
    {
        delete one;
        one = NULL;
    }

}
bool BinaryTree::isFull() const
{
    try
    {
        Node * newNode;
        newNode = new Node;
        delete newNode;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void BinaryTree::insert(int data)
{
    insert(data, root);

}

void BinaryTree::destroy()
{
    destroy(root);
    return;
}

void BinaryTree::insert(int data, Node *& one)
{
    if(one == NULL)
    {
            Node * newNode = new Node;
            newNode->value = data;
            newNode ->right = NULL;
            newNode->left = NULL;
            one = newNode;
    }
    else if (one->value > data)
    {
        insert(data, one->left);
    }
    else if(one ->value <= data )
    {
        insert(data, one->right);
    }

    return;

}

void BinaryTree::print() const
{
        print(root);


}

void BinaryTree::print(Node * one) const
{
        if (one == NULL)
        {
            return;
        }
        if(one->left != NULL)
        {
            print(one->left);
        }
        if(one->right != NULL)
        {
            print(one->right);
        }
            cout << " " << one->value;


}
#endif // FRIDAYBST_H
