#include <iostream>
#include <cassert>
#include <cmath>

void multiplication();
int getRandomNumber(int);
int getQuestion(int, int);
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
    std::cout << "Enter grade-level (1 - 4): ";
    int gradeLevel;
    std::cin >> gradeLevel;
    if (gradeLevel < 1 || gradeLevel > 4) {
        std::cerr << "\nError 1: Wrong grade level." << std::endl;
        ::exit(1);
    }
    gradeLevel = pow(10, gradeLevel);
    std::cout << "Pick the type of problems\n"
              << "      addition       - 1\n"
              << "      subtraction    - 2\n"
              << "      multiplication - 3\n"
              << "      division       - 4\n"
              << "      mix of all     - 5\n"
              << "  picking ";
    int type;
    std::cin >> type;
    if (type < 1 || type > 5) {
        std::cerr << "\nError 2: Wrong type." << std::endl;
        ::exit(2);
    }
    int answer = 0;
    while (true) {
        int result = getQuestion(type, gradeLevel);
        std::cin >> answer;
        if (answer == EOF) { return; }
        while (answer != result) {
            if (answer == EOF) { return; }
            displayIncorrectResponse();
            std::cin >> answer;
        }
        displayCorrectResponse();
    }
}

int
getRandomNumber(int gradeLevel)
{
    return rand() % gradeLevel;
}

int
getQuestion(int type, int gradeLevel)
{
    std::cout << "How much is ";
    int a = getRandomNumber(gradeLevel);
    int b = getRandomNumber(gradeLevel);
    while (b == 0 && type == 4) {
        b = getRandomNumber(gradeLevel);
    }
    if (type == 5) {
        type = rand() % 4 + 1;
    }
    int result;
    switch (type) {
    case 1: result = a + b; std::cout << a << " + " << b << "? "; break;
    case 2: result = a - b; std::cout << a << " - " << b << "? "; break;
    case 3: result = a * b; std::cout << a << " * " << b << "? "; break;
    case 4: result = a / b; std::cout << a << " / " << b << "? "; break;
    default: assert(0);                                           break;
    }
    return result;
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

