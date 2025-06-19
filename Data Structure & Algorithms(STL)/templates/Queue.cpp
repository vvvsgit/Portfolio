#include "../headers/Queue.hpp"

template <typename T>
Queue<T>::Queue()
    : List<T>()
{
}

template <typename T>
Queue<T>::Queue(const Queue<T>& rhv)
    : List<T>(rhv)
{
}

template <typename T>
inline const Queue<T>& 
Queue<T>::operator=(const Queue<T>& rhv)
{
    if (this == &rhv) return *this;
    List<T>::operator=(rhv);
    return *this;
}

template <typename T>
inline bool 
Queue<T>::empty() const
{
    return List<T>::empty();
}

template <typename T>
inline typename Queue<T>::size_type 
Queue<T>::size() const
{
    return List<T>::size();
}

template <typename T>
inline typename Queue<T>::reference 
Queue<T>::front()
{
    return List<T>::front();
}

template <typename T>
inline typename Queue<T>::const_reference 
Queue<T>::front() const
{
    return List<T>::front();
}

template <typename T>
inline typename Queue<T>::reference 
Queue<T>::back()
{
    return List<T>::back();
}

template <typename T>
inline typename Queue<T>::const_reference 
Queue<T>::back() const
{
    return List<T>::back();
}

template <typename T>
inline void 
Queue<T>::push(const_reference value)
{
    List<T>::push_back(value);
}

template <typename T>
inline void 
Queue<T>::pop()
{
    List<T>::pop_front();
}

template <typename T>
inline bool 
Queue<T>::operator==(const Queue<T>& rhv) const
{
    return List<T>::operator==(rhv);
}

template <typename T>
inline bool 
Queue<T>::operator<(const Queue<T>& rhv) const
{
    return List<T>::operator<(rhv);
}

