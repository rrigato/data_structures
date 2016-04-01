#include "FridayBST.h"

int main()
{
    BinaryTree B;
    B.insert(5);
    B.insert(2);
    B.insert(7);
    B.print();
    B.destroy();
    std::cout << std::endl;
    B.print();
    std::cin.get();
    return 0;
}
