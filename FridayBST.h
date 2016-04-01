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
            int insert(int, Node *&);
    public:
        BinaryTree();
        ~BinaryTree();
        void destroy();
        int insert(int);
        bool isFull() const;

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

int BinaryTree::insert(int data)
{
    return insert(data, root);

}

void BinaryTree::destroy()
{
    destroy(root);
}

int BinaryTree::insert(int data, Node *& one)
{
    if(one == NULL)
    {
            Node * newNode = new Node;
            newNode->value = data;
            newNode ->right = NULL;
            newNode->left = NULL;

    }
    if (one->value > data)
    {
        insert(data, one->left);
    }
    else if(one ->value <= data )
    {
        insert(data, one->right);
    }

}
#endif // FRIDAYBST_H
