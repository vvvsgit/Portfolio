#include "headers/BubbleSort.hpp"

#include <iostream>

template <typename T>
void 
bubbleSort(std::vector<T>& v)
{
    const int size = v.size();

    for (int i = size; i > 0; --i) {
        for (int j = 1; j < i; ++j) {
            if (v[j] < v[j - 1]) std::swap(v[j], v[j - 1]);
        }
    }
}

template <typename T>
void 
print(const std::vector<T>& v)
{
    typename std::vector<T>::const_iterator first = v.begin();
    typename std::vector<T>::const_iterator last = v.end();
    while (first != last) {
        std::cout << *first << ' ';
        ++first;
    }
    std::cout << std::endl;
}

