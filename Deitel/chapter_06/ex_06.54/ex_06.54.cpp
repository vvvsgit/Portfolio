#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

int rollDice();
void displayWin();
void displayLoss();

int
main()
{
    enum Status { CONTINUE, WON, LOST };
    int myPoint;
    Status gameStatus;
    std::srand(std::time(0));
    int bankBalance = 1000;
    
    int wager = 1;
    std::cout << "\nEnter wager (0 to end): ";
    std::cin >> wager;
    while (wager > 0) { 
        while (wager > bankBalance || wager < 0) {
            std::cout << "Invali wager enterd, enter again. ";
            std::cin >> wager;
        }
        int sumOfDice = rollDice();
        switch (sumOfDice) {
        case 7: case 11: gameStatus = WON; bankBalance += wager;          break;
        case 2: case 3: case 12: gameStatus = LOST; bankBalance -= wager; break;
        default: gameStatus = CONTINUE; myPoint = sumOfDice;
                 std::cout << "Point is " << myPoint << std::endl;        break;
        }

        while (gameStatus == CONTINUE) {
            sumOfDice = rollDice();
            if (sumOfDice == myPoint) {
                bankBalance += wager;
                std::cout << "Player wins" << std::endl;
                gameStatus = WON;
                displayWin();
            } else if (sumOfDice == 7) {
                bankBalance -= wager;
                std::cout << "Player loses" << std::endl;
                gameStatus = LOST;
                displayLoss();
            }
        }
        if (bankBalance == 0) {
            std::cout << "\n\t\t\tSorry. You busted.\n" << std::endl;
           break;
        } 
        std::cout << "Initial bank balance is " << bankBalance << std::endl;
        std::cout << "\nEnter wager (0 to end): ";
        std::cin >> wager;
    }

    std::cout << std::endl;
    return 0;
}

int
rollDice()
{
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int sum = die1 + die2;
    std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << std::endl;
    return sum;
}

void
displayWin()
{
    switch (rand() % 2) {
    case 0: std::cout << "\nYou're up big. Chash in your chips\n" << std::endl; break;
    case 1: std::cout << "\nWinner winner chicken dinner.\n" << std::endl;      break;
    default: assert(0);                                                         break;
    }
}

void
displayLoss()
{
    switch (rand() % 2) {
        case 0: std::cout << "\nOh, you're going for broke, huh?\n" << std::endl; break;
        case 1: std::cout << "\nAw cmon, take a chance!\n" << std::endl;          break;
        default: assert(0);                                                       break;
    }
}

