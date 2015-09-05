#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using std:: cout;
using std:: endl;
template <class Z>
class Sorting
{
    int Max_Items;
public:
    Sorting()
    {
        Max_Items =1000;
    }
    void merge_sort(Z [], int, int);
    void merge(Z [], int, int, int, int);

};
template <class Z>
void Sorting<Z>:: merge(Z  array_name[], int left_start, int left_end, int right_start, int right_end)
{
    Z temp_array[Max_Items];
    int index = left_start;
    int save_first = left_start;
    while((left_start <= left_end) && (right_start <= right_end))
    {
        if (array_name[left_start] < array_name[right_start])
        {
            temp_array[index] = array_name[left_start];
            left_start++;
        }
        else
        {
            temp_array[index]= array_name[right_start];
            right_start++;
        }
        index++;
    }
    while(left_start <= left_end)
    {
        temp_array[index] = array_name[right_start];
        left_start++;
        index++;
    }
    for (index = save_first; index <= right_end; index ++)
    {
        array_name[index] = temp_array[index];
    }
}
template <class Z>
void Sorting<Z> :: merge_sort (Z  array_name[], int start, int end)
{
    if (start < end)
        return;
    int middle = (end + start)/2;
    merge_sort(array_name, start, middle);
    merge_sort(array_name, middle+1, end);
    merge(array_name, start, middle, middle+1, end);
}
#endif
