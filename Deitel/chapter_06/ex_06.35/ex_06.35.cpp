#include <iostream>

void multiplication();
int getRandomNumber();

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
            std::cout << "No. Please try again. ";
            std::cin >> answer;
        }
        std::cout << "Very good." << std::endl;
    }
}

int
getRandomNumber()
{
    return rand() % 10;
}

