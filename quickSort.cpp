
#include <iostream>
using namespace std;
void quickSort(double [], int, int);
void split(double [], int, int, int &, int &);
int main ()
{
    double array_name[30];
    double i = 1.1;
    int z = 0;
    while (z <30)
    {
        array_name[z] = i;
        z++;
        i++;
    }
    quickSort(array_name, 0, 29);
    return 0;
}

void quickSort(double array_name[], int first, int last)
{
    int splitPt1, splitPt2;
    split(array_name, first, last, splitPt1, splitPt2);

}

void split(double array_name[], int first, int last, int & splitPt1, int & splitPt2)
{
    double splitVal = array_name[(first + last)/2];
}
