#include "headers/functions.hpp"

bool
isPalindrome(const std::string& line)
{
    std::string cleanLine;
    for (size_t i = 0; i < line.length(); ++i) {
        if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
            cleanLine += ::tolower(line[i]);
        }
    }

    std::stack<char> stackLine;
    const int size = cleanLine.length();
    int i = 0;
    while (i < size / 2) stackLine.push(cleanLine[i++]);
    if (size % 2 == 1) ++i;
    while (i < size) {
        if (cleanLine[i++] != stackLine.top()) return false;
        stackLine.pop();
    }

    return true;
}

