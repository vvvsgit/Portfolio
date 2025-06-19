#include "headers/functions.hpp"

#include <iostream>

void
fill(std::list<int>& list, const size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        list.push_back(std::rand() % 100);
    }
}

int
sum(const std::list<int>& list)
{
    int result = 0;
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
        result += *it;
    }
    return result;
}

double
average(const std::list<int>& list)
{
    return static_cast<double>(sum(list)) / list.size();
}

void
print(const std::list<int>& list)
{
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << ' ';
    }
}

