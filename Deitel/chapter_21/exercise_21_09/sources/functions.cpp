#include "headers/functions.hpp"

#include <iostream>

void fillListReversed(const std::list<char>& left, std::list<char>& right)
{
    std::list<char>::const_reverse_iterator it = left.rbegin();
    for (it = left.rbegin(); it != left.rend(); ++it) {
        right.push_back(*it);
    }
}

void
print(const std::list<char>& list)
{
    for (std::list<char>::const_iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << ' ';
    }
}

