#include "headers/printArray.hpp"

#include <iostream>

template<typename T>
void
printArray(const T* array, const int count)
{
    for (int i = 0; i < count; ++i) {
        std::cout << array[i] << " ";
    }
}

template<typename T>
int
printArray(const T* array, const int count,
           const int lowSubscript, const int highSubscript)
{
    if (lowSubscript < 0 || highSubscript < 0 || 
        lowSubscript >= count || highSubscript > count || 
        lowSubscript >= highSubscript) {
        return 0;
    }
    for (int i = lowSubscript; i < highSubscript; ++i) {
        std::cout << array[i] << " ";
    }
    return highSubscript - lowSubscript;
}

