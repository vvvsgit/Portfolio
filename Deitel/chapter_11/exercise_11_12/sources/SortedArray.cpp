#include "headers/SortedArray.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <bits/stdc++.h>

SortedArray::SortedArray(const int size)
{
    assert(size >= 0);
    size_ = size;
    ptr_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        ptr_[i] = 0;
    }
}

SortedArray::SortedArray(const SortedArray& copy)
    : size_(copy.size_)
{
    ptr_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        ptr_[i] = copy.ptr_[i];
    }
}

SortedArray::~SortedArray()
{
    if (ptr_ != NULL) {
        delete [] ptr_;
        ptr_ = NULL;
    }
}

void 
SortedArray::insert(const int number)
{
    int* tempPtr = new int[size_ + 1];

    bool notInserted = true;
    for (int i = 0, j = 0; i < size_; ++i, ++j) {
        if (notInserted && number <= ptr_[i]) {
            tempPtr[j] = number;
            --i;
            notInserted = false;
            continue;
        }
        tempPtr[j] = ptr_[i];
    }
    if (notInserted) tempPtr[size_] = number;
    delete [] ptr_;
    ptr_ = tempPtr;
    ++size_;
}

const SortedArray&
SortedArray::operator=(const SortedArray& right)
{
    if (&right == this) return *this;

    if (size_ != right.size_) {
        delete [] ptr_;
        size_ = right.size_;
        ptr_ = new int[size_];
    }
    for (int i = 0; i < size_; i++) {
        ptr_[i] = right.ptr_[i];
    }
    return *this;
}

bool
SortedArray::operator==(const SortedArray& right) const
{
    if (size_ != right.size_) {
        return false;
    }
    for (int i = 0; i < size_; i++) {
        if (ptr_[i] != right.ptr_[i]) {
            return false;
        }
    }
    return true;
}

bool
SortedArray::operator!=(const SortedArray& right) const 
{
    return !(*this == right);
}

int
SortedArray::operator()(const int nth)
{
    assert(nth > 0 && nth <= size_);
    return ptr_[nth - 1];
}

std::istream&
operator>>(std::istream& input, SortedArray& array)
{
    for (int i = 0; i < array.size_; i++) {
        input >> array.ptr_[i];
    }
    array.sort();
    return input;
}

std::ostream&
operator<<(std::ostream& output, const SortedArray& array)
{
    std::cout << "array - ";
    const char fill = output.fill(' ');
    int i;
    for (i = 0; i < array.size_; i++) {
        output << std::setw(4) << array.ptr_[i];
        if ((i + 1) % 10 == 0) {
            output << std::endl;
        }
    }
    output << std::setfill(fill);
    if (i % 10 != 0) {
        output << std::endl;
    }

    return output;
}

void
SortedArray::sort()
{
    std::sort(ptr_, ptr_ + size_);
}

int 
SortedArray::getSize() const
{
    return size_;
}

