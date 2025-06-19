#include "headers/TicTacToe.hpp"

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <cassert>

TicTacToe::TicTacToe(const std::vector<Player*>& players, Board& board)
{
    assert(2 <= players.size());
    assert(players[0]->getSymbol() != players[1]->getSymbol());

    players_ = players;
    board_ = &board;

    if (!(::isatty(STDIN_FILENO))) {
        std::srand(std::time(0));
    }
}

void
TicTacToe::play()
{
    while(true) {
        printMenuOptions();

        int choice;
        std::cin >> choice;
        if (!(::isatty(STDIN_FILENO))) {
            std::cout << choice << std::endl;
        }
        switch (choice) {
        case 1:  playVsComputer(); break;
        case 2:  playVsPlayer();   break;
        case 0:  return;           break;
        default: assert(0);        break;
        }
    }
}

void
TicTacToe::printMenuOptions()
{
    std::cout << "\n\n\t𝓣 𝓘 𝓒 𝓣 𝓐 𝓒 𝓣 𝓞 𝓔\n" << std::endl;
    std::cout << "\t  O\\Main Menu/X\n"  << std::endl;
    std::cout << "\t> Single Player - 1" << std::endl;
    std::cout << "\t> Multi Player  - 2" << std::endl;
    std::cout << "\t> Exit          - 0" << std::endl;
    std::cout << "\n  > Choice ";
}

void
TicTacToe::playVsComputer()
{
    printWhosFirstOptions();
    int choice;
    std::cin >> choice;
    assert(!(choice != 1 && choice != 2));

    if (!(::isatty(STDIN_FILENO))) {
        std::cout << choice << std::endl;
    }
    
    players_[choice % 2]->setIsComputer(true);
    playVsPlayer();
    players_[choice % 2]->setIsComputer(false);
}

void
TicTacToe::printWhosFirstOptions()
{
    std::cout << "   First move?" << std::endl;
    std::cout << "   Player   - 1" << std::endl;
    std::cout << "   Computer - 2" << std::endl;
    std::cout << " > Choice ";
}

void
TicTacToe::playVsPlayer()
{
    board_->setBoard();
    board_->print();
    const int moves = SIZE * SIZE;
    for (int i = 0; i < moves; ++i) {
        std::cout << "\n " << players_[i % 2]->getSymbol() << "'s move\n";
        nextMove(i);
        board_->print();
        if (isWin()) {
            std::cout << "Congratulations " << players_[i % 2]->getSymbol() << " has won the game.\n" << std::endl;
            return;
        }
    }
    std::cout << "It's a tie.\n" << std::endl;
}

void
TicTacToe::nextMove(const int turn)
{
    int x, y;
    if (players_[turn % 2]->getSymbol() != 'C') {
        std::cout << "    Row: ";
        std::cin >> x;
        if (!(::isatty(STDIN_FILENO))) {
            std::cout << x << std::endl;
        }
        std::cout << " Column: ";
        std::cin >> y;
        if (!(::isatty(STDIN_FILENO))) {
            std::cout << y << std::endl;
        }
        assert(!(x > 3 || x < 1 || y > 3 || y < 1));
    } else {
        while (true) {
            x = rand() % 3 + 1;
            y = rand() % 3 + 1;
            if (' ' == board_->getSign(x, y)) break;
        }
    }
    if (' ' != board_->getSign(x, y)) {
        std::cout << "Warning 1: move not available, try again" << std::endl;
        nextMove(turn);
        return;
    }
    board_->move(x, y, players_[turn % 2]->getSymbol());
}

bool
TicTacToe::isWin()
{
    if (isRowWin()) return true;
    if (isColumnWin()) return true;
    if (isDiagonalWin()) return true;
    if (isSecondDiagonalWin()) return true;
    return false;
}

bool
TicTacToe::isRowWin()
{
    for (int i = 1; i <= SIZE; ++i) {
        if (isRowWin(i)) return true;
    }
    return false;
}

bool
TicTacToe::isRowWin(const int row)
{
    int column = 1;
    const char sign = board_->getSign(row, column);
    if (sign == ' ') return false;
    for (++column; column <= SIZE; ++column) {
        if(sign != board_->getSign(row, column)) return false;
    }
    return true;
}

bool
TicTacToe::isColumnWin()
{
    for (int i = 1; i <= SIZE; ++i) {
        if (isColumnWin(i)) return true;
    }
    return false;
}

bool
TicTacToe::isColumnWin(const int column)
{
    int row = 1;
    const char sign = board_->getSign(row, column);
    if (sign == ' ') return false;
    for (++row; row <= SIZE; ++row) {
        if (sign != board_->getSign(row, column)) return false;
    }
    return true;
}

bool
TicTacToe::isDiagonalWin()
{
    int rowColumn = 1;
    const char sign = board_->getSign(rowColumn, rowColumn);
    if (sign == ' ') return false;
    for (++rowColumn; rowColumn <= SIZE; ++rowColumn) {
        if (sign != board_->getSign(rowColumn, rowColumn)) return false;
    }
    return true;
}

bool
TicTacToe::isSecondDiagonalWin()
{
    int row = 1;
    int column = SIZE;
    const char sign = board_->getSign(row, column);
    if (sign == ' ') return false;
    for (++row, --column; row <= SIZE; ++row, --column) {
        if (sign != board_->getSign(row, column)) return false;
    }
    return true;
}

