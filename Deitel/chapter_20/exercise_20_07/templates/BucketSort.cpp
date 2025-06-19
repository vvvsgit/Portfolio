#include "headers/BucketSort.hpp"

#include <iostream>

void 
bucketSort(std::vector<int>& v)
{
    std::vector<std::vector<int> > bucket(10);
    const int size = v.size();

    for (int power = 1; !sorted(v); power *= 10) {
        for (int i = 0; i < size; ++i) {
            bucket[v[i] / power % 10].push_back(v[i]); 
        }

        for (int i = 0, row = 0; i < size; ++row) {
            const int column = bucket[row].size();
            for (int j = 0; j < column; ++j) {
                v[i] = bucket[row][j];
                ++i;
            }
            bucket[row].clear();
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

template <typename T>
bool 
sorted(const std::vector<T>& v)
{
    const int size = v.size();
    for (int i = 1; i < size; ++i) {
        if (v[i] < v[i - 1]) return false;
    }
    return true;
}

