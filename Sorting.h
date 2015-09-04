#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using std:: cout;
using std:: endl;
template <class Z>
class Sorting
{
public:
    void merge_sort(Z [], int, int);
    void merge(Z [], int, int, int, int);

};
template <class Z>
void Sorting<Z>:: merge(Z array_name[], int left_start, int left_end, int right_start, int right_end)
{
    if( array_name[left_end] < array_name[right_start])
        return;
}
template <class Z>
void Sorting<Z> :: merge_sort (Z array_name[], int start, int end)
{
    if (start == end)
        return;
    int middle = (end +);
    merge_sort(array_name, start, middle);
    merge_sort(array_name, middle, end);
    




}
#endif
