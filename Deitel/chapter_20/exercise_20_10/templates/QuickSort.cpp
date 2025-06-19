#include "headers/QuickSort.hpp"

#include <iostream>

template <typename T>
void 
quickSort(std::vector<T>& v)
{
    quickSort(v, 0, v.size());
}

template <typename T>
void 
quickSort(std::vector<T>& v, const size_t first, const size_t last)
{
    if (first >= last) return;
    size_t start = first;
    size_t end = last - 1;
    partition(v, start, end);
    quickSort(v, first, end);
    quickSort(v, start + 1, last);
}

template <typename T>
void 
partition(std::vector<T>& v, size_t& start, size_t& end)
{
    while (end != start) {
        for (; end > start; --end) {
            if (v[end] < v[start]) {
                std::swap(v[end], v[start]);
                ++start;
                break;
            }
        }
        for (; start < end; ++start) {
            if (v[start] > v[end]) {
                std::swap(v[start], v[end]);
                --end;
                break;
            }
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

