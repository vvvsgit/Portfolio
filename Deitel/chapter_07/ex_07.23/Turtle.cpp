#include "Turtle.hpp"

#include <iostream>
#include <cassert>

Turtle::Turtle()
{
    setFloor(false);
    setX(0);
    setY(0);
    setPen(UP);
    setDirection(SOUTH);
}

void
Turtle::setFloor(bool floor)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            floor_[i][j] = floor;
        }
    }
}

void
Turtle::setX(int x)
{
    x_ = x;
}

void
Turtle::setY(int y)
{
    y_ = y;
}

int
Turtle::getX()
{
    return x_;
}


int
Turtle::getY()
{
    return y_;
}

void
Turtle::setPen(Pen pen)
{
    pen_ = pen;
}

Pen
Turtle::getPen()
{
    return pen_;
}

void
Turtle::setDirection(Direction direction)
{
    direction_ = direction;
}

Direction
Turtle::getDirection()
{
    return direction_;
}

void
Turtle::runTurtle()
{
    std::cout << std::endl;
    while (true) {
        int command = printCommands();
        if (0 == command) { break; }
        chooseCommand(command);
    }
    std::cout << std::endl;
}

int
Turtle::printCommands()
{
    int command;
    std::cout << "\n 1 ... Pen up\n"
              << " 2 ... Pen down\n"
              << " 3 ... Turn right\n"
              << " 4 ... Turn left\n"
              << " 5 ... Move forward\n"
              << " 6 ... Print floor\n"
              << " 7 ... Erase mode\n"
              << " 8 ... Show cordinates\n"
              << " 9 ... Show direction\n"
              << " 0 ... End of data\n"
              << "\t\tCommand > ";
    std::cin >> command;
    if (command < 0 || command > 9) {
        std::cerr << "\nError 1: No such command." << std::endl;
        ::exit(1);
    }
    std::cout << std::endl;
    return command;
}

void
Turtle::chooseCommand(int command)
{
    switch (command) {
    case 1:  setPen(UP);       break;
    case 2:  setPen(DOWN);     break;
    case 3:  turnRight();      break;
    case 4:  turnLeft();       break;
    case 5:  moveForward();    break;
    case 6:  printFloor();     break;
    case 7:  setPen(ERASE);    break;
    case 8:  showCordinates(); break;
    case 9:  showDirection();  break;
    default: assert(0);        break;
    }
}

void
Turtle::turnRight()
{
    switch (getDirection()) {
    case NORTH: setDirection(EAST);  break;
    case EAST:  setDirection(SOUTH); break;
    case SOUTH: setDirection(WEST);  break;
    case WEST:  setDirection(NORTH); break;
    default:    assert(0);           break;
    }
}

void
Turtle::turnLeft()
{
    switch (getDirection()) {
    case NORTH: setDirection(WEST);  break;
    case EAST:  setDirection(NORTH); break;
    case SOUTH: setDirection(EAST);  break;
    case WEST:  setDirection(SOUTH); break;
    default:    assert(0);           break;
    }
}

void
Turtle::moveForward()
{
    int space = getSpaces();
    while (checkMoveValidity(space)) {
        std::cout << "Invalid spaces. Try again." << std::endl;
        space = getSpaces();
    }
    if (0 == space) { return; }
    if (getDirection() == NORTH) {
        for (int i = 0; i < space; ++i) {
            if (getPen() == DOWN) {
                floor_[getX() - i][getY()] = true;
            }
            if (getPen() == ERASE) {
                floor_[getX() - i][getY()] = false;
            }
        }
        setX(getX() - (space - 1));
    }
    if (getDirection() == EAST) {
        for (int i = 0; i < space; ++i) {
            if (getPen() == DOWN) {
                floor_[getX()][getY() + i] = true;
            }
            if (getPen() == ERASE) {
                floor_[getX()][getY() + i] = false;
            }
        }
        setY(getY() + (space - 1));
    }
    if (getDirection() == SOUTH) {
        for (int i = 0; i < space; ++i) {
            if (getPen() == DOWN) {
                floor_[getX() + i][getY()] = true;
            }
            if (getPen() == ERASE) {
                floor_[getX() + i][getY()] = false;
            }
        }
        setX(getX() + (space - 1));
    }
    if (getDirection() == WEST) {
        for (int i = 0; i < space; ++i) {
            if (getPen() == DOWN) {
                floor_[getX()][getY() - i] = true;
            }
            if (getPen() == ERASE) {
                floor_[getX()][getY() - i] = false;
            }
        }
        setY(getY() - (space - 1));
    }
}

int
Turtle::getSpaces()
{
    std::cout << "\t\tSpaces > ";
    int spaces;
    std::cin >> spaces;
    if (spaces < 0 || spaces > SIZE) {
        std::cerr << "\nError 2: Wrong spaces." << std::endl;
        ::exit(2);
    }
    return spaces;
}

bool
Turtle::checkMoveValidity(int space)
{
    bool validity;
    switch (getDirection()) {
    case NORTH: validity = (getX() - space) < -1;   break;
    case EAST:  validity = (getY() + space) > SIZE; break;
    case SOUTH: validity = (getX() + space) > SIZE; break;
    case WEST:  validity = (getY() - space) < -1;   break;
    default:    assert(0);                          break;
    }
    return validity;
}

void
Turtle::showCordinates()
{
    std::cout << "\n\tTurtle's cordinates are (" << getX() << ", " << getY() << ")\n" << std::endl;
}

void
Turtle::showDirection()
{
    switch (getDirection()) {
    case NORTH: std::cout << "NORTH" << std::endl; break;
    case EAST:  std::cout << "East"  << std::endl; break;
    case SOUTH: std::cout << "SOUTH" << std::endl; break;
    case WEST:  std::cout << "West"  << std::endl; break;
    default:    assert(0);                         break;
    }
}

void
Turtle::printFloor()
{
    const int size = SIZE * 2 + 1;
    std::cout << "┏";
    for (int i = 0; i < size; ++i) {
        std::cout << "━";
    }
    std::cout << "┓" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "┃";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << (floor_[i][j] ? " +" : "  ");
        }
        std::cout << " ┃" << std::endl;
    }
    std::cout << "┗";
    for (int i = 0; i < size; ++i) {
        std::cout << "━";
    }
    std::cout << "┛" << std::endl;
}

