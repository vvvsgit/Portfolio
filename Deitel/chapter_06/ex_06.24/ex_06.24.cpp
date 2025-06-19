#include <iostream>

void checkmateBoard();

int
main()
{
    checkmateBoard();
    return 0;
}

void
checkmateBoard()
{
    for (int column = 1; column <= 8; ++column) {
        for (int row = 1; row <= 16; ++row) {
            if (0 == (column + row) % 2) {
                std::cout << ' ';
            } else {
                std::cout << '*';
            }
        }
        std::cout << std::endl;
    }
}

