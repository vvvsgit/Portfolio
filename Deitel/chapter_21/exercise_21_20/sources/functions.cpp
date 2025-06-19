#include "headers/functions.hpp"

#include <iostream>

void
recursively(const std::list<int>& list)
{
    recursively(list, list.begin());
}

void
recursively(const std::list<int>& list, std::list<int>::const_iterator it)
{
    if (it == list.end()) return;
    const std::list<int>::const_iterator itLocal = it;
    recursively(list, ++it);
    std::cout << *itLocal;
}

