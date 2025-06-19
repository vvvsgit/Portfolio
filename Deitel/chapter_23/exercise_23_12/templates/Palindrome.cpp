#include "headers/Palindrome.hpp"

#include <iostream>

template <typename T>
bool
palindrome(const std::vector<T>& v)
{
    for (int first = 0, last = v.size() - 1; first < last; ++first, --last) {
        if (v[first] != v[last]) return false;
    }
    return true;
}

