#include <iostream>

int
main()
{
    int row = 10;
    while (row >= 1) {
        int column = 1;
        while (column <= 10) {
            std::cout << (row % 2 ? '<' : '>');
            ++column;
        }
        --row;
        std::cout << std::endl;
    }
    return 0;
}

