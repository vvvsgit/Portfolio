#include <iostream>

int
main()
{
    std::cout << std::endl;

    int sales[3][5];
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 5; ++column) {
            sales[row][column] = 0;
            std::cout << '[' << row << "][" << column << "] ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

