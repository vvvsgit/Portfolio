#include "headers/LinearSearch.hpp"

template <typename T>
int 
linearSearch(std::vector<T>& v, const T& key, const size_t index)
{
    if (v[index] == key) return index;
    if (index < v.size()) return linearSearch(v, key, index + 1);
    return -1;
}

