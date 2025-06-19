#include <iostream>
#include <cassert>

void multiplication();
int getRandomNumber();
void displayCorrectResponse();
void displayIncorrectResponse();

int
main()
{
    std::cout << std::endl;
    srand(time(0));
    multiplication();
    std::cout << std::endl;
    return 0;
}

void
multiplication()
{
    int answer;
    while (true) {
        int a = getRandomNumber();
        int b = getRandomNumber();
        int result = a * b;
        std::cout << "How much is " << a << " times " << b << "? ";
        std::cin >> answer;
        if (answer < 0) {
            return;
        }
        while (answer != result) {
            displayIncorrectResponse();
            std::cin >> answer;
        }
        displayCorrectResponse();
    }
}

int
getRandomNumber()
{
    return rand() % 10;
}

void
displayCorrectResponse()
{
    switch (rand() % 4) {
    case 0: std::cout << "Very good!"             << std::endl; break;
    case 1: std::cout << "Excellent!"             << std::endl; break;
    case 2: std::cout << "Nice work!"             << std::endl; break;
    case 3: std::cout << "Keep up the good work!" << std::endl; break;
    default: assert(0);                                         break;
    }
}

void
displayIncorrectResponse()
{
    switch (rand() % 4) {
    case 0: std::cout << "No. Please try again." << std::endl; break;
    case 1: std::cout << "Wrong. Try once more." << std::endl; break;
    case 2: std::cout << "Don't give up!"        << std::endl; break;
    case 3: std::cout << "No. Keep trying."      << std::endl; break;
    default: assert(0);                                        break;
    }
}

