#include "headers/BinarySearch.hpp"

#include <iostream>

template <typename T>
int 
binarySearch(std::vector<T>& v, const T& key, const size_t first, const size_t last)
{
    if (last <= first) return -1;
    const size_t mid = (first + last) / 2;
    if (v[mid] < key) return binarySearch(v, key, mid + 1, last);
    if (v[mid] > key) return binarySearch(v, key, first, mid);
    return mid;
}

