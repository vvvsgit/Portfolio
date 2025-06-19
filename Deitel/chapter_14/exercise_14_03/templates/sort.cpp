#include "headers/sort.hpp"

template<typename Type>
void
selectionSort(Type* const array, const int size)
{
    for (int i = 0; i < size - 1; ++i) {
        int smallest = i;

        for (int index = i + 1; index < size; ++index) {
            if (array[index] < array[smallest]) {
                smallest = index;
            }
        }
        swap(&array[i], &array[smallest]);
    } 
}

template<typename Type>
void
swap(Type* const element1Ptr, Type* const element2Ptr)
{
    const Type hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

