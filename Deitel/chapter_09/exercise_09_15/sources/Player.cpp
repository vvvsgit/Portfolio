#include "headers/Player.hpp"

#include <cassert>

Player::Player(const std::string name, const char symbol, const bool isComputer)
    : name_(name)
{
    setSymbol(symbol);
    setIsComputer(isComputer);
}

void
Player::setSymbol(const char symbol)
{
    assert(symbol != ' ');
    symbol_ = symbol;
}

char
Player::getSymbol()
{
    return symbol_;
}

void
Player::setIsComputer(const bool isComputer)
{
    isComputer_ = isComputer;
}

bool 
Player::getIsComputer()
{
    return isComputer_;
}

