#include "FridayBST.h"

int main()
{
    BinaryTree B;
    B.insert(5);
    B.insert(2);
    B.insert(7);
    for(int i = 20; i > 11; i--)
    {
        B.insert(i);
    }
    B.print();
    for (int z = 0; z <= 20; z++)
    {
        B.Remove(z);
    }
    B.Remove(5);
    B.print();
    std::cout << B.isEmpty() <<std::endl;
    B.destroy();
    std::cout << std::endl;
    std::cout << B.isEmpty() <<std::endl;
    B.print();
    std::cin.get();
    return 0;
}

