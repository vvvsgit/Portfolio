#include "headers/functions.hpp"

#include <iostream>

void
printLineReversed(const char* line)
{
    std::stack<char> reverseLine;
    for (int i = 0; line[i] != '\0'; ++i) {
        reverseLine.push(line[i]);
    }

    while (!reverseLine.empty()) {
        std::cout << reverseLine.top();
        reverseLine.pop();
    }
    std::cout << std::endl;
}

