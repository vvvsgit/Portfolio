#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

template<typename Type>
void selectionSort(Type* const array, const int size);

template<typename Type>
void swap(Type* const element1Ptr, Type* const element2Ptr);

#include "templates/sort.cpp"

#endif

