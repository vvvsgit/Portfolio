#include "headers/functions.hpp"

#include <iostream>

void
merge(std::list<int>& left, std::list<int>& right, std::list<int>& result)
{
    left.sort();
    right.sort();

    std::list<int>::const_iterator LIt = left.begin();
    std::list<int>::const_iterator RIt = right.begin();
    while (LIt != left.end() && RIt != right.end()) {
        if (*LIt < *RIt) {
            result.push_back(*LIt);
            ++LIt;
            continue;
        }
        result.push_back(*RIt);
        ++RIt;
    }
    while (LIt != left.end()) {
        result.push_back(*LIt);
        ++LIt;
    }
    while (RIt != right.end()) {
        result.push_back(*RIt);
        ++RIt;
    }
}

void
print(const std::list<int>& list)
{
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << ' ';
    }
}

