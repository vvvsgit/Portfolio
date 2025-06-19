#include <iostream>

int
main()
{
    int rowSide = 8;
    int columnSide = 16;
    int row = 0;
    std::cout << std::endl;
    while (row < rowSide) {
        int column = 0;
        while (column < columnSide) {
            std::cout << ((row + column) % 2 ? ' ' : '*');
            ++column;
        }
        ++row;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

