#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"
#include <string>

#include <iostream>
using namespace std;
template <class T>
class ArrayList : public List<T>
{
private:
    T * array_pointer;
    int list_size;
    int num_elements;
    int current_position;
public:

    ArrayList ();//
    ~ArrayList();
    void reset();//
    void append(T); //
    T getNext();
    void remove(T);
    void clear();
    int getLength () const;  //
    void print() const;
    bool isFull() const; //
    bool isEmpty() const;
    T retrieve (int) const;
};


template <class T>
void ArrayList <T> :: clear()
{
    num_elements = 0;
}

template <class T>
void ArrayList <T> :: remove(T value)
{

}



template <class T>
void ArrayList <T> :: append(T value)
{
    if (isFull())
    {
            cout << "Array is full, cannot append" <<endl;
            return;
    }



    array_pointer[num_elements] = value;
    num_elements++;
}


template <class T>
T ArrayList <T> :: getNext()
{
    if (isEmpty())
    {
        string error_message = "Error: out of bounds";
                throw error_message;
    }

    current_position++;
    return array_pointer[current_position];
}




template <class T>
T ArrayList <T> :: retrieve(int element) const
{
    string error_message;
    error_message = "Error: element out of bounds.";
    if ((element <(current_position +1)) || (element > (num_elements -1)))
    {
        throw  error_message;
    }
    else
    return array_pointer[element];

}

template <class T>
void ArrayList <T> :: print() const
{
    if (isEmpty())
    {
        cout << "The list is empty" <<endl;
    }
    else
    {
        int i = 0;
        while ( i < num_elements)
        {
            cout << array_pointer[i] << " -> " ;
            i++;
        }
        cout << endl;
    }
}


template <class T>
bool ArrayList <T> :: isEmpty () const
{
    if (num_elements ==0)
        return true;
    return false;
}
template <class T>
void ArrayList<T>::reset()
{
    current_position =-1;
}

template <class T>
ArrayList <T> :: ~ArrayList ()
{
    delete [] array_pointer;
    num_elements = 0;
}

template <class T>
ArrayList <T> :: ArrayList ()
{
    array_pointer = new T[25];
    list_size = 25;
    num_elements = 0;
}

template <class T>
int ArrayList <T> :: getLength () const
{
    return num_elements;

}
template <class T>
bool ArrayList <T> :: isFull () const
{
    if (num_elements==list_size)
        return true;
    return false;
}

#endif
