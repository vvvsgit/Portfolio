#ifndef __SORTED_ARRAY_HPP__
#define __SORTED_ARRAY_HPP__

#include <iostream>

class SortedArray
{
    friend std::istream& operator>>(std::istream& input, SortedArray& array);
    friend std::ostream& operator<<(std::ostream& output, const SortedArray& array);

public:
    SortedArray(const int row = 10);
    SortedArray(const SortedArray& copy);
    ~SortedArray();

    void insert(const int number);

    const SortedArray& operator=(const SortedArray& right);
    bool operator==(const SortedArray& right) const;
    bool operator!=(const SortedArray& right) const;

    int operator()(const int nth);

    int getSize() const;

private:
    void sort();

private:
    int size_;
    int* ptr_;
};

#endif

