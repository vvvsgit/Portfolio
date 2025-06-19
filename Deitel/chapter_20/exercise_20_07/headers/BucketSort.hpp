#ifndef __BUCKET_SORT_HPP_
#define __BUCKET_SORT_HPP_

#include <vector>

void bucketSort(std::vector<int>& v);
template <typename T>
void print(const std::vector<T>& v);
template <typename T>
bool sorted(const std::vector<T>& v);

#include "templates/BucketSort.cpp"

#endif

