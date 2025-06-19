#ifndef __PRINT_ARRAY_HPP__
#define __PRINT_ARRAY_HPP__

template<typename T>
void printArray(const T* array, const int count);

template<typename T>
int printArray(const T* array, const int count, const int lowSubscript, const int highSubscript);

#include "templates/printArray.cpp"

#endif

