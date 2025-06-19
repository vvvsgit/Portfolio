#include "headers/Board.hpp"

#include <iostream>
#include <cassert>

Board::Board()
{
    setBoard();
}

void
Board::setBoard()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board_[i][j] = ' ';
        }
    }
}

void
Board::move(const int x, const int y, const char symbol)
{
    assert(!(x > 3 || x < 0 || y > 3 || y < 0));
    board_[x - 1][y - 1] = symbol;
}

char
Board::getSign(const int x, const int y)
{
    return board_[x - 1][y - 1];
}

void
Board::print()
{
    std::cout << "    1 2 3 " << std::endl;
    std::cout << "   ┏━┳━┳━┓" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << " " << i + 1 << ' ';
        for (int j = 0; j < SIZE; ++j) {
            std::cout << "┃" << board_[i][j];
        }
        std::cout << "┃ " << i + 1 << std::endl;
        if (i < 2) std::cout << "   ┣━╋━╋━┫" << std::endl;
    }
    std::cout << "   ┗━┻━┻━┛" << std::endl;
    std::cout << "    1 2 3 " << std::endl;
}

