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
    int times = 10;
    int count = 0;
    int rightCount = 0;
    int answer;
    while (count < times) {
        int a = getRandomNumber();
        int b = getRandomNumber();
        int result = a * b;
        std::cout << "How much is " << a << " times " << b << "? ";
        std::cin >> answer;
        ++count;
        while (answer != result) {
            displayIncorrectResponse();
            if (count == times) { break; }
            std::cin >> answer;
            ++count;
        }
        if (answer == result) {
            displayCorrectResponse();
            ++rightCount;
        }
    }
    std::cout << count << std::endl;
    std::cout << rightCount << std::endl;
    if (75 > rightCount * 100 / count) {
        std::cout << "Please ask your instructor for extra help." << std::endl;
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
    case 0: std::cout << "No. Please try again."  << std::endl; break;
    case 1: std::cout << "Wrong. Try once more."  << std::endl; break;
    case 2: std::cout << "Don't give up!"         << std::endl; break;
    case 3: std::cout << "No. Keep trying."       << std::endl; break;
    default: assert(0);                                         break;
    }
}

