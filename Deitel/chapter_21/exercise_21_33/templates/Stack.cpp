#include "headers/Stack.hpp"

template <typename STACKTYPE>
inline void 
Stack<STACKTYPE>::push(const STACKTYPE& data)
{
    stackList_.insertAtFront(data);
}

template <typename STACKTYPE>
inline bool 
Stack<STACKTYPE>::pop(STACKTYPE& data)
{
    return stackList_.removeFromFront(data);
}

template <typename STACKTYPE>
inline bool 
Stack<STACKTYPE>::isStackEmpty() const
{
    return stackList_.isEmpty();
}

template <typename STACKTYPE>
inline void 
Stack<STACKTYPE>::printStack() const
{
    stackList_.print();
}

