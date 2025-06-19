#include "Analysis.hpp"

#include <iostream>

void
Analysis::processExamResults()
{
    int passes = 0;
    int failures = 0;
    int studentCounter = 0;
    int result;

    while (studentCounter < 10) {
        std::cout << "Enter result (1 = pass, 2 = fail): ";
        std::cin >> result;
        if (1 == result) {
            ++passes;
            ++studentCounter;
        }
        else if (2 == result) {
            ++failures;
            ++studentCounter;
        }
    }

    std::cout << "\nPassed " << passes << "\nFailed " << failures << std::endl;

    if (passes > 8) {
    std::cout << "\nRaise tuition." << std::endl;
    }
}

