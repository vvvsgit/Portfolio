#include "headers/IntegerSet.hpp"

#include <cassert>
#include <iostream>

IntegerSet::IntegerSet()
{
    for (int i = 0; i < SET_SIZE; ++i) {
        set_[i] = false;
    }
}

IntegerSet::IntegerSet(const bool array[], const int size)
{
    assert(size > 0);
    for (int i = 0; i < SET_SIZE; ++i) {
        if (i < size) {
            set_[i] = array[i];
        } else {
            set_[i] = false;
        }
    }
}

IntegerSet
IntegerSet::unionOfSets(const IntegerSet& right)
{
    IntegerSet result;
    for (int i = 0; i < SET_SIZE; ++i) {
        result.set_[i] = set_[i] || right.set_[i];
    }
    return result;
}

IntegerSet
IntegerSet::intersectionOfSets(const IntegerSet& right)
{
    IntegerSet result;
    for (int i = 0; i < SET_SIZE; ++i) {
        result.set_[i] = set_[i] && right.set_[i];
    }
    return result;
}

void
IntegerSet::insertElement(const int element)
{
    assert(0 >= element && element <= SET_SIZE);
    set_[element] = true;
}

void
IntegerSet::deleteElement(const int element)
{
    assert(0 >= element && element <= SET_SIZE);
    set_[element] = false;
}

void
IntegerSet::printSet()
{
    if(isEmpty()) {
        std::cout << '_' << std::endl;
        return;
    }

    for (int i = 0; i < SET_SIZE; ++i) {
        if (set_[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

bool
IntegerSet::isEqualTo(const IntegerSet& right) const
{
    for (int i = 0; i < SET_SIZE; ++i) {
        if(set_[i] != right.set_[i]) return false;
    }
    return true;
}

bool
IntegerSet::isEmpty() const
{
    for (int i = 0; i < SET_SIZE; ++i) {
        if (set_[i]) return false;
    }
    return true;
}

