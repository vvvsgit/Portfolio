#ifndef __QUICK_SORT_HPP_
#define __QUICK_SORT_HPP_

#include <vector>
#include <cstddef>

template <typename T>
void quickSort(std::vector<T>& v);
template <typename T>
void quickSort(std::vector<T>& v, const size_t first, const size_t last);
template <typename T>
void partition(std::vector<T>& v, size_t& first, size_t& last);
template <typename T>
void print(const std::vector<T>& v);

#include "templates/QuickSort.cpp"

#endif

