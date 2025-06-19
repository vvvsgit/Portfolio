#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <cstddef>

template <typename elementType = int, size_t numberOfElements = 10>
class Array
{
public:
    Array();

    bool operator==(const Array& right) const;
    bool operator!=(const Array& right) const;

    size_t getSize() const;

    elementType& operator[](size_t index);
    elementType operator[](size_t index) const;
private:
    elementType data_[numberOfElements];
};

#include "templates/Array.cpp"

#endif

