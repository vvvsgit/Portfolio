#include "../headers/Stack.hpp"

template <typename T>
Stack<T>::Stack()
    : stack_(List<T>())
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& rhv)
    : stack_(List<T>(rhv.stack_))
{
}

template <typename T>
Stack<T>::~Stack()
{
    stack_.~List<T>();
}

template <typename T>
inline const Stack<T>& 
Stack<T>::operator=(const Stack<T>& rhv)
{
    if (this == &rhv) return *this;
    stack_ = rhv.stack_;
    return *this;
}

template <typename T>
inline bool 
Stack<T>::empty() const
{
    return stack_.empty();
}

template <typename T>
inline typename Stack<T>::size_type 
Stack<T>::size() const
{
    return stack_.size();
}

template <typename T>
inline typename Stack<T>::reference 
Stack<T>::top()
{
    return stack_.front();
}

template <typename T>
inline typename Stack<T>::const_reference 
Stack<T>::top() const
{
    return stack_.front();
}

template <typename T>
inline void 
Stack<T>::push(const_reference rhv)
{
    stack_.push_front(rhv);
}

template <typename T>
inline void 
Stack<T>::pop()
{
    stack_.pop_front();
}

template <typename T>
inline bool 
Stack<T>::operator==(const Stack<T>& rhv) const
{
    return stack_ == rhv.stack_;
}

template <typename T>
inline bool 
Stack<T>::operator<(const Stack<T>& rhv) const
{
    return stack_ < rhv.stack_;
}

