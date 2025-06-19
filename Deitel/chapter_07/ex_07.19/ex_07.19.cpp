#include <iostream>
#include <cstdlib>
#include <ctime>

int rollDice();

int
main()
{
    std::cout << std::endl;

    std::srand(std::time(0));

    const int gamesRoll = 21;
    int winRolls[gamesRoll] = {0};
    int wins = 0;
    int loseRolls[gamesRoll] = {0};
    int loses = 0;
    int totalRolls = 0;

    int timesPlayed = 10000;
    for (int i = 0; i < timesPlayed; ++i) {
        enum Status {CONTINUE, WON, LOST};
        Status gameStatus;

        int sumOfDice = rollDice();
        int myPoint;
        int roll = 1;

        switch (sumOfDice) {
        case 7: case 11: gameStatus = WON; ++wins;                   break;
                 std::cout << "Player wins" << std::endl;
        case 2: case 3: case 12: gameStatus = LOST; ++loses;         break;
                 std::cout << "Player loses" << std::endl;
        default: gameStatus = CONTINUE; myPoint = sumOfDice;
                 std::cout << "\tPoint is " << myPoint << std::endl; break;
        }

        while (gameStatus == CONTINUE) {
            ++roll;
            sumOfDice = rollDice();
            if (sumOfDice == myPoint) {
                gameStatus = WON;
                std::cout << "Player wins" << std::endl;
                ++wins;
            } else if (sumOfDice == 7) {
                gameStatus = LOST;
                std::cout << "Player loses" << std::endl;
                ++loses;
            }
        }
        if (roll <= 20 && gameStatus == WON) {
            ++winRolls[roll - 1];
        } else if (roll > 20) {
            ++winRolls[20];
        } else if (roll <= 20 && gameStatus == LOST) {
            ++loseRolls[roll - 1];
        } else {
            ++loseRolls[20];
        }
        totalRolls += roll;
    }
    for (int i = 0; i < gamesRoll; ++i) {
        std::cout << "Wins at " << i + 1 << " rolls is " << winRolls[i] 
                  << "\tLoses at " << i + 1 << " rolls is " << loseRolls[i] << std::endl;
    }
    std::cout << "Total wins is " << wins << "\tTotal loses is " << loses << std::endl;
    std::cout << "Chances to win is " << static_cast<double>(wins) / timesPlayed << std::endl;
    std::cout << "The avarage length of the game is " << static_cast<double>(totalRolls) / timesPlayed << std::endl;
    std::cout << std::endl;
    return 0;
}

int
rollDice()
{
    int sum = (rand() % 6 + 1) + (rand() % 6 + 1);
    std::cout << "Player rolled " << sum << std::endl;
    return sum;
}

