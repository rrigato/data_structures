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
            int findNode(int, Node *&);
            int Remove(int, Node *&);

    public:
        BinaryTree();
        ~BinaryTree();
        void destroy();
        void insert(int);
        bool isFull() const;
        void print() const;
        bool isEmpty()const;
        int Remove(int);

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
    if (isFull())
    {
        cout << "Error: unable to allocate necessary memory" <<endl;
        return;
    }
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

bool BinaryTree::isEmpty() const
{
    return root == NULL;
}

int BinaryTree::Remove(int data)
{
    return findNode(data, root);

}

int BinaryTree::findNode(int data, Node *& one)
{
    if(one == NULL)
    {
        return -1;
    }
    if (one->value == data)
    {
        return Remove(data, one);
    }
    else if(one->value < data)
    {
        return findNode(data, one->right);
    }
    else if(one->value > data)
    {
        return findNode(data, one->left);
    }
    return -1;
}

int BinaryTree::Remove(int data, Node *& one)
{


    if(one->left == NULL && one->right == NULL)
    {
        delete one;
        one = NULL;
        return 0;
    }
    else if(one->left != NULL && one->right == NULL)
    {
        Node *two = one;
        one = one->left;
        delete two;
        two = NULL;
        return 0;
    }
    else if(one->left != NULL && one->right != NULL)
    {
        Node * two = one;
        Node * three = one->left;
        one = one->right;
        while(three->right != NULL)
        {
            three = three->right;
        }
        three->right = one;

        delete two;
        two = NULL;
        return 0;

    }
    return -1;
}
#endif // FRIDAYBST_H
