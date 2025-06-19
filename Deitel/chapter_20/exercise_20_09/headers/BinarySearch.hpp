#ifndef __BINARY_SEARCH_HPP_
#define __BINARY_SEARCH_HPP_

#include <vector>
#include <cstddef>

template <typename T>
int binarySearch(std::vector<T>& v, const T& key, const size_t first, const size_t last);

#include "templates/BinarySearch.cpp"

#endif

