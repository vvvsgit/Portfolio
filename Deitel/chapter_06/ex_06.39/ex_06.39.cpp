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
        int guessCount = 0;
        int number = rand() % 1000 + 1;
        std::cout << "\nI have a number between 1 and 1000." << std::endl;
        std::cout << "Can you guess my number?" << std::endl;
        std::cout << "Please type your first guess. ";
        int answer;
        do {
            std::cin >> answer;
            ++guessCount;
            if (answer < number) {
                std::cout << "Too low. Try again. ";
            } else if (answer > number) {
                std::cout << "Too high. Try again. ";
            } else if (answer == number) {
                std::cout << "Ecellent! You guessed the number!" << std::endl;
            }
        } while (answer != number);
        if (guessCount == 10) {
            std::cout << "Ahah! You know the secret!" << std::endl;
        } else if (guessCount < 10) {
            std::cout << "Either you know the secret or you got lucky!" << std::endl;
        } else if (guessCount > 10) {
            std::cout << "You should be able to do better!" << std::endl;
        }
        std::cout << "\nWould You like to play again (y or n)? ";
        std::cin >> dicision;
    }
}

