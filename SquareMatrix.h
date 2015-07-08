#include <iostream>

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
class SquareMatrix
{
private:
//     const int row_size = 3;
//     const int column_size = 3;
    double  Matrix [3] [3]  ;
public:
    SquareMatrix();
    ~SquareMatrix();
    void makeEmpty(int);
    void storeValue (int, int, double);
    void add (SquareMatrix);
    double getElement(int, int) const;
    void copy(SquareMatrix);
    void subtract (SquareMatrix);
    void print() const;

};
void SquareMatrix::print () const
{

    int row_num, column_num;
    for ( row_num =0 ; row_num < 3; row_num++)
    {
        for(column_num = 0 ; column_num < 3; column_num++)
        {

            std::cout << Matrix [row_num] [column_num] << " " ;
        }
        std::cout << std::endl;
    }
}
void SquareMatrix::subtract(SquareMatrix s)
{


    int row_num, column_num;
    for ( row_num =0 ; row_num < 3; row_num++)
    {
        for(column_num = 0 ; column_num < 3; column_num++)
        {

            Matrix [row_num] [column_num]  = Matrix [row_num] [column_num]  - s.getElement(row_num, column_num);
        }
    }

}
void SquareMatrix::copy (SquareMatrix s)
{
    int row_num, column_num;
    for ( row_num =0 ; row_num < 3; row_num++)
    {
        for(column_num = 0 ; column_num < 3; column_num++)
        {

            Matrix [row_num] [column_num]  = s.getElement(row_num, column_num);
        }
    }

}
double SquareMatrix::getElement (int i, int j) const
{
    return Matrix[i] [j];
}
void SquareMatrix::add (SquareMatrix s)
{
    int row_num, column_num;
    for ( row_num =0 ; row_num < 3; row_num++)
    {
        for(column_num = 0 ; column_num < 3; column_num++)
        {

            Matrix [row_num] [column_num]  = Matrix [row_num] [column_num] + s.getElement(row_num, column_num);
        }
    }

}

void SquareMatrix::storeValue (int i, int j, double value)
{
    Matrix [i] [j] = value;
}
void SquareMatrix::makeEmpty(int n)
{
    int row_num, column_num;
    for ( row_num =0 ; row_num < n; row_num++)
    {
        for(column_num = 0 ; column_num < n; column_num++)
        {

            Matrix [row_num] [column_num] = 0;
        }
    }
}
SquareMatrix ::SquareMatrix()
{
    makeEmpty(3);
}
SquareMatrix::~SquareMatrix()
{

}

#endif // SQUAREMATRIX_H
