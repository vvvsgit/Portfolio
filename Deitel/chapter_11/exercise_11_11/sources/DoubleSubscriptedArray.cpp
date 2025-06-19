#include "headers/DoubleSubscriptedArray.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

DoubleSubscriptedArray::DoubleSubscriptedArray(const int row, const int column)
{
    assert(row > 0 && column > 0);
    column_ = column;
    row_ = row;
    size_ = row_ * column_;
    ptr_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        ptr_[i] = 0;
    }
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& copy)
    : row_(copy.row_)
    , column_(copy.column_)
    , size_(copy.size_)
{
    ptr_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        ptr_[i] = copy.ptr_[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    if (ptr_ != NULL) {
        delete [] ptr_;
        ptr_ = NULL;
    }
}

int
DoubleSubscriptedArray::getRow() const
{
    return row_;
}

int
DoubleSubscriptedArray::getColumn() const
{
    return column_;
}

int 
DoubleSubscriptedArray::getSize() const
{
    return size_;
}

const DoubleSubscriptedArray&
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& right)
{
    if (&right == this) return *this;

    if (size_ != right.size_) {
        delete [] ptr_;
        size_ = right.size_;
        ptr_ = new int[size_];
    }
    row_ = right.row_;
    column_ = right.column_;
    for (int i = 0; i < size_; i++) {
        ptr_[i] = right.ptr_[i];
    }
    return *this;
}

bool
DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& right) const
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
DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& right) const 
{
    return !(*this == right);
}

int&
DoubleSubscriptedArray::operator()(const int row, const int column)
{
    assert(row >= 0 && column >= 0 && column < column_ && row < row_);
    return ptr_[row * column_ + column];
}

int
DoubleSubscriptedArray::operator()(const int row, const int column) const
{
    assert(row >= 0 && column >= 0 && column < column_ && row < row_);
    return ptr_[row * column_ + column];
}

std::istream&
operator>>(std::istream& input, DoubleSubscriptedArray& array)
{
    for (int i = 0; i < array.size_; i++) {
        input >> array.ptr_[i];
    }
    return input;
}

std::ostream&
operator<<(std::ostream& output, const DoubleSubscriptedArray& array)
{
    const char fill = std::cout.fill(' ');
    int i;
    for (i = 0; i < array.size_; i++) {
        output << std::setw(4) << array.ptr_[i];
        if ((i + 1) % array.column_ == 0) {
            output << std::endl;
        }
    }
    std::cout << std::setfill(fill);
    if (i % array.column_ != 0) {
        output << std::endl;
    }

    return output;
}

