#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>

class Player
{
public:
    Player(const std::string name, const char symbol, const bool isComputer = false);
    void setSymbol(const char symbol);
    char getSymbol();
    void setIsComputer(const bool isComputer);
    bool getIsComputer();

private:
    const std::string name_;
    char symbol_;
    bool isComputer_;
};

#endif
