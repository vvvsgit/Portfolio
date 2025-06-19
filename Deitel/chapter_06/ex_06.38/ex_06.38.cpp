#include <iostream>

void guessTheNumber();

int
main()
{
    std::cout << std::endl;
    srand(time(0));
    guessTheNumber();
    std::cout << std::endl;
    return 0;
}

void
guessTheNumber()
{
    char dicision = 'y';
    while (dicision == 'y' || dicision == 'Y') {
        int number = rand() % 1000 + 1;
        std::cout << "\nI have a number between 1 and 1000." << std::endl;
        std::cout << "Can you guess my number?" << std::endl;
        std::cout << "Please type your first guess.";
        int answer;
        do {
            std::cin >> answer;
            if (answer < number) {
                std::cout << "Too low. Try again. ";
            } else if (answer > number) {
                std::cout << "Too high. Try again. ";
            } else if (answer == number) {
                std::cout << "Ecellent! You guessed the number!\n"
                          << "Would You like to play again (y or n)? ";
                std::cin >> dicision;
            }
        } while (answer != number);
    }
}

