#ifndef __BOARD_HPP__
#define __BOARD_HPP__

const int SIZE = 3;

class Board
{
public:
    Board();

    void setBoard();
    void move(const int x, const int y, const char symbol);
    char getSign(const int x, const int y);
    void print();

private:
    char board_[SIZE][SIZE];
};

#endif

