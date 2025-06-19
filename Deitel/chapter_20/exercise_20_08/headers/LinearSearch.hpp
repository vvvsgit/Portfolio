#ifndef __LINEAR_SEARCH_HPP_
#define __LINEAR_SEARCH_HPP_

#include <vector>
#include <cstddef>

template <typename T>
int linearSearch(std::vector<T>& v, const T& key, const size_t index = 0);

#include "templates/LinearSearch.cpp"

#endif

