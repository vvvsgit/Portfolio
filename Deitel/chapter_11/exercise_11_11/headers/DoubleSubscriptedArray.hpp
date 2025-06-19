#ifndef __DOUBLE_SUBSCRIPTED_ARRAY_HPP__
#define __DOUBLE_SUBSCRIPTED_ARRAY_HPP__

#include <iostream>

class DoubleSubscriptedArray
{
    friend std::ostream& operator<<(std::ostream& input, const DoubleSubscriptedArray& array);
    friend std::istream& operator>>(std::istream& output, DoubleSubscriptedArray& array);

public:
    DoubleSubscriptedArray(const int row = 1, const int column = 1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray& copy);
    ~DoubleSubscriptedArray();
    
    const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& right);
    bool operator==(const DoubleSubscriptedArray& right) const;
    bool operator!=(const DoubleSubscriptedArray& right) const;

    int& operator()(const int row, const int column);
    int operator()(const int row, const int column) const;

    int getRow() const;
    int getColumn() const;
    int getSize() const;

private:
    int row_;
    int column_;
    int size_;
    int* ptr_;
};

#endif

