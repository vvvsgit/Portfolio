#include "headers/Array.hpp"

#include <cassert>

template <typename elementType, size_t numberOfElements>
Array<elementType, numberOfElements>::Array()
{
    for (size_t i = 0; i < getSize(); ++i) {
        data_[i] = 0;
    }
}

template <typename elementType, size_t numberOfElements>
size_t 
Array<elementType, numberOfElements>::getSize() const
{
    return numberOfElements;
}

template <typename elementType, size_t numberOfElements>
bool 
Array<elementType, numberOfElements>::operator==(const Array<elementType, numberOfElements>& right) const
{
    if (getSize() != right.getSize()) {
        return false;
    }
    for (int i = 0; i < getSize(); ++i) {
        if (data_[i] != right.data_[i]) {
            return false;
        }
    }
    return true;
}

template <typename elementType, size_t numberOfElements>
bool
Array<elementType, numberOfElements>::operator!=(const Array<elementType, numberOfElements>& right) const
{
    return !(*this == right);
}

template <typename elementType, size_t numberOfElements>
elementType& 
Array<elementType, numberOfElements>::operator[](size_t subscript)
{
    assert(!(subscript < 0 || subscript >= getSize()));
    return data_[subscript];
}

template <typename elementType, size_t numberOfElements>
elementType 
Array<elementType, numberOfElements>::operator[](size_t subscript) const
{
    assert(!(subscript < 0 || subscript >= getSize()));
    return data_[subscript];
}

