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

void
printArray(const char* array, const int count)
{
    for (int i = 0; i < count - 1; ++i) {
        std::cout << array[i] << " ";
        if (0 == (i + 1) % 5) {
            std::cout << std::endl;
        }
    }
}

