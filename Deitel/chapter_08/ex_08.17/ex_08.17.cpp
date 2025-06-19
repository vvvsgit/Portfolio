#include <iostream>
#include <cassert>

void waitForIt();
int getRandomNumber();
int moveTortoise(int, int);
int moveHare(int, int);
void checkPositions(int, int);
void printRoad(int, int);

const int RACE = 70;

int
main()
{
    std::cout << std::endl;

    std::srand(time(0));
    int tortoise = 0;
    int hare = 0;

    std::cout << "BANG!!!!!\nAND THEY'RE OFF!!!!!\n" << std::endl;
    printRoad(tortoise, hare);
    while (tortoise < RACE - 1 && hare < RACE - 1) {
        waitForIt();

        const int percentage = getRandomNumber();
        tortoise = moveTortoise(tortoise, percentage);
        if (tortoise < 0) {
            tortoise = 0;
        }
        hare = moveHare(hare, percentage);
        if (hare < 0) {
            hare =  0;
        }

        printRoad(tortoise, hare);
        checkPositions(tortoise, hare);
    }
    std::cout << std::endl;
    return 0;
}

void
waitForIt()
{
    std::cout << std::endl;
    for (int i = 0; i < 300000000; ++i);
}

int
getRandomNumber()
{
    return std::rand() % 10 + 1;
}

int
moveTortoise(int tortoise, int move)
{
    switch (move) {
    case 1: case 2: case 3: case 4: case 5: tortoise += 3; break;
    case 6: case 7:                         tortoise -= 6; break;
    case 8: case 9: case 10:                tortoise += 1; break;
    default: assert(0);                                    break;
    }
    return tortoise;
}

int
moveHare(int hare, int move)
{
    switch (move) {
    case 1: case 2:         hare += 0;  break;
    case 3: case 4:         hare += 9;  break;
    case 5:                 hare -= 12; break;
    case 6: case 7: case 8: hare += 1;  break;
    case 9: case 10:        hare -= 2;  break;
    default: assert(0);
    }
    return hare;
}

void
checkPositions(int tortoise, int hare)
{
    const bool isTortoiseWon = tortoise >= RACE - 1;
    const bool isHareWon = hare >= RACE - 1;
    if (isTortoiseWon && isHareWon) {
        std::cout << "It's a tie." << std::endl;
        return;
    }
    if (isTortoiseWon) {
        std::cout << "TORTOISE WINS!!! YAY!!!" << std::endl;
        return;
    }
    if (isHareWon) {
        std::cout << "Hare wins. Yuch." << std::endl;
        return;
    }
}

void
printRoad(int tortoise, int hare)
{
    std::cout << "     ┏";
    for (int i = 0; i <= RACE + 1; ++i) {
        std::cout << "━";
    }
    std::cout << "┓" << std::endl;
    std::cout << "START┃|";
    for (int i = 0; i < RACE; ++i) {
        if (i == 69) {
            std::cout << '|';
        }
        if (tortoise > 69) {
            tortoise = 69;
        }
        if (hare > 69) {
            hare = 69;
        }
        if (tortoise == i && hare == i) {
            switch (i) {
            case 69: std::cout << "O";        break;
            case 68: std::cout << "O| ";      break;
            case 67: std::cout << "OU| ";     break;
            case 66: std::cout << "OUC| ";    break;
            case 65: std::cout << "OUCH| ";   break;
            case 64: std::cout << "OUCH!| ";  break;
            case 63: std::cout << "OUCH!!| "; break;
            default: std::cout << "OUCH!!!";  break;
            }
            i += 6;
            continue;
        }
        if (tortoise == i) {
            std::cout << 'T';
            continue;
        }
        if (hare == i) {
            std::cout << 'H';
            continue;
        }
        std::cout << ' ';
    }
    std::cout << "┃FINISH" << std::endl;
    std::cout << "     ┗";
    for (int i = 0; i <= RACE + 1; ++i) {
        std::cout << "━";
    }
    std::cout << "┛" << std::endl;
}

