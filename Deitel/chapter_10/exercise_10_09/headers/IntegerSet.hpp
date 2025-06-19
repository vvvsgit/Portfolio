#ifndef __INTEGER_SET_HPP__
#define __INTEGER_SET_HPP__

const int SET_SIZE = 101;

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(const bool array[], const int size);
    IntegerSet unionOfSets(const IntegerSet& right);
    IntegerSet intersectionOfSets(const IntegerSet& right);
    void insertElement(const int element);
    void deleteElement(const int element);
    void printSet();
    bool isEqualTo(const IntegerSet& right) const;
    bool isEmpty() const;
private:
    bool set_[SET_SIZE];
};

#endif
