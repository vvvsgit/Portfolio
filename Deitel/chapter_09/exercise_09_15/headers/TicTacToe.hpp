#ifndef __TIC_TAC_TOE_HPP__
#define __TIC_TAC_TOE_HPP__

#include "headers/Player.hpp"
#include "headers/Board.hpp"

#include <vector>

class TicTacToe
{
public:
    TicTacToe(const std::vector<Player*>& players, Board& board);

    void play();

private:
    void playVsComputer();
    void playVsPlayer();
    void nextMove(const int turn);

    bool isWin();
    bool isRowWin();
    bool isRowWin(const int row);
    bool isColumnWin();
    bool isColumnWin(const int column);
    bool isDiagonalWin();
    bool isSecondDiagonalWin();

    void printMenuOptions();
    void printWhosFirstOptions();

private:
    std::vector<Player*> players_;
    Board* board_;
};

#endif

